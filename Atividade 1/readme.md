# Projeto de Escalonamento de Tarefas

Este projeto consiste em um programa desenvolvido em C ou Java para simular o escalonamento de um conjunto de tarefas conhecidas. O escalonamento é realizado considerando o tempo de execução de cada tarefa e a quantidade de processadores disponíveis. O programa utiliza a política de escalonamento clássica SJF (Shortest Job First), que executa as menores tarefas primeiro. Além disso, foi implementada uma versão oposta, que considera as maiores tarefas primeiro. 

## Como Compilar e Executar o Programa (GCC)

### Compilação em C

Para compilar o programa em C utilizando o GCC, abra um terminal e navegue até o diretório do projeto. Execute o seguinte comando:

```bash
gcc -o trabalho_escalonador trabalho_escalonador.c -lm
```

## Como Executar o Programa

O programa pode ser executado a partir da linha de comando, utilizando os parâmetros `nome_do_arquivo` e `quantidade_de_processadores`. A seguir, temos um exemplo de como executar o programa:

```bash
./trabalho_escalonador tarefas.txt 2
```

Onde:

`nome_do_arquivo`: O nome do arquivo que contém informações sobre as tarefas a serem escalonadas.
`quantidade_de_processadores`: Um número que indica a quantidade de processadores disponíveis.


## Formato do Arquivo de Entrada

O arquivo de entrada deve conter, em cada linha, o nome da tarefa (identificação única) seguido por um espaço e um número inteiro que representa o tempo de execução em segundos. Por exemplo:

```Plaintext
a1 5
a2 1
a3 10
b1 10
b2 3
b3 7
b4 8
c1 8
c2 2
```
## Política de Escalonamento

O programa utiliza duas políticas de escalonamento: SJF (menores tarefas primeiro) e sua versão oposta (maiores tarefas primeiro).

## Saída do Programa

Como saída, o programa gera um arquivo contendo informações sobre o escalonamento realizado. Cada processador terá um bloco de informações, incluindo o ID do processador, o nome de cada tarefa, e o instante inicial e final de execução em segundos. O arquivo de saída não possui espaços.

## Exemplo de Arquivo de Saída

Para exemplificar, considerando a execução do programa com o arquivo de entrada mencionado anteriormente e dois processadores, a saída pode ser semelhante à seguinte:

```plaintext
Processador_1
a2;0;1
b2;1;4
b3;4;11
c1;11;19
b1;19;29

Processador_2
c2;0;2
a1;2;7
b4;7;15
a3;15;25
```

Este exemplo demonstra o escalonamento das tarefas nos dois processadores, seguindo a política SJF. O formato segue a estrutura mencionada anteriormente, facilitando a interpretação dos resultados.

*Observação*: É importante garantir que o arquivo de entrada esteja formatado corretamente e que o programa seja executado com os parâmetros apropriados.

# Licença

Certifique-se de criar um arquivo chamado `LICENSE.md` no mesmo diretório do README, e nele, adicione os termos da [Licença MIT](https://opensource.org/licenses/MIT).
