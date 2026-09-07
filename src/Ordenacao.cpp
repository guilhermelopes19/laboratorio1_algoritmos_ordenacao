#include <iostream>
#include <cstdlib>

//inclui a biblioteca de tempo
#include <time.h>

#include "Estatisticas.h"
#include "Ordenacao.h"

// ATENÇÃO - APAGAR DEPOIS!!!!
// Alterado o método para que possa receber o vector diretamente.
void Ordenacao::selectionSort(std::vector<int>& A, Estatisticas& est)
{
    clock_t inicio = clock();

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes era: Indice i, j, Min;
    // Como não usamos mais o typedef Indice, usamos int diretamente.
    int i, j, min;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes era: Item x;
    // Como o vector agora armazena int diretamente,
    // a variável auxiliar x também passa a ser int.
    int x;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ADICIONADO:
    // Guardamos o tamanho do vector em uma variável int.
    // Assim não precisamos comparar int com A.size() dentro dos laços.
    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes o vetor era percorrido da posição 1 até n - 1.
    // O vector usa índices de 0 até n - 1.
    // Por isso agora começamos em 0.
    for (i = 0; i < n - 1; i++)
    {

        min = i;

        // ATENÇÃO - APAGAR DEPOIS!!!!
        // ALTERADO:
        // Antes era:
        // for (j = i + 1; j <= n; j++)
        //
        // Como o último índice válido do vector é n - 1,
        // usamos j < n.
        for (j = i + 1; j < n; j++)
        {

            est.comparacoes++;

            // ATENÇÃO - APAGAR DEPOIS!!!!
            // ALTERADO:
            // Antes era:
            // if (A[j].Chave < A[Min].Chave)
            //
            // Como cada posição do vector já possui um int,
            // podemos comparar os valores diretamente.
            if (A[j] < A[min])
            {
                min = j;
            }
        }

        // ATENÇÃO - APAGAR DEPOIS!!!!
        // ALTERADO:
        // Antes A[min] e A[i] eram do tipo Item.
        // Agora as posições do vector armazenam int diretamente.
        x = A[min];
        A[min] = A[i];
        A[i] = x;

        est.movimentacoes += 3;
    }

    clock_t fim = clock();

    // Calcula o tempo de execução do algoritmo em segundos.
    est.tempoExecucao =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Alterado o método para que possa receber o vector diretamente.
void Ordenacao::insertionSort(std::vector<int>& A, Estatisticas& est)
{
    clock_t inicio = clock();

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes era: Indice i, j;
    // Como não usamos mais o typedef Indice, usamos int diretamente.
    int i, j;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes era: Item x;
    // Como o vector armazena int diretamente,
    // a variável auxiliar x também passa a ser int.
    int x;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ADICIONADO:
    // Guardamos o tamanho do vector em uma variável int.
    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // ALTERADO:
    // Antes os dados começavam na posição 1 e o laço começava em 2.
    // Como o vector começa na posição 0,
    // agora começamos pela posição 1.
    for (i = 1; i < n; i++)
    {
        // Guarda o elemento atual para encontrar sua posição correta
        // dentro da parte que já está ordenada.
        x = A[i];
        est.movimentacoes++;

        j = i - 1;

        // ATENÇÃO - APAGAR DEPOIS!!!!
        // REMOVIDO:
        // Antes existia:
        // A[0] = x; /* sentinela */
        //
        // Isso não pode mais ser usado porque a posição 0
        // agora contém um dado real do vector.

        // ATENÇÃO - APAGAR DEPOIS!!!!
        // ALTERADO:
        // O teste j >= 0 impede que o algoritmo acesse
        // uma posição negativa do vector.
        //
        // A comparação entre os elementos agora é feita
        // diretamente com x < A[j].
        while (j >= 0)
        {
            est.comparacoes++;

            if (x < A[j])
            {

                A[j + 1] = A[j];
                est.movimentacoes++;

                j--;
            }
            else
            {
                break;
            }
        }

        // Coloca o valor atual na posição correta.
        A[j + 1] = x;
        est.movimentacoes++;
    }

    clock_t fim = clock();

    // Calcula o tempo de execução do algoritmo em segundos.
    est.tempoExecucao =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Utilizei como referência o código do livro Projeto de Algoritmos,
// de Nívio Ziviani, e o PDF disponibilizado pela professora.
// Adaptei o algoritmo para receber vector<int> e utilizar a classe Ordenacao.
void Ordenacao::shellSort(std::vector<int>& A, Estatisticas& est)
{
    clock_t inicio = clock();

    int n = A.size();
    int h = 1;

    est.comparacoes = 0;
    est.movimentacoes = 0;

    // Evita problemas caso o vector tenha zero ou apenas um elemento.
    if (n <= 1)
    {
        clock_t fim = clock();

        est.tempoExecucao =
            ((double)(fim - inicio)) / CLOCKS_PER_SEC;

        return;
    }

    // h representa o intervalo entre os elementos comparados.
    // Calcula inicialmente o maior intervalo da sequência:
    // 1, 4, 13, 40, 121...
    while (h < n)
    {
        // Mantida a sequência 3h + 1 apresentada no material da professora.
        h = h * 3 + 1;
    }

    // Vai diminuindo os intervalos até chegar em 1.
    do
    {
        h /= 3;

        // Começa a percorrer o vector a partir da posição h.
        for (int i = h; i < n; i++)
        {
            int x = A[i];
            est.movimentacoes++;

            int j = i;

            // Compara o elemento atual com elementos
            // que estão separados pelo intervalo h.
            while (j >= h)
            {
                est.comparacoes++;

                if (A[j - h] > x)
                {
                    A[j] = A[j - h];
                    est.movimentacoes++;

                    j -= h;
                }
                else
                {
                    break;
                }
            }

            A[j] = x;
            est.movimentacoes++;
        }

    } while (h != 1);

    clock_t fim = clock();

    est.tempoExecucao =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Função auxiliar recursiva utilizada pelo Quick Sort.
// Foi adaptada do código da professora para utilizar vector<int>
// e trabalhar com a classe Ordenacao.
void Ordenacao::ordena( int esq, int dir, std::vector<int>& A, Estatisticas& est)
{
    // ATENÇÃO - APAGAR DEPOIS!!!!
    // As variáveis i e j serão alteradas pela função particao
    // e indicam os limites das próximas partes que serão ordenadas.
    int i;
    int j;

    // Divide o trecho atual do vector em duas partes,
    // posicionando os elementos em relação ao pivô.
    particao(esq, dir, i, j, A, est);

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // Se ainda existir uma parte à esquerda para ordenar,
    // chama novamente a própria função.
    if (esq < j)
    {
        ordena(esq, j, A, est);
    }

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // Se ainda existir uma parte à direita para ordenar,
    // chama novamente a própria função.
    if (i < dir)
    {
        ordena(i, dir, A, est);
    }
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Função principal do Quick Sort.
// Ela prepara as estatísticas, controla o tempo de execução
// e inicia a chamada da função recursiva ordena.
void Ordenacao::quickSort( std::vector<int>& A, Estatisticas& est )
{
    clock_t inicio = clock();

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // Guardamos o tamanho do vector em uma variável int,
    // seguindo o mesmo padrão utilizado nos outros algoritmos.
    int n = A.size();

    // Reinicia as estatísticas antes de começar a ordenação.
    est.comparacoes = 0;
    est.movimentacoes = 0;

    // ATENÇÃO - APAGAR DEPOIS!!!!
    // O Quick Sort só precisa ser executado se houver
    // mais de um elemento no vector.
    //
    // Como o vector começa na posição 0,
    // o primeiro índice é 0 e o último é n - 1.
    if (n > 1)
    {
        ordena(0, n - 1, A, est);
    }

    clock_t fim = clock();

    // Calcula o tempo total de execução do Quick Sort em segundos.
    // O tempo é medido apenas aqui, e não dentro da função recursiva,
    // para não reiniciar a medição em cada chamada.
    est.tempoExecucao =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Adaptado do código de Quick Sort apresentado pela professora.
// O código original utilizava Item, Indice e ponteiros.
// Foi adaptado para vector<int>, referências e a classe Ordenacao.
void Ordenacao::particao( int esq, int dir, int& i, int& j, std::vector<int>& A, Estatisticas& est )
{
    int aux;

    i = esq;
    j = dir;

    // Obtém como pivô o elemento central do trecho atual.
    int pivo = A[(i + j) / 2];
    est.movimentacoes++;

    do
    {
        // Procura, da esquerda para a direita,
        // um elemento que seja maior ou igual ao pivô.
        while (i <= dir)
        {
            est.comparacoes++;

            if (A[i] < pivo)
            {
                i++;
            }
            else
            {
                break;
            }
        }

        // Procura, da direita para a esquerda,
        // um elemento que seja menor ou igual ao pivô.
        while (j >= esq)
        {
            est.comparacoes++;

            if (A[j] > pivo)
            {
                j--;
            }
            else
            {
                break;
            }
        }

        // Caso os índices ainda não tenham se cruzado,
        // troca os elementos encontrados.
        if (i <= j)
        {
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;

            est.movimentacoes += 3;

            i++;
            j--;
        }

    } while (i <= j);
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// Utilizei como referência o código de Heap Sort apresentado pela professora.
// O código original utiliza Item, Indice e começa os índices na posição 1.
// Adaptei para receber vector<int>, trabalhar com índices iniciando em 0
// e utilizar a classe Ordenacao.
// Essa função reorganiza uma parte do vector para manter a propriedade do heap.
// No heap máximo, o pai precisa ser maior ou igual aos seus filhos.
void Ordenacao::refaz( int esq, int dir, std::vector<int>& A, Estatisticas& est )
{
    int i = esq;
    int j;
    int x;

    // No código da professora, como os índices começam em 1,
    // o filho esquerdo é calculado com i * 2.
    // Como no vector os índices começam em 0,
    // o filho esquerdo passa a ser 2 * i + 1.
    j = i * 2 + 1;

    // Guarda o valor atual para depois colocá-lo
    // na posição correta dentro do heap.
    x = A[i];
    est.movimentacoes++;

    // Continua enquanto existir um filho dentro
    // da parte do vector que ainda pertence ao heap.
    while (j <= dir)
    {
        // Se j < dir, significa que também existe um filho direito.
        if (j < dir)
        {
            // Conta a comparação entre os dois filhos.
            est.comparacoes++;

            // Se o filho direito for maior,
            // j passa a apontar para ele.
            if (A[j] < A[j + 1])
            {
                j++;
            }
        }

        // Compara o valor que está sendo reposicionado
        // com o maior dos filhos.
        est.comparacoes++;

        // Se x já for maior ou igual ao maior filho,
        // ele já está em uma posição válida no heap.
        if (x >= A[j])
        {
            break;
        }

        // Caso contrário, o maior filho sobe
        // para a posição atual.
        A[i] = A[j];
        est.movimentacoes++;

        // Agora continuamos analisando a partir
        // da posição para onde descemos.
        i = j;

        // Calcula novamente o filho esquerdo.
        j = i * 2 + 1;
    }

    // Coloca x na posição correta encontrada.
    A[i] = x;
    est.movimentacoes++;
}

// Essa função percorre os elementos que podem possuir filhos
// e utiliza refaz para montar o heap máximo.
void Ordenacao::constroi( std::vector<int>& A, int n, Estatisticas& est)
{
    // No vector, o último elemento que pode possuir filhos
    // está na posição n / 2 - 1.
    //
    // Exemplo com 8 elementos:
    // índices: 0 1 2 3 4 5 6 7
    // a posição 3 é o último índice que ainda pode ter filhos.
    for (int esq = n / 2 - 1; esq >= 0; esq--)
    {
        // n - 1 representa a última posição válida do vector.
        refaz(esq, n - 1, A, est);
    }
}

// ATENÇÃO - APAGAR DEPOIS!!!!
// O Heap Sort primeiro transforma o vector em um heap máximo.
// Depois, troca o maior elemento, que está na raiz,
// com o último elemento da parte ainda não ordenada.
void Ordenacao::heapSort( std::vector<int>& A, Estatisticas& est )
{
    clock_t inicio = clock();

    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    // Só precisa ordenar se existir mais de um elemento.
    if (n > 1)
    {
        // Primeiro constrói o heap máximo.
        // Depois dessa etapa, o maior valor estará na posição 0.
        constroi(A, n, est);

        // Como o vector começa em 0,
        // a raiz do heap fica na posição 0.
        int esq = 0;

        // dir representa a última posição
        // que ainda pertence ao heap.
        int dir = n - 1;

        // A cada repetição, o maior valor é colocado
        // no final da parte ainda não ordenada.
        while (dir > 0)
        {
            // Troca a raiz, que contém o maior valor,
            // com o último elemento do heap.
            int x = A[0];
            A[0] = A[dir];
            A[dir] = x;

            // A troca utiliza três atribuições.
            est.movimentacoes += 3;

            // O elemento colocado em A[dir] já está
            // na sua posição definitiva.
            // Por isso, diminuímos o tamanho do heap.
            dir--;

            // Como a raiz recebeu outro valor,
            // precisamos restaurar a propriedade do heap.
            refaz(esq, dir, A, est);
        }
    }

    clock_t fim = clock();

    est.tempoExecucao =
        ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

// ATENÇÃO - APAGAR DEPOIS!!!! 
//CÓDIGO ANTIGO. SE CONCORDAREM COM ALTERAÇÃO QUE FIZ, APAGUEM ESSE COMENTÁRIO 
// void OrdenacaoSelecao(Item *A, Indice n, Estatisticas &est) {
//     clock_t inicio = clock();

//     Indice i, j, Min;
//     Item x;

//     est.comparacoes = 0;
//     est.movimentacoes = 0;

//     for (i = 1; i <= n-1; i++) {
//         Min = i;
//         for (j = i+1; j <= n; j++) {
//             est.comparacoes++;
//             if (A[j].Chave < A[Min].Chave) {
//                 Min = j;
//             }
//         }
        
//         x = A[Min];
//         A[Min] = A[i];
//         A[i] = x;
//         est.movimentacoes += 3; 
//     }

//     clock_t fim = clock();
//     est.tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
// }

// void OrdenacaoInsercao(Item *A, Indice n, Estatisticas &est) {
//     clock_t inicio = clock();

//     Indice i, j;
//     Item x;

//     est.comparacoes = 0;
//     est.movimentacoes = 0;

//     for (i = 2; i <= n; i++) {
//         x = A[i]; 
//         est.movimentacoes++;
        
//         j = i-1;
//         A[0] = x; /* sentinela */
//         est.movimentacoes++;

//         est.comparacoes++;
//         while (x.Chave < A[j].Chave) {
//             A[j+1] = A[j];
//             est.movimentacoes++;
            
//             j--;
            
//             est.comparacoes++;
//         }
        
//         A[j+1] = x;
//         est.movimentacoes++;
//     }

//     clock_t fim = clock();
//     est.tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
// }