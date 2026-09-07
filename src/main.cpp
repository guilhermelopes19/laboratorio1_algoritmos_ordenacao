// LABORATÓRIO 1 —  ALGORITMOS DE ORDENAÇÃO
// Disciplina: Estrutura de Dados 2
// Professora: Inês
// Alunos: Bruno Barreto, Dimitrius Khouri e Guilherme Lopes 



#include <iostream>
#include <cstdlib>
#include <Estatisticas.h>
#include <menus.h>
//permite o uso do vector
#include <vector>
//biblioteca necessária para faezr validação da opção digitada pelo usário (digitar caracteres ao invés de números)
#include <limits>
//permite usar acentuação
#include <windows.h>


using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcao;
    vector<int> listaDados;

    do {
        system("cls");
        cout << "--- Bem vindo a Ordenação ---\n"
             << "1.  Gerar um conjunto de dados\n"
             << "2.  Exibir os dados gerados\n"
             << "3.  Ordenar utilizando Selection Sort\n"
             << "4.  Ordenar utilizando Insertion Sort\n"
             << "5.  Ordenar utilizando Shell Sort\n" 
             << "6.  Ordenar utilizando Quick Sort\n" 
             << "7.  Ordenar utilizando Heap Sort\n"
             << "8.  Executar e comparar todos os algoritmos\n"
             << "9.  Encerrar o programa\n" 
             << endl;

        cout << "Digite o numero da opção desejada: " <<endl;
        cin >> opcao;

        // Verifica se o usuario digitou um valor invalido, como uma letra
        if(cin.fail()){
            // Limpa o estado de erro do cin para permitir novas leituras
            cin.clear();
            // Descarta a entrada invalida que ficou armazenada no buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nEntrada inválida! Digite apenas numeros\n" << endl;
            system("pause");

            // Volta para o inicio do menu principal
            continue;

        }

        switch (opcao){
            case 1:
                menuGerarDados(listaDados);
                break;
            case 2:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuExibirDados(listaDados);
                break;
            case 3:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuSelectionSort(listaDados);
                break;
            case 4:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuInsertionSort(listaDados);
                break;
            case 5:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuShellSort(listaDados);
                break;
            case 6:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuQuickSort(listaDados);
                break;
            case 7:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuHeapSort(listaDados);
                break;
            case 8:
                if(listaDados.empty()) {
                    cout << "\nNenhum conjunto de dados foi gerado!\n"<< endl;
                    system("pause");
                    break;
                }
                menuExecutarComparar(listaDados);
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
