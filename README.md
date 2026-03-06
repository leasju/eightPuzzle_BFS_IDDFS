# 8-Puzzle com Inteligência Artificial em C

Projeto desenvolvido para a disciplina **Programação e Estrutura de Dados em C** e **Inteligência Artificial Computacional**, com o objetivo de implementar um simulador do jogo **8-Puzzle**, permitindo que o usuário jogue manualmente ou visualize a solução do problema utilizando algoritmos de busca em Inteligência Artificial.

O sistema foi desenvolvido na linguagem **C** e utiliza estruturas de dados clássicas como **pilhas e filas**, além de implementar algoritmos de busca para resolução automática do puzzle.

---

# 📌 Sobre o Projeto

O **8-Puzzle** é um jogo de raciocínio composto por um tabuleiro **3x3**, contendo oito peças numeradas e um espaço vazio (representado por **X**). O objetivo é organizar as peças na ordem correta realizando movimentos válidos.

Estado final esperado:

| 1 | 2 | 3 |

| 4 | 5 | 6 |

| 7 | 8 | X |


Neste projeto, o programa permite:

- Jogar manualmente tentando resolver o puzzle
- Permitir que a **IA resolva automaticamente o problema**
- Escolher o **nível de dificuldade**
- Visualizar o **caminho da solução encontrado pela IA**
- Verificar o **número de estados explorados durante a busca**

O projeto foi desenvolvido com foco na aplicação prática de conceitos de **estruturas de dados, algoritmos de busca e programação estruturada em C**. :contentReference[oaicite:0]{index=0}

---

# 🎯 Objetivos do Projeto

- Aplicar conceitos de **programação estruturada em C**
- Implementar **estruturas de dados fundamentais**
- Aplicar **algoritmos de busca em Inteligência Artificial**
- Desenvolver raciocínio lógico e análise de algoritmos
- Criar um sistema interativo e funcional em terminal

---

# ⚙️ Funcionalidades

O sistema possui três modos principais de execução:

## 👤 Modo Jogador

O usuário tenta resolver o puzzle manualmente utilizando os seguintes comandos:

| Tecla | Movimento |
|------|-----------|
| W | mover peça para cima |
| S | mover peça para baixo |
| A | mover peça para esquerda |
| D | mover peça para direita |
| 5 | sair do jogo |

O sistema contabiliza o número de movimentos realizados até a solução.

---

## 🤖 Modo IA — Busca em Largura (BFS)

O algoritmo **Breadth-First Search (BFS)** explora os estados do tabuleiro nível por nível utilizando uma **fila (FIFO)**.

Características:

- Garante encontrar a **solução ótima**
- Explora todos os estados possíveis de um nível antes de avançar
- Utiliza estrutura de **fila**

Ao encontrar a solução, o programa exibe:

- caminho completo até a solução
- número de movimentos
- profundidade da solução
- quantidade de estados explorados

---

## 🤖 Modo IA — Busca em Profundidade Limitada Iterativa (IDDFS)

O algoritmo **Iterative Deepening Depth First Search (IDDFS)** combina características de busca em profundidade e busca em largura.

Características:

- Utiliza **pilha (LIFO)**
- Limita a profundidade da busca
- Aumenta progressivamente o limite até encontrar solução

Essa estratégia permite **controle de memória melhor que BFS em alguns cenários**.

---

# 🎮 Sistema de Dificuldade

O jogo possui quatro níveis de dificuldade que determinam a quantidade de embaralhamento inicial do tabuleiro.

| Nível | Movimentos de embaralhamento |
|------|------------------------------|
| Fácil | 10 |
| Médio | 15 |
| Difícil | 30 |
| Muito Difícil | 31 |

Quanto maior o número de movimentos iniciais, mais complexo se torna o puzzle.

---

# 🧠 Estrutura de Dados Utilizadas

O projeto utiliza duas estruturas principais:

## Fila

Utilizada na implementação da **Busca em Largura (BFS)**.

Comportamento:
FIFO (First In First Out)

Arquivo utilizado:
fila.h


---

## Pilha

Utilizada na implementação da **Busca em Profundidade Limitada Iterativa (IDDFS)**.

Comportamento:
LIFO (Last In First Out)

Arquivo utilizado:
pilha.h


---

# 🧩 Estrutura do Projeto
8-puzzle/
│

├── 8puzzle.c # Arquivo principal do programa

├── fila.h # Implementação da estrutura de dados Fila

├── pilha.h # Implementação da estrutura de dados Pilha

└── README.md


---

# 🧪 Algoritmos Implementados

| Algoritmo | Tipo |
|------|------|
| BFS | Busca em largura |
| IDDFS | Busca em profundidade limitada iterativa |

Esses algoritmos permitem resolver automaticamente o puzzle a partir de qualquer configuração inicial válida.

---

# ▶️ Como Compilar e Executar

### Compilação

Utilize o **gcc** para compilar o programa:

gcc 8puzzle.c -o puzzle


### Execução
./puzzle


O programa abrirá um menu permitindo escolher o modo de jogo.

---

# 📊 Saída do Programa

Durante a execução, o sistema pode mostrar:

- estado atual do tabuleiro
- número de movimentos
- caminho da solução
- profundidade da solução
- estados explorados

Isso permite visualizar claramente **como os algoritmos de busca encontram a solução**.

---

# 📚 Conceitos Aplicados

Durante o desenvolvimento do projeto foram aplicados diversos conceitos importantes de ciência da computação:

- Matrizes
- Estruturas de dados
- Pilhas
- Filas
- Alocação dinâmica de memória
- Busca em grafos
- Inteligência Artificial
- Controle de estados
- Evitar estados repetidos

---

# 🎓 Contexto Acadêmico

Este projeto foi desenvolvido como parte das disciplinas:

- **Programação e Estrutura de Dados**
- **Inteligência Artificial Computacional**

no curso de **Ciência de Dados e Inteligência Artificial** da **Pontifícia Universidade Católica de Campinas (PUC-Campinas)**. :contentReference[oaicite:1]{index=1}

---

# 👩‍💻 Integrantes

- Bárbara Lima  
- Emily Delgado  
- [Isabel Baungartner](https://www.linkedin.com/in/isabel-baungartner-78a573296/)
- [Julia Leandro](www.linkedin.com/in/juliasleandro)  
