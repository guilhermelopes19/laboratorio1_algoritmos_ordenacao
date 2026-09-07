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