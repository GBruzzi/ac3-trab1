#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>

/* ============================================================================
 * PROGRAMA B: Travessia Aleatória em Grafo (Baixa Localidade Espacial)
 * * O QUE FAZ: 
 * Cria 1 milhão de "nós" na memória e os conecta em uma ordem totalmente 
 * embaralhada. Depois, o programa percorre esses nós pulando de um para o outro.
 * * OBJETIVO NO SIMULADOR: 
 * Ao dar saltos gigantes e imprevisíveis pela memória (Pointer Chasing), 
 * este programa é um "pesadelo" para a memória Cache. Ele demonstra a 
 * Baixa Localidade, forçando o processador a errar suas previsões o tempo 
 * todo e gerando uma taxa altíssima de Cache Misses.
 * ============================================================================ */

#ifdef SNIPER
#include "sim_api.h"
#else
#define SimRoiStart()
#define SimRoiEnd()
#endif

struct Node {
    int id;
    int next_index; 
    long long padding[4]; 
};

const int NUM_NODES = 1000000; 

int main() {
    std::cout << "Criando grafo com " << NUM_NODES << " nos...\n";
    std::vector<Node> graph(NUM_NODES);
    std::vector<int> indices(NUM_NODES);

    for (int i = 0; i < NUM_NODES; ++i) {
        graph[i].id = i;
        indices[i] = i;
    }

    std::cout << "Embaralhando as conexoes para gerar saltos aleatorios...\n";
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(indices.begin(), indices.end(), g);

    for (int i = 0; i < NUM_NODES - 1; ++i) {
        graph[indices[i]].next_index = indices[i + 1];
    }
    graph[indices[NUM_NODES - 1]].next_index = -1; 

    int current_node = indices[0];
    long long sum = 0;

    std::cout << "Iniciando travessia do grafo. O Sniper comecara a medir agora...\n";

    // --- INÍCIO DA REGIÃO DE INTERESSE (ROI) ---
    SimRoiStart();

    while (current_node != -1) {
        sum += graph[current_node].id;
        current_node = graph[current_node].next_index;
    }

    // --- FIM DA REGIÃO DE INTERESSE (ROI) ---
    SimRoiEnd();

    std::cout << "Concluido! Soma dos IDs (evita otimizacao): " << sum << "\n";

    return 0;
}