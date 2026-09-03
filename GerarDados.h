#ifndef GERAR_DADOS_H
#define GERAR_DADOS_H

#include <vector>

class GeradorDados
{
public:
    std::vector<int> gerarAleatorio(int tamanho);
    std::vector<int> gerarOrdenado(int tamanho);
    std::vector<int> gerarInverso(int tamanho);
    std::vector<int> gerarParcialmenteOrdenado(int tamanho);
};

#endif