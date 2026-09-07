#include <iostream>
#include <cstdlib>

#include <chrono>

#include "Estatisticas.h"
#include "Ordenacao.h"

void Ordenacao::selectionSort(std::vector<int>& A, Estatisticas& est) {
    auto inicio = std::chrono::steady_clock::now();

    int i, j, min;

    int x;

    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    for(i = 0; i < n - 1; i++) {

        min = i;

        for(j = i + 1; j < n; j++) {

            est.comparacoes++;

            if(A[j] < A[min]) {
                min = j;
            }
        }

        x = A[min];
        A[min] = A[i];
        A[i] = x;

        est.movimentacoes += 3;
    }

    auto fim = std::chrono::steady_clock::now();

    // Calcula a diferença diretamente em segundos, armazenando em um double
    std::chrono::duration<double> diferenca = fim - inicio;
    est.tempoExecucao = diferenca.count();
}

void Ordenacao::insertionSort(std::vector<int>& A, Estatisticas& est) {
    auto inicio = std::chrono::steady_clock::now();

    int i, j;

    int x;

    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    for(i = 1; i < n; i++) {

        x = A[i];
        est.movimentacoes++;

        j = i - 1;

        while(j >= 0) {
            est.comparacoes++;

            if(x < A[j]) {
                A[j + 1] = A[j];
                est.movimentacoes++;
                j--;
            } else {
                break;
            }
        }

        A[j + 1] = x;
        est.movimentacoes++;
    }

    auto fim = std::chrono::steady_clock::now();

    // Calcula a diferença diretamente em segundos, armazenando em um double
    std::chrono::duration<double> diferenca = fim - inicio;
    est.tempoExecucao = diferenca.count();
}

void Ordenacao::shellSort(std::vector<int>& A, Estatisticas& est) {
    auto inicio = std::chrono::steady_clock::now();

    int n = A.size();
    int h = 1;

    est.comparacoes = 0;
    est.movimentacoes = 0;

    if(n <= 1) {
        auto fim = std::chrono::steady_clock::now();

        // Calcula a diferença diretamente em segundos, armazenando em um double
        std::chrono::duration<double> diferenca = fim - inicio;
        est.tempoExecucao = diferenca.count();

        return;
    }

    while (h < n) {
        h = h * 3 + 1;
    }

    do {
        h /= 3;

        for(int i = h; i < n; i++) {
            int x = A[i];
            est.movimentacoes++;

            int j = i;

            while(j >= h) {
                est.comparacoes++;

                if(A[j - h] > x) {
                    A[j] = A[j - h];
                    est.movimentacoes++;
                    j -= h;
                } else {
                    break;
                }
            }

            A[j] = x;
            est.movimentacoes++;
        }

    } while (h != 1);

    auto fim = std::chrono::steady_clock::now();

    // Calcula a diferença diretamente em segundos, armazenando em um double
    std::chrono::duration<double> diferenca = fim - inicio;
    est.tempoExecucao = diferenca.count();
}

void Ordenacao::ordena(int esq, int dir, std::vector<int>& A, Estatisticas& est) {
    int i;
    int j;

    particao(esq, dir, i, j, A, est);

    if(esq < j) {
        ordena(esq, j, A, est);
    }

    if(i < dir) {
        ordena(i, dir, A, est);
    }
}

void Ordenacao::quickSort(std::vector<int>& A, Estatisticas& est) {
    auto inicio = std::chrono::steady_clock::now();

    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    if(n > 1) {
        ordena(0, n - 1, A, est);
    }

    auto fim = std::chrono::steady_clock::now();

    // Calcula a diferença diretamente em segundos, armazenando em um double
    std::chrono::duration<double> diferenca = fim - inicio;
    est.tempoExecucao = diferenca.count();
}

void Ordenacao::particao(int esq, int dir, int& i, int& j, std::vector<int>& A, Estatisticas& est) {
    int aux;

    i = esq;
    j = dir;

    int pivo = A[(i + j) / 2];
    est.movimentacoes++;

    do {
        while(i <= dir) {
            est.comparacoes++;

            if(A[i] < pivo) {
                i++;
            } else {
                break;
            }
        }

        while(j >= esq) {
            est.comparacoes++;

            if(A[j] > pivo) {
                j--;
            } else {
                break;
            }
        }

        if(i <= j) {
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;

            est.movimentacoes += 3;

            i++;
            j--;
        }

    } while (i <= j);
}

void Ordenacao::refaz(int esq, int dir, std::vector<int>& A, Estatisticas& est) {
    int i = esq;
    int j;
    int x;

    j = i * 2 + 1;

    x = A[i];
    est.movimentacoes++;

    while(j <= dir) {
        if(j < dir) {
            est.comparacoes++;

            if(A[j] < A[j + 1]) {
                j++;
            }
        }

        est.comparacoes++;

        if(x >= A[j]) {
            break;
        }

        A[i] = A[j];
        est.movimentacoes++;

        i = j;

        j = i * 2 + 1;
    }

    A[i] = x;
    est.movimentacoes++;
}

void Ordenacao::constroi(std::vector<int>& A, int n, Estatisticas& est) {
    for(int esq = n / 2 - 1; esq >= 0; esq--) {
        refaz(esq, n - 1, A, est);
    }
}

void Ordenacao::heapSort(std::vector<int>& A, Estatisticas& est) {
    auto inicio = std::chrono::steady_clock::now();

    int n = A.size();

    est.comparacoes = 0;
    est.movimentacoes = 0;

    if(n > 1) {
        constroi(A, n, est);

        int esq = 0;
        int dir = n - 1;

        while(dir > 0) {
            int x = A[0];
            A[0] = A[dir];
            A[dir] = x;

            est.movimentacoes += 3;

            dir--;

            refaz(esq, dir, A, est);
        }
    }

    auto fim = std::chrono::steady_clock::now();

    // Calcula a diferença diretamente em segundos, armazenando em um double
    std::chrono::duration<double> diferenca = fim - inicio;
    est.tempoExecucao = diferenca.count();
}