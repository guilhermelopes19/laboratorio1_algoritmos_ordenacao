// ATENÇÃO - APAGAR DEPOIS!!!! 
// Leiam o 'REGISTRO_ALTERACOES.txt' sobre as alterações


#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <vector>
#include "Estatisticas.h"

class Ordenacao
{
        private:
        /// Função auxiliar utilizada pelo Quick Sort para dividir o vector em duas partes.
        static void particao( int esq, int dir, int& i, int& j, std::vector<int>& A, Estatisticas& est);
        
        // Função auxiliar recursiva utilizada pelo Quick Sort.
        static void ordena( int esq, int dir, std::vector<int>& A, Estatisticas& est);

        // Função auxiliar do Heap Sort para reorganizar uma parte do vector em heap máximo.
        static void refaz( int esq, int dir, std::vector<int>& A, Estatisticas& est);

        // Função auxiliar do Heap Sort que utiliza refaz para transformar o vector em um heap máximo.
        static void constroi( std::vector<int>& A, int n, Estatisticas& est);

    public:
        // O método é static porque pertence à classe e não precisa de um objeto específico.
        // O '&' passa o vetor por referência, evitando criar uma cópia desnecessária.
        static void selectionSort(std::vector<int>& dados, Estatisticas& est);
        static void insertionSort(std::vector<int>& dados, Estatisticas& est);
        static void shellSort(std::vector<int>& dados, Estatisticas& est);
        static void quickSort(std::vector<int>& dados, Estatisticas& est);
        static void heapSort(std::vector<int>& dados, Estatisticas& est);
};

#endif



// ATENÇÃO - APAGAR DEPOIS!!!! 
//CÓDIGO ANTIGO. SE CONCORDAREM COM ALTERAÇÃO QUE FIZ, APAGUEM ESSE COMENTÁRIO 

// #ifndef ORDENACAO_H
// #define ORDENACAO_H

// #include "Estatisticas.h"

// typedef int ChaveTipo;

// typedef struct Item {
//     ChaveTipo Chave;
// } Item;

// typedef int Indice;

// void OrdenacaoSelecao(Item *A, Indice n, Estatisticas &est);
// void OrdenacaoInsercao(Item *A, Indice n, Estatisticas &est);

// #endif