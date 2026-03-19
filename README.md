# 🧠 Análise de Desempenho de Cache — Arquitetura de Computadores

> Trabalho prático de análise do impacto da hierarquia de memória cache no desempenho de diferentes tipos de workloads.

---

## 📋 Descrição

Este projeto compara o comportamento da memória cache em dois programas com padrões de acesso à memória opostos, variando parâmetros da cache (tamanho e associatividade) e medindo o impacto no desempenho. O objetivo é observar como a localidade de referência influencia a taxa de cache hits/misses.

---

## 🖥️ Programas Analisados

| | Programa A | Programa B |
|---|---|---|
| **Tipo** | Alta Localidade | Baixa Localidade |
| **Implementação** | Multiplicação de Matrizes | Busca em Árvore Binária / Grafo |
| **Padrão de acesso** | Sequencial, dados vizinhos | Aleatório, saltos na memória |
| **Comportamento esperado** | Poucos cache misses | Muitos cache misses |

---

## ⚙️ Configuração da Máquina Base (Simulada)

```yaml
núcleos:    1
cache_L1:   32 KB
cache_L2:   256 KB
política:   LRU (Least Recently Used)
simulador:  gem5  # ou substitua pelo utilizado pelo grupo
```

---

## 🧪 Divisão dos Testes

### Teste 1 — Variação do Tamanho da Cache L1

| Configuração | 16 KB | 32 KB | 64 KB | 128 KB |
|---|---|---|---|---|
| Programa A | ✅ | ✅ | ✅ | ✅ |
| Programa B | ✅ | ✅ | ✅ | ✅ |

### Teste 2 — Variação da Associatividade da Cache

| Configuração | Direct-Mapped | 2-way | 4-way | 8-way |
|---|---|---|---|---|
| Programa A | ✅ | ✅ | ✅ | ✅ |
| Programa B | ✅ | ✅ | ✅ | ✅ |

---

## 👥 Divisão de Tarefas

| Responsabilidade |
|---|
| Teste 1 no Programa A — varia tamanho da Cache L1 |
| Teste 1 no Programa B — varia tamanho da Cache L1 |
| Teste 2 no Programa A — varia associatividade da Cache |
| Teste 2 no Programa B — varia associatividade da Cache |
| Documentação, análise comparativa e escrita do artigo |

---

## 📊 Métricas Coletadas

- Taxa de **cache miss** (L1 e L2)
- Tempo de execução (ciclos / segundos)
- Número de acessos à memória principal
- Speedup relativo à configuração base

---

## 📄 Artigo

O artigo completo está disponível na pasta [`/artigo`](./artigo/) e segue as normas da disciplina de **Arquitetura de Computadores**.

---

## 👨‍💻 Integrantes

| Nome | GitHub | 
|---|---|
| Ana Clara Duarte | @anaclaraduarte0011 | 
| Gabriel Bruzzi | @gbruzzi | 
| Júlia  | @usuario3 |
| Kenia Teixeira  | @usuario4 | 
| Júlia Sebatstião  | @usuario5 | 

---

## 🏫 Informações da Disciplina

```
Disciplina:  Arquitetura de Computadores
Curso:       Ciência da Computação
Instituição: PUC MINAS
Semestre:    [Ex: 2026/1]
Professor:   Matheus Alcântara
```
