#include <GerarDados.h>

using namespace std;

vector<int> GeradorDados::gerarAleatorio(int tamanho) {
   uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);

    for(int i = 0; i < tamanho; i++) {
        listaNum[i] = distribuicao(gen);
    }

    return listaNum;
}

vector<int> GeradorDados::gerarOrdenado(int tamanho){
    // ATENÇÃO - APAGAR DEPOIS!!!! 
    // Comentei a linha do código abaixo e copilou normalmente
    // Se nos testes não apresentar erros, rapagar depois esse código comentado
    // uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);

    for(int i = 0; i < tamanho; i++) {
        listaNum[i] = i+1;
    }

    return listaNum;
}

vector<int> GeradorDados::gerarInverso(int tamanho){
    // ATENÇÃO - APAGAR DEPOIS!!!! 
    // Comentei a linha do código abaixo e copilou normalmente
    // Se nos testes não apresentar erros, rapagar depois esse código comentado
    // uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < tamanho; i++) {
        listaNum[i] = tamanho - i;
    }

    return listaNum;
}

vector<int> GeradorDados::gerarParcialmenteOrdenado(int tamanho){
    uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < tamanho; i++) {
        if(i < tamanho/2) {
            listaNum[i] = i+1;
        } else {
            listaNum[i] = distribuicao(gen);
        }
    }

    return listaNum;
}
