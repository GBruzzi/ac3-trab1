#include <iostream>
#include <vector>

/* ============================================================================
 * PROGRAMA A: Multiplicação de Matrizes (Alta Localidade Espacial)
 * * O QUE FAZ: 
 * Cria três matrizes gigantes (1024x1024) e realiza a multiplicação entre elas.
 * * OBJETIVO NO SIMULADOR: 
 * Como as matrizes são lidas de forma sequencial (linha por linha), este 
 * programa é o "cenário ideal" para a memória Cache. Ele demonstra a 
 * Alta Localidade Espacial, gerando poucos Cache Misses, pois o processador 
 * consegue prever e trazer os próximos dados da RAM antes mesmo de precisar deles.
 * ============================================================================ */

// Configuração para o Sniper Simulator (Marcadores de Região de Interesse)
#ifdef SNIPER
#include "sim_api.h"
#else
#define SimRoiStart()
#define SimRoiEnd()
#endif


const int N = 1024; 

int main() {
    std::cout << "Alocando matrizes (" << N << "x" << N << ")...\n";
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 2));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    std::cout << "Iniciando multiplicacao. O Sniper comecara a medir agora...\n";

    // --- INÍCIO DA REGIÃO DE INTERESSE (ROI) ---
    SimRoiStart(); 

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }

    // --- FIM DA REGIÃO DE INTERESSE (ROI) ---
    SimRoiEnd();

    std::cout << "Concluido! Amostra do resultado: " << C[0][0] << "\n";
    
    return 0;
}