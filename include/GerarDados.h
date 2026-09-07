#ifndef GERAR_DADOS_H
#define GERAR_DADOS_H

#include <vector>
#include <random>

class GeradorDados {
    private:
        inline static std::random_device rd;
        inline static std::mt19937 gen{rd()};

    public:
        static std::vector<int> gerarAleatorio(int tamanho);
        static std::vector<int> gerarOrdenado(int tamanho);
        static std::vector<int> gerarInverso(int tamanho);
        static std::vector<int> gerarParcialmenteOrdenado(int tamanho);
};

#endif