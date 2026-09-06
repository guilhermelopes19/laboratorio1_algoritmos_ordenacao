#include <iostream>
#include <cstdlib>
#include "Estatisticas.h"
#include "Ordenacao.h"

void OrdenacaoSelecao(Item *A, Indice n, Estatisticas &est) {
    clock_t inicio = clock();

    Indice i, j, Min;
    Item x;

    est.comparacoes = 0;
    est.movimentacoes = 0;

    for (i = 1; i <= n-1; i++) {
        Min = i;
        for (j = i+1; j <= n; j++) {
            est.comparacoes++;
            if (A[j].Chave < A[Min].Chave) {
                Min = j;
            }
        }
        
        x = A[Min];
        A[Min] = A[i];
        A[i] = x;
        est.movimentacoes += 3; 
    }

    clock_t fim = clock();
    est.tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

void OrdenacaoInsercao(Item *A, Indice n, Estatisticas &est) {
    clock_t inicio = clock();

    Indice i, j;
    Item x;

    est.comparacoes = 0;
    est.movimentacoes = 0;

    for (i = 2; i <= n; i++) {
        x = A[i]; 
        est.movimentacoes++;
        
        j = i-1;
        A[0] = x; /* sentinela */
        est.movimentacoes++;

        est.comparacoes++;
        while (x.Chave < A[j].Chave) {
            A[j+1] = A[j];
            est.movimentacoes++;
            
            j--;
            
            est.comparacoes++;
        }
        
        A[j+1] = x;
        est.movimentacoes++;
    }

    clock_t fim = clock();
    est.tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}