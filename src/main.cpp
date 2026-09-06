#include <iostream>
#include <cstdlib>
#include <Estatisticas.h>

using namespace std;

int main() {
    int n, opcao;

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
                cout << "Gerar dados" <<endl;
                break;
            
            case 2:
                cout << "Exibir Dados" <<endl;
                break;

            case 3:
                cout << "Selection Sort" <<endl;
                break;

            case 4:
                cout << "Insertion Sort" <<endl;
                break;

            case 5:
                cout << "Shell Sort" <<endl;
                break;

            case 6:
                cout << "Quick Sort" <<endl;
                break;

            case 7:
                cout << "Heap Sort" <<endl;
                break;

            case 8:
                cout << "Comparar tudo" <<endl;
                break;
                
            case 9:
                cout << "Encerrar" <<endl;
                break;

            default:
                cout <<"Opcao invalida " <<endl;

        }

    } while(opcao!=9);


     cout << "Tchau! " <<endl;

}
