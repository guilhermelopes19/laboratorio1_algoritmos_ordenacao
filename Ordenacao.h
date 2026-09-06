#ifndef ORDENACAO_H
#define ORDENACAO_H

#include "Estatisticas.h"

typedef int ChaveTipo;

typedef struct Item {
    ChaveTipo Chave;
} Item;

typedef int Indice;

void OrdenacaoSelecao(Item *A, Indice n, Estatisticas &est);
void OrdenacaoInsercao(Item *A, Indice n, Estatisticas &est);

#endif