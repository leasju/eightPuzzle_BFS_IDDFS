/*
TRABALHO - 8 PUZZLE COM BUSCA
DISCIPLINA: IA COMPUTACIONAL + PROGRAMAÇÃO E ESTRUTURA DE DADOS EM C
PROFESSOR: FERNANDO E LÚCIA
INTEGRANTES:
- BÁRBARA LIMA
- ISABEL BAUNGARTNER
- EMILY DELGADO
- JULIA LEANDRO
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Módulos
#include "fila.h"
#include "pilha.h"

// ---------------------------------------------------------------------
// ------------------------------ FUNÇÕES ------------------------------
// ---------------------------------------------------------------------

// ----- EMBARALHAR TABULEIRO

void embaralhar(int tab[][3], int qtd_mov)
{
    int linha = 2, col = 2; // Posição inicial do 0 (X)
    int opcoes[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    srand(time(NULL));

    for (int i = 0; i < qtd_mov; i++) // Repete a qtde de movimentos desejada
    {
        int nLinha, nCol, mov, aux;
        do {
            mov = rand()%4; // Escolhe um movimento aleatório
            nLinha = linha + opcoes[mov][0]; // Nova linha
            nCol = col + opcoes[mov][1]; // Nova coluna
        } while (nLinha < 0 || nLinha > 2 || nCol < 0 || nCol > 2); // Impede de sair do tabuleiro (ultrapassar limites da matriz)

        aux = tab[linha][col]; // Guarda valor atual do "x" em "aux"
        tab[linha][col] = tab[nLinha][nCol]; // Move o num para a posição do "X"
        tab[nLinha][nCol] = aux; // Move o "X" para a nova posição

        // Atualiza a posição atual do "X" para a próxima iteração do laço
        linha = nLinha;
        col = nCol;
    }
}

// ----- IMPRIME O TABULEIRO

void mostrar_tab(int T[3][3]) { // Linhas
    for (int i = 0; i < 3; i++) // Colunas
    {
        printf("\t");
        for (int j = 0; j < 3; j++) {
            if (T[i][j] == 0){
                printf("| X |"); // Se a posição for 0, imprime o X
            } else{
                printf("| %d |", T[i][j]);
            }
        }
        printf("\n");
    }
}

// ----- REINICIA O TABULEIRO
void reiniciar_tabuleiro(int T[3][3]) {
    int tabuleiro_inicial[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            T[i][j] = tabuleiro_inicial[i][j];
        }
    }
}

// ----- BOAS VINDAS

void boas_vindas()
{
    system("cls");

    printf("\n==========================================\n\n");
    printf("         BEM-VINDO AO JOGO 8-PUZZLE!        \n");
    printf("\n==========================================\n\nMonte o tabuleiro na ordem correta:\n\n");
    printf("\t| 1 || 2 || 3 |\n");
    printf("\t| 4 || 5 || 6 |\n");
    printf("\t| 7 || 8 || X |\n");
    printf("\nBoa sorte!\n");
    printf("\nPressione ENTER para continuar...\n");
    getchar();

    system("cls");
}

// ----- LER MOVIMENTO
/*
w = cima
a = esquerdo
s = baixo
d = direito
*/

int ler(){

    char op;

    printf("\n\n\n MOVIMENTOS POSSIVEIS:");
    printf("\n\n| mover para CIMA = w; \n| mover para BAIXO = s;\n| mover para ESQUERDA = a;\n| mover para DIREITA = d;\n\n| fechar programa = 5.\n\nDigite o movimento que deseja realizar: ");
    fflush(stdin);
    op = getchar();
    op = tolower(op);

    return op;

}

// ----- APLICAR MOVIMENTO

int fs(int T[3][3], int opcao, int *linhaX, int *colX)
{
    int linha = *linhaX;
    int col = *colX;

    if (opcao == 'w' && linha > 0) // Cima
    {
        T[linha][col] = T[linha - 1][col];
        T[linha - 1][col] = 0;
        *linhaX = linha - 1;
        return 1;
    }
    else if (opcao == 's' && linha < 2) // Baixo
    {
        T[linha][col] = T[linha + 1][col];
        T[linha + 1][col] = 0;
        *linhaX = linha +1;
        return 1;
    }
    else if (opcao == 'a' && col > 0) // Esquerda
    {
        T[linha][col] = T[linha][col - 1];
        T[linha][col - 1] = 0;
        *colX = col - 1;
        return 1;
    }
    else if (opcao == 'd' && col < 2) // Direita
    {
        T[linha][col] = T[linha][col + 1]; // Pega um num que esta a direita do X e move ele para onde estava o X
        T[linha][col + 1] = 0; // Coloca o X na nova posição a direita
        *colX = col + 1;
        return 1;
    }
    else if (opcao == '5')
    {
        system("cls");
        printf("\t\t\t\t\t---------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t| VOCE ESTA SAINDO DO PROGRAMA! |\n");
        printf("\t\t\t\t\t---------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
        exit(1);
    }
    else
    {
        system("cls");
        printf("\n\n\t|OPCAO INVALIDA!|");
    }
}

// ----- ENCONTRAR O X(0)

void encontraX(int tab[3][3], int *linha, int *col) {
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (tab[i][j] == 0) {
                *linha = i;
                *col = j;
                return;
            }
        }
    }
}


// ----- ESCOLHA DO NÍVEL DE DIFICULDADE DO JOGO

int opND(int op)
{
    do
    {
        printf("Selecione o nivel de dificuldade: ");
        printf("\n\n\t| 1 - FACIL");
        printf("\n\t| 2 - MEDIO");
        printf("\n\t| 3 - DIFICIL");
        printf("\n\t| 4 - MUITO DIFICIL");
        printf("\n\t| 0 - VOLTAR AO MENU PRINCIPAL");

        printf("\n\nOpcao: ");

        scanf("%d", &op);

        if (op < 0 || op > 4)
       {
           system("cls");
           printf("\n\n\t|OPCAO INVALIDA!|");
           printf("\n\n\nPressione ENTER para continuar...\n");
           getchar(); getchar();
           system("cls");
       }

    } while (op < 0 || op > 4);

    return op;
}

// ----- APLICAR NÍVEL DE DIFICULDADE

void aplicarNivel(int T[3][3], int opDif)
{
    switch (opDif)
    {
        case 1:
            printf("Facil"); embaralhar(T, 10);
            break;
        case 2:
            printf("Medio"); embaralhar(T, 15);
            break;
        case 3:
            printf("Dificil"); embaralhar(T, 30);
            break;
        case 4:
            printf("Muito dificil"); embaralhar(T, 31);
            break;
    }
}

// ----- CONFIGURAÇÕES DOS NÍVEIS DE DIFICULDADE

typedef struct {
    int movimentos_embaralhar;
    int movimentos_ideais;
    char nome[20];
} Nivel;

Nivel niveis[] = {
    {10, 10, "Fácil"},
    {15, 15, "Médio"},
    {30, 30, "Difícil"},
    {31, 31, "Muito Difícil"}
};

// ----- ESCOLHA DE MODO DE JOGO: JOGADOR OU IA

int opIAus (int opC)
{
    do
    {
        printf("Escolha a opcao desejada");
        printf("\n\n\t| 1 - MODO JOGADOR\n\tResolver o puzzle manualmente");
        printf("\n\n\t| 2 - MODO IA - BUSCA EM LARGURA\n\tResolver pela IA usando Busca em Largura (BFS)");
        printf("\n\n\t| 3 - MODO IA - BUSCA EM PROFUNDIDADE LIMITADA ITERATIVA\n\tResolver pela IA usando IDDFS");
        printf("\n\n\t| 0 - FECHAR O PROGRAMA");

        printf("\n\nOpcao: ");
        scanf("%d", &opC);

        if (opC < 0 || opC > 3)
        {
           system("cls");
           printf("\n\n\t|OPCAO INVALIDA!|");
           printf("\n\n\nPressione ENTER para continuar...\n");
           getchar(); getchar();
           system("cls");
        }

    } while (opC < 0 || opC > 3);

    return opC;
}

// ----- ESCOLHA SE DESEJA SAIR OU CONTINUAR NO PROGRAMA APÓS O FIM DO JOGO
int voltarSair ()
{
    int voltarF;

    system("cls");
    printf("\n\nEscolha a opcao desejada");
    printf("\n\n  | 0 - Voltar para o menu inicial");
    printf("\n\n  | 5 - Encerrar programa");
    printf("\n\nOpcao: ");
    scanf("%d", &voltarF);

    return voltarF;

}

// ---------------------------------------------------------------------
// ----------- PARTES ADICIONAIS PARA AS BUSCAS FUNCIONAREM ------------
// ---------------------------------------------------------------------

// ----- struct: ESTADO DO TABULEIRO

typedef struct estado{
    int tab[3][3]; // Estado do tabuleiro
    int profundidade; // Nível da árvore
    int pai; // Índice do estado do pai
} Estado;

// ----- COMPARA OS DOIS ESTADOS DO TABULEIRO: atual e final

int compara(int a[3][3], int b[3][3])
{
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (a[i][j] != b[i][j]){
                return 0; // Não resolvido
            }
        }
    }
    return 1; // Resolvido
}

// ----- SOLUÇÃO

int resolvido(int tab[3][3])
{
    int solucao[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    return compara(tab, solucao);
}

// ----- COPIA O TAB ATUAL PARA O NOVO ESTADO (Para não alterar o original)

void copiar(int tabAtual[3][3], int tabFinal[3][3])
{
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            tabFinal[i][j] = tabAtual[i][j];
        }
    }
}

// ----- MOSTRA O CAMINHO DA SOLUÇÃO

void mostrarCaminhoSol(Estado estados[], int indiceFinal, int profundidade, int explorados)
{
    int caminho[10000];
    int tam = 0;
    int iAtual = indiceFinal; // Índice do estado atual

    while (iAtual != -1)
    {
        caminho[tam++] = iAtual;
        iAtual = estados[iAtual].pai;
    }

    // -- Exibe apenas os movimentos relevantes
    printf("\n\nCaminho da solucao encontrado (%d movimentos):\n", tam - 1);
    for (int i = tam - 1; i >= 0; i--)
    {
        printf("\nMovimento #%d:\n\n", tam - 1 - i);
        mostrar_tab(estados[caminho[i]].tab);
    }

    printf("\nSolucao encontrada em profundidade %d!\n", profundidade);
    printf("Estados explorados: %d\n", explorados);

    printf("\nPressione ENTER para continuar...\n");
    getchar();getchar();
}

// ----------------
// ---- BUSCAS ----
// ----------------

// ------------------ BUSCA BFS ------------------

int bfs_ia(int inicial[3][3])
{
    // Definindo o objetivo (estado final desejado)
    int solucao[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    int linha, col;

    Fila* f = CriaFila();

    // Vetor que guarda dinâmico de estados
    Estado *estados = malloc(100000 * sizeof(Estado));
    if (estados == NULL) {
        printf("\n[ERRO] Falha ao alocar memória para os estados.\n");
        return 0;
    }

    // inicio: Índice do primeiro estado
    // fim: Quantidade de estados existentes até o momento
    // cont_explorado: Contador de estados visitados

    int inicio = 0, fim = 0, cont_explorado = 0;

    // -- Estado inicial
    copiar(inicial, estados[0].tab);
    estados[0].profundidade = 0;
    estados[0].pai = -1; // A raiz não possui um pai
    InsereFila(f, 0); // Guarda o índice 0 na fila


    while (!VaziaFila(f))
    {
        int indice = RetiraFila(f); // Índice do estado atual

        if (indice < 0 || indice > fim) {
            printf("\n[ERRO] Índice inválido removido da fila (%d). Encerrando busca.\n", indice);
            liberaFila(f);
            return 0;
        }

        Estado atual = estados[indice]; // Cópia do "atual" para facilitar o uso
        cont_explorado++;

        // -- Verifica solução
        if (compara(atual.tab, solucao))
        {
            mostrarCaminhoSol(estados, indice, atual.profundidade, cont_explorado);
            liberaFila(f);
            free(estados);
            return 1;
        }

        // -- Encontrando o "x" no tabuleiro
        encontraX(atual.tab, &linha, &col);

        int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // Movimentos possíveis

        // -- Percorrendo as 4 direções possíveis
        for (int m=0; m<4; m++)
        {
            int nl = linha + mov[m][0];
            int nc = col + mov[m][1];

            // -- Verificando se o movimento é válido
            if (nl>=0 && nl<3 && nc>=0 && nc<3)
            {
                fim++; // Cria um novo estado filho

                // -- Verificando se ultrapassou o número "seguro" de estados
                if (fim >= 99999)
                {
                    printf("\n[ERRO] Limite de estados atingido (%d). Encerrando busca para evitar erros.\n", fim);
                    liberaFila(f);
                    free(estados);
                    return 0;
                }

                copiar(atual.tab, estados[fim].tab); // Copiando o tab atual para o novo estado

                // -- Troca o "x" com o algarismo adjacente
                int temp = estados[fim].tab[linha][col];
                estados[fim].tab[linha][col] = estados[fim].tab[nl][nc];
                estados[fim].tab[nl][nc] = temp;

                // -- Incrementando
                estados[fim].profundidade = atual.profundidade + 1;
                estados[fim].pai = indice;


                // ---- Evita estados repetidos
                // Percorre todos os estados já criados para ver se o novo tabuleiro (estado) já existia
                int repetido = 0;
                for (int k = 0; k < fim; k++)
                {
                    if (compara(estados[k].tab, estados[fim].tab))
                    {
                        repetido = 1; // 1 = Existe
                        break;
                    }
                }

                // Se for novo, adiciona à fila
                if (!repetido)
                {
                    InsereFila(f, fim);

                } else {
                    fim--; // Desfaz o incremento pra não ultrapassar o limite
                }
            }
        }
    }

    liberaFila(f);

    printf("\nBusca finalizada: nenhuma solução encontrada.\n");
    printf("\nPressione ENTER para encerrar...\n");
    getchar(); getchar(); // Pausa até o usuário apertar ENTER

    free(estados);

    return 0;
}

// ------------------ BUSCA IDDFS ------------------

int iddfs_ia(int inicial[3][3])
{
    // Definindo o objetivo (estado final desejado)
    int solucao[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
    int linha, col;

    Pilha* p = CriaPilha();
    Estado estados[10000]; // Armazena todos os estados gerados

    int cont_explorado = 0; // Contador de estados (nós) visitados
    int maxProf = 0; // Máximo de profundidade
    int fim = 0; // Índice do último estado criado

    // Estado inicial
    copiar(inicial, estados[0].tab);
    estados[0].profundidade = 0;
    estados[0].pai = -1; // A raiz não possui um pai

    while (maxProf < 50) // Aumentando o limite progressivamente
    {

        liberaPilha(p);
        p = CriaPilha();
        fim = 0; // Reiniciando o contador a cada nova profundidade

        push(p, 0); // Adiciona o estado inicial

        while (!vaziaPilha(p))
        {
            int indice = pop(p);
            Estado atual = estados[indice];
            cont_explorado++;

            // -- Verifica solução
            if (compara(atual.tab, solucao)) {

                mostrarCaminhoSol(estados, indice, atual.profundidade, cont_explorado);

                liberaPilha(p);
                return 1;
            }


            // -- Gera novos estados apenas se não atingiu o limite
            if (atual.profundidade < maxProf) {

                encontraX(atual.tab, &linha, &col);

                int mov[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // Movimentos possíveis


                // -- Percorrendo as 4 direções possíveis
                for (int m=0; m<4; m++) {
                    int nl = linha + mov[m][0];
                    int nc = col + mov[m][1];


                    // -- Verificando se o movimento é válido
                    if (nl>=0 && nl<3 && nc>=0 && nc<3) {

                        fim++; // Cria um novo estado filho
                        copiar(atual.tab, estados[fim].tab); // Copiando o tab atual para o novo estado

                        // -- Troca o "x" com o algarismo adjacente
                        int temp = estados[fim].tab[linha][col];
                        estados[fim].tab[linha][col] = estados[fim].tab[nl][nc];
                        estados[fim].tab[nl][nc] = temp;

                        // -- Incrementando
                        estados[fim].profundidade = atual.profundidade + 1;
                        estados[fim].pai = indice;

                        // ---- Evita estados repetidos
                        // Percorre todos os estados já criados para ver se o novo tabuleiro (estado) já existia
                        int repetido = 0;
                        for (int k = 0; k < fim; k++) {
                            if (compara(estados[k].tab, estados[fim].tab)) {
                                repetido = 1;
                                break;
                            }
                        }

                        // Se for novo, adiciona à pilha
                        if (!repetido) {
                            push(p, fim);
                        } else {
                            fim--; // Desfaz o incremento pra não ultrapassar o limite
                        }
                    }
                }
            }
        }

        maxProf++; // Aumentando o limite e tentando novamente
    }

    liberaPilha(p);

    printf("\nBusca finalizada: nenhuma solução encontrada até o limite máximo de profundidade.\n");
    printf("\nPressione ENTER para encerrar...\n");
    getchar(); getchar(); // Pausa até o usuário apertar ENTER

    return 0;
}


// ---------------------------------------------------------------------
// -------------------------------- MAIN -------------------------------
// ---------------------------------------------------------------------

int main ()
{
    int T[3][3] = {{1,2,3},{4,5,6},{7,8,0}}; // Definindo a matriz do tabuleiro
    int opcao, opDif, opIA, opSair;
    int cont_mov = 0;
    int mov_valido = 0;
    int linhaX = 2, colX = 2; // Posição inicial do 0 (X)
    int sairPrograma=0;

    while(!sairPrograma)
    {
        // reiniciar tabuleiro
        cont_mov = 0;
        linhaX = 2;
        colX = 2;
        reiniciar_tabuleiro(T);


        boas_vindas();

        opIA = opIAus(opIA);

        if (opIA == 0) {
            system("cls");
            printf("\t\t\t\t\t---------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t| VOCE ESTA SAINDO DO PROGRAMA! |\n");
            printf("\t\t\t\t\t---------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ");
            exit(1);
        }

        system("cls");

        // --- ESCOLHA DO NÍVEL DE DIFICULDADE
        opDif = opND(opDif);

        if (opDif == 0)
        {
            system("cls");
            continue; // Volta ao menu principal
        }
        system("cls");



        // --- ESCOLHA DE MODO: USUÁRIO OU IA
        switch (opIA)
        {
            // ---------------------- USUÁRIO (Jogador) ----------------------
            case 1:
                printf("\nOpcao escolhida: Resolver manualmente");
                printf("\nNivel de dificuldade: ");
                aplicarNivel(T, opDif);

                // -- Posição X
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (T[i][j] == 0)
                        {
                            linhaX = i;
                            colX = j;
                        }
                    }
                }

                // -- Exibe num necessário de movimentos para chegar à solução
                printf("\nEste puzzle pode ser resolvido com ate ");
                if (opDif == 1){
                    printf("10 movimentos.\n");
                }
                if (opDif == 2){
                    printf("15 movimentos.\n");
                }
                if (opDif == 3){
                    printf("30 movimentos.\n");
                }
                if (opDif == 4){
                    printf("31 movimentos.\n");
                }

                printf("\n\nDeseja iniciar o jogo? Pressione ENTER para comecar...");
                getchar(); getchar();
                system("cls");


                // -- Início do jogo (Usuário)
                int saida = 1;
                do
                {
                    printf("\tOBJETIVO FINAL:\n\n");
                    printf("\t| 1 || 2 || 3 |\n");
                    printf("\t| 4 || 5 || 6 |\n");
                    printf("\t| 7 || 8 || X |\n");

                    printf("\n\n\tESTADO ATUAL:\n\n");
                    mostrar_tab(T);

                    printf("\n\nMovimentos realizados: %d", cont_mov);

                    if (resolvido(T))
                    {
                        printf("\nParabens! Voce resolveu o 8-puzzle!\n");
                        printf("Numero de movimentos realizados: %d\n", cont_mov);
                        break;
                    }

                    opcao = ler();

                    if (opcao == '5')
                    {
                        printf("Jogo encerrado.\n");
                        saida = 0;
                    }


                    // -- Aplica o movimento e incrementa se for válido
                    mov_valido = fs(T, opcao, &linhaX, &colX);
                    if (mov_valido) {
                        cont_mov++;
                    }

                    system("cls");

                } while (saida);
                system("pause");
                break;

           // ------------------------- BUSCA BFS -------------------------
            case 2:
                printf("\nOpcao escolhida: IA - Resolver por BFS");
                printf("\nNivel de dificuldade: ");
                aplicarNivel(T, opDif);

                // -- Inicio do jogo (Busca)
                printf("\n\nDeseja iniciar a busca? Pressione ENTER para continuar...");
                getchar(); getchar();
                system("cls");

                printf("IA iniciando a busca por BFS...\n\n");

                mostrar_tab(T);
                bfs_ia(T);
                break;

            // ----------------------- BUSCA IDDFS ------------------------
            case 3:
                printf("\nOpcao escolhida: IA - Resolver por IDDFS");
                printf("\nNivel de dificuldade: ");
                aplicarNivel(T, opDif);

                // -- Inicio do jogo (Busca)
                printf("\n\nDeseja iniciar a busca? Pressione ENTER para continuar...");
                getchar(); getchar();
                system("cls");

                printf("IA iniciando a busca por IDDFS...\n\n");

                mostrar_tab(T);
                iddfs_ia(T);
                break;
        }

        // Pergunta se o usuário quer jogar novamente ou sair

        do {
            opSair = voltarSair();

            if (opSair==0)
            {
               system("cls");
                    break;
            }
            else if (opSair==5)
            {
               system("cls");
               sairPrograma=1;
            }
            else
            {
               system("cls");
               printf("\n\n\t|OPCAO INVALIDA!|");
               printf("\n\n\nPressione ENTER para continuar...\n");
               getchar(); getchar();
               system("cls");
            }
        } while(opSair!= 0 && opSair!=5);
    }

    return 0;
}
