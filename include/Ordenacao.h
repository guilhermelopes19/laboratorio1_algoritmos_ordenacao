#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>
#include "Estatisticas.h"

class Ordenacao {
    private:
        // Função auxiliar utilizada pelo Quick Sort para dividir o vetor em duas partes
        static void particao(int esq, int dir, int& i, int& j, std::vector<int>& A, Estatisticas& est);
        // Função auxiliar recursiva utilizada pelo Quick Sort
        static void ordena(int esq, int dir, std::vector<int>& A, Estatisticas& est);
        // Função auxiliar do Heap Sort para reorganizar uma parte do vetor em heap máximo
        static void refaz(int esq, int dir, std::vector<int>& A, Estatisticas& est);
        // Função auxiliar do Heap Sort que utiliza refaz para transformar o vetor em um heap máximo
        static void constroi(std::vector<int>& A, int n, Estatisticas& est);

    public:
        static void selectionSort(std::vector<int>& dados, Estatisticas& est);
        static void insertionSort(std::vector<int>& dados, Estatisticas& est);
        static void shellSort(std::vector<int>& dados, Estatisticas& est);
        static void quickSort(std::vector<int>& dados, Estatisticas& est);
        static void heapSort(std::vector<int>& dados, Estatisticas& est);
};

#endif