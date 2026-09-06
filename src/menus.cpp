#include <menus.h>
#include <iostream>
#include <GerarDados.h>

using namespace std;

void menuGerarDados(vector<int>& listaDados) {
    int opcao, tamanho;

    system("cls");
    cout << "--- Gerar Dados ---\n";
    cout << "Quantidade de dados desejada\n";
    cout << "1. 1.000 elementos\n\
2. 10.000 elementos\n\
3. 50.000 elementos\n\
4. 100.000 elementos\n";

    cout << "Digite o numero da opcao desejada: " <<endl;
    cin >> opcao;

    switch(opcao) {
        case 1:
            tamanho = 1000;
            break;
        case 2:
            tamanho = 10000;
            break;
        case 3: 
            tamanho = 50000;
            break;
        case 4:
            tamanho = 100000;
            break;
        default:
            cout << "Opcao invalida! Voltando ao Menu...\n";
            system("pause");
            return;
    }

    system("cls");
    cout << "--- Gerar Dados ---\n\
1. Dados Aleatorios\n\
2. Dados Ordenados\n\
3. Dados Ordem Inversa\n\
4. Dados Parcialmente Ordenados\n";

    cout << "Digite o numero da opcao desejada: " <<endl;
    cin >> opcao;

    switch(opcao) {
        case 1:
            listaDados = GeradorDados::gerarAleatorio(tamanho);
            break;
        case 2:
            listaDados = GeradorDados::gerarOrdenado(tamanho);
            break;
        case 3: 
            listaDados = GeradorDados::gerarInverso(tamanho);
            break;
        case 4:
            listaDados = GeradorDados::gerarParcialmenteOrdenado(tamanho);
            break;
        default:
            cout << "Opcao invalida! Voltando ao Menu...\n";
            system("pause");
            return;
    }

    cout << "Lista de dados gerada com sucesso!\n";
    system("pause");
}

void menuExibirDados(vector<int>& listaDados) {

}

void menuSelectionSort() {

}

void menuInsertionSort() {

}

void menuShellSort() {

}

void menuQuickSort() {

}

void menuHeapSort() {

}

void menuExecutarComparar() {

}
