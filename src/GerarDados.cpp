#include <GerarDados.h>
#include <random>

using namespace std;

vector<int> GeradorDados::gerarAleatorio(int tamanho) {
    uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < listaNum.size(); i++) {
        listaNum.push_back(distribuicao(gen));
    }

    return listaNum;
}

vector<int> GeradorDados::gerarOrdenado(int tamanho){
    uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < listaNum.size(); i++) {
        listaNum.push_back(i+1);
    }

    return listaNum;
}

vector<int> GeradorDados::gerarInverso(int tamanho){
    uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < listaNum.size(); i++) {
        listaNum.push_back(1000-i);
    }

    return listaNum;
}

vector<int> GeradorDados::gerarParcialmenteOrdenado(int tamanho){
    uniform_int_distribution<> distribuicao(1, tamanho * 1000);

    vector<int> listaNum(tamanho);
    for(int i = 0; i < listaNum.size(); i++) {
        if(i < listaNum.size()/2) {
            listaNum.push_back(i+1);
        } else {
            listaNum.push_back(distribuicao(gen));
        }
    }

    return listaNum;
}
