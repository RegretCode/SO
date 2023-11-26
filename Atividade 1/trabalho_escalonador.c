// Crie um programa (em C ou Java) para simular o escalonamento de um conjunto de tarefas conhecidas (é de conhecimento o tempo de execução de cada tarefa). 

// O programa deverá receber como parâmetro na linha de execução (usando argc e argv): 

//      a) nome do arquivo que possui informações sobre as tarefas que serão escalonadas (cada linha do arquivo contém o nome da tarefa (identificação única), um espaço e um número inteiro que representa o tempo de execução em segundos);
//      b) um número que indicará a quantidade de processadores. 

// Politica de escalonamento:
//      Utilize o clássico SJF (Shortest Job First) que irá executar as menores tarefas primeiro. Depois implemente o oposto, considerando o maior primeiro.

// Saída:
//      Como saída espera-se um arquivo contendo: id do processador e o nome de cada tarefa com o instante inicial e final (em segundos).

// Exemplo:
//      Forma de executar o programa: ./trabalho_escalonador tarefas.txt 2
//      OBS: No arquivo de entrada: “tarefas.txt” (nome da tarefa e tempo total de execução separados pelo caractere espaço).

// Por exemplo:
//      Arquivo de entrada “tarefas.txt”
// a1 5
// a2 1
// a3 10
// b1 10
// b2 3
// b3 7
// b4 8
// c1 8
// c2 2

// Arquivo de saída(foi solicitado para escalonar em dois processadores e foi utilizado o SJF. Além disso, perceba que o arquivo de saída não possui espaço)
// Processador_1
// a2;0;1
// b2;1;4
// b3;4;11
// c1;11;19
// b1;19;29

// Processador_2
// c2;0;2
// a1;2;7
// b4;7;15
// a3;15;25

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar uma tarefa
typedef struct
{
    char nome[50];
    int tempo_execucao;
} Tarefa;

typedef struct
{
    int id;
    char nome_tarefa[50];
    int inicio;
    int fim;
} Execucao;

// -----------------------Funções-------------------------------------------
int comparar_tempo_execucao(const void *a, const void *b);
void sjf(Tarefa tarefas[], int numero_tarefas, int numero_processadores);
void ljf(Tarefa tarefas[], int numero_tarefas, int numero_processadores);

int main(int argc, char *argv[])
{
    // Verifica se o número de argumentos é correto
    if (argc != 3)
    {
        printf("Uso: %s <arquivo_tarefas> <numero_processadores>\n", argv[0]);
        return 1;
    }

    // Abre o arquivo
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê o número de processadores
    int numero_processadores = atoi(argv[2]);

    // Lê as tarefas do arquivo
    Tarefa tarefa;
    Tarefa tarefas[100]; // Supondo um máximo de 100 tarefas, ajuste conforme necessário
    int numero_tarefas = 0;

    while (fscanf(arquivo, "%s %d", tarefa.nome, &tarefa.tempo_execucao) == 2)
    {
        tarefas[numero_tarefas] = tarefa;
        numero_tarefas++;
    }

    fclose(arquivo);

    // Chamando as funções de escalonamento
    sjf(tarefas, numero_tarefas, numero_processadores);
    printf("\n"); // Adiciona uma linha em branco para separar as saídas
    ljf(tarefas, numero_tarefas, numero_processadores);

    return 0;
}
int comparar_tempo_execucao(const void *a, const void *b)
{
    return ((Tarefa *)a)->tempo_execucao - ((Tarefa *)b)->tempo_execucao;
}

int comparar_tempo_execucao_decrescente(const void *a, const void *b)
{
    return ((Tarefa *)b)->tempo_execucao - ((Tarefa *)a)->tempo_execucao;
}

void sjf(Tarefa tarefas[], int numero_tarefas, int numero_processadores) {
    qsort(tarefas, numero_tarefas, sizeof(Tarefa), comparar_tempo_execucao);

    Execucao execucoes[100];
    int tempo_atual[100] = {0};

    for (int i = 0; i < numero_tarefas; i++) {
        int indice_processador = i % numero_processadores;
        int inicio = tempo_atual[indice_processador];
        int fim = inicio + tarefas[i].tempo_execucao;

        // Corrige a inicialização do campo nome_tarefa
        Execucao execucao = {indice_processador, "", inicio, fim};
        strcpy(execucao.nome_tarefa, tarefas[i].nome);

        execucoes[i] = execucao;

        tempo_atual[indice_processador] = fim;
    }

    // Escreve no arquivo de saída
    FILE *arquivo_saida = fopen("saida_sjf.txt", "w");
    if (arquivo_saida == NULL)
    {
        perror("Erro ao abrir o arquivo de saída");
        exit(1);
    }

    for (int i = 0; i < numero_tarefas; i++)
    {
        fprintf(arquivo_saida, "Processador %d: Tarefa %s - Inicio: %d, Fim: %d\n",
                execucoes[i].id, execucoes[i].nome_tarefa, execucoes[i].inicio, execucoes[i].fim);
    }

    fclose(arquivo_saida);
}
void ljf(Tarefa tarefas[], int numero_tarefas, int numero_processadores) {
    qsort(tarefas, numero_tarefas, sizeof(Tarefa), comparar_tempo_execucao_decrescente);

    Execucao execucoes[100];
    int tempo_atual[100] = {0};

    for (int i = 0; i < numero_tarefas; i++) {
        int indice_processador = i % numero_processadores;
        int inicio = tempo_atual[indice_processador];
        int fim = inicio + tarefas[i].tempo_execucao;

        // Corrige a inicialização do campo nome_tarefa
        Execucao execucao = {indice_processador, "", inicio, fim};
        strcpy(execucao.nome_tarefa, tarefas[i].nome);

        execucoes[i] = execucao;

        tempo_atual[indice_processador] = fim;
    }

    FILE *arquivo_saida = fopen("saida_ljf.txt", "w");
    if (arquivo_saida == NULL)
    {
        perror("Erro ao abrir o arquivo de saída");
        exit(1);
    }

    for (int i = 0; i < numero_tarefas; i++)
    {
        fprintf(arquivo_saida, "Processador %d: Tarefa %s - Inicio: %d, Fim: %d\n",
                execucoes[i].id, execucoes[i].nome_tarefa, execucoes[i].inicio, execucoes[i].fim);
    }

    fclose(arquivo_saida);
}