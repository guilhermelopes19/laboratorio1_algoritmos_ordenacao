#include <iostream>
#include <cstdlib>
#include <Estatisticas.h>
#include <menus.h>
#include <Ordenacao.h>
#include <vector>

using namespace std;

int main() {
    int opcao;
    vector<int> listaDados;

    do {
        system("cls");

        cout << "--- Bem vindo a Ordenacao ---\n\
                1.  Gerar um conjunto de dados; \n\
                2.  Exibir os dados gerados;\n\
                3.  Ordenar utilizando Selection Sort;\n\
                4.  Ordenar utilizando Insertion Sort;\n\
                5.  Ordenar utilizando Shell Sort;\n\
                6.  Ordenar utilizando Quick Sort;\n\
                7.  Ordenar utilizando Heap Sort;\n\
                8.  Executar e comparar todos os algoritmos;\n\
                9.  Encerrar o programa\n"<< endl;

        cout << "Digite o numero da opcao desejada: " <<endl;
        cin >> opcao;

        switch (opcao){
            case 1:
                menuGerarDados(listaDados);
                break;
            case 2:
                menuExibirDados(listaDados);
                break;
            case 3:
                menuSelectionSort();
                break;
            case 4:
                menuInsertionSort();
                break;
            case 5:
                menuShellSort();
                break;
            case 6:
                menuQuickSort();
                break;
            case 7:
                menuHeapSort();
                break;
            case 8:
                menuExecutarComparar();
                break;
            case 9:
                cout << "Encerrar" <<endl;
                break;
            default:
                cout << "Opcao invalida " <<endl;
                system("pause");
        }

    } while(opcao!=9);


     cout << "Tchau! " <<endl;

}
