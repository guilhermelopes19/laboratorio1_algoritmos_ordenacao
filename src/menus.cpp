#include <menus.h>
#include <iostream>
#include <GerarDados.h>
#include <Estatisticas.h>
#include <Ordenacao.h>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

void printDados(vector<int> listaDados);
void printEstatisticas(Estatisticas est);

void menuGerarDados(vector<int>& listaDados) {
    int opcao, tamanho;

    system("cls");
    cout << "--- Gerar Dados ---\n";
    cout << "Quantidade de dados desejada\n";
    cout << "1. 1.000 elementos\n"
         << "2. 10.000 elementos\n"
         << "3. 50.000 elementos\n"
         << "4. 100.000 elementos\n"
         << "5. Informar outro tamanho\n" << endl; 

    cout << "\nDigite o número da opção desejada: " << endl;
    cin >> opcao;

    if(cin.fail()) {
        cin.clear();
        // Descarta a entrada invalida que ficou armazenada no buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEntrada inválida! Digite apenas números\n" << endl;
        system("pause");

        return;
    }

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

        case 5:
            cout << "\nDigite o tamanho do vetor:" <<endl;
            cin>> tamanho;

            if(cin.fail()) {
                cin.clear();
                // Descarta a entrada invalida que ficou armazenada no buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nEntrada inválida! Digite apenas números\n" << endl;
                system("pause");

                return;
            }
            
            if(tamanho <= 0) {
                cout << "\nTamanho do vetor inválido! Voltando ao Menu... \n"<<endl;;
                system("pause");
                return;
            }

            break;

        default:
            cout << "\nOpção inválida! Voltando ao Menu...\n";
            system("pause");
            return;
    }

    system("cls");
    cout << "--- Gerar Dados ---\n"
         << "1. Dados Aleatórios\n"
         << "2. Dados Ordenados\n"
         << "3. Dados Ordem Inversa\n"
         << "4. Dados Parcialmente Ordenados\n" << endl; 

    cout << "\nDigite o numero da opção desejada: " <<endl;
    cin >> opcao;

    if(cin.fail()) {
        cin.clear();
        // Descarta a entrada invalida que ficou armazenada no buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nEntrada inválida! Digite apenas números\n" << endl;
        system("pause");

        return;
    }

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
            cout << "\nOpção inválida! Voltando ao Menu...\n";
            system("pause");
            return;
    }

    cout << "\nLista de dados gerada com sucesso!\n";
    system("pause");
}

void menuExibirDados(vector<int> listaDados) {
    system("cls");
    cout << "--- Exibir Dados ---\n";
    
    printDados(listaDados);

    system("pause");
}

void menuSelectionSort(vector<int> listaDados) {
    Estatisticas estSelectionSort;
    
    system("cls");
    cout << "--- Selection Sort ---\n";

    cout << "\r[Aguarde, executando algoritmo...]" << flush;

    Ordenacao::selectionSort(listaDados, estSelectionSort);

    cout << "\r" << setw(50) << "" << flush;
    cout << "\r";

    printDados(listaDados);
    printEstatisticas(estSelectionSort);
    
    system("pause");
}

void menuInsertionSort(vector<int> listaDados) {
    Estatisticas estInsertionSort;
    
    system("cls");
    cout << "--- Insertion Sort ---\n";

    cout << "\r[Aguarde, executando algoritmo...]" << flush;

    Ordenacao::insertionSort(listaDados, estInsertionSort);

    cout << "\r" << setw(50) << "" << flush;
    cout << "\r";

    printDados(listaDados);
    printEstatisticas(estInsertionSort);
    
    system("pause");
}

void menuShellSort(vector<int> listaDados) {
    Estatisticas estShellSort;
    
    system("cls");
    cout << "--- Shell Sort ---\n";

    cout << "\r[Aguarde, executando algoritmo...]" << flush;

    Ordenacao::shellSort(listaDados, estShellSort);

    cout << "\r" << setw(50) << "" << flush;
    cout << "\r";

    printDados(listaDados);
    printEstatisticas(estShellSort);
    
    system("pause");
}

void menuQuickSort(vector<int> listaDados) {
    Estatisticas estQuickSort;
    
    system("cls");
    cout << "--- Quick Sort ---\n";

    cout << "\r[Aguarde, executando algoritmo...]" << flush;

    Ordenacao::quickSort(listaDados, estQuickSort);

    cout << "\r" << setw(50) << "" << flush;
    cout << "\r";

    printDados(listaDados);
    printEstatisticas(estQuickSort);
    
    system("pause");
}

void menuHeapSort(vector<int> listaDados) {
    Estatisticas estHeapSort;
    
    system("cls");
    cout << "--- Heap Sort ---\n";

    cout << "\r[Aguarde, executando algoritmo...]" << flush;

    Ordenacao::heapSort(listaDados, estHeapSort);

    cout << "\r" << setw(50) << "" << flush;
    cout << "\r";   

    printDados(listaDados);
    printEstatisticas(estHeapSort);
    
    system("pause");
}

void menuExecutarComparar(vector<int> listaDados) {
    vector<int> listaSelection = listaDados;
    vector<int> listaInsertion = listaDados;
    vector<int> listaShell = listaDados;
    vector<int> listaQuick = listaDados;
    vector<int> listaHeap = listaDados;
    
    Estatisticas estSelection;
    Estatisticas estInsertion;
    Estatisticas estShell;
    Estatisticas estQuick;
    Estatisticas estHeap;

    system("cls");

    cout << "--- Executar e Comparar Algoritmos ---" << endl;

    cout << setfill('-') << setw(100) << "" << endl;

    cout << setfill(' ');

    cout << left; 
    cout << setw(25) << "Algoritmo"
         << setw(25) << "Comparações"
         << setw(25) << "Movimentações" 
         << setw(25) << "Tempo de Execução (s)" << endl;
    
    cout << setfill('-') << setw(100) << "" << endl;

    cout << setfill(' ');


    cout << "\r[Aguarde, executando Selection Sort...]" << flush;
    Ordenacao::selectionSort(listaSelection, estSelection);
    cout << "\r"
         << setw(25) << "Selection Sort"
         << setw(25) << estSelection.comparacoes
         << setw(25) << estSelection.movimentacoes
         << setw(25) << estSelection.tempoExecucao 
         << endl;

    cout << "\r[Aguarde, executando Insertion Sort...]" << flush;
    Ordenacao::insertionSort(listaInsertion, estInsertion);
    cout << "\r"
         << setw(25) << "Insertion Sort"
         << setw(25) << estInsertion.comparacoes
         << setw(25) << estInsertion.movimentacoes
         << setw(25) << estInsertion.tempoExecucao 
         << endl;

    cout << "\r[Aguarde, executando Shell Sort...]" << flush;
    Ordenacao::shellSort(listaShell, estShell);
    cout << "\r"
         << setw(25) << "Shell Sort"
         << setw(25) << estShell.comparacoes
         << setw(25) << estShell.movimentacoes
         << setw(25) << estShell.tempoExecucao 
         << endl;

    cout << "\r[Aguarde, executando Quick Sort...]" << flush;
    Ordenacao::quickSort(listaQuick, estQuick);
    cout << "\r"
         << setw(25) << "Quick Sort"
         << setw(25) << estQuick.comparacoes
         << setw(25) << estQuick.movimentacoes
         << setw(25) << estQuick.tempoExecucao 
         << endl;
    
    cout << "\r[Aguarde, executando Heap Sort...]" << flush;
    Ordenacao::heapSort(listaHeap, estHeap);
    cout << "\r"
         << setw(25) << "Heap Sort"
         << setw(25) << estHeap.comparacoes
         << setw(25) << estHeap.movimentacoes
         << setw(25) << estHeap.tempoExecucao 
         << endl;
    
    cout << setfill('-') << setw(100) << "" << endl;

    system("pause");
}

void printDados(vector<int> listaDados) {
    cout << "[";

    if(listaDados.empty()) {
        cout << "Lista Vazia]" << endl;
        return;
    }
    
    for(long long unsigned int i = 0; i < listaDados.size(); i++) {
        if(i != listaDados.size()-1) {
            cout << listaDados[i] << ", ";
        } else {
            cout << listaDados[i] << "]" << endl;
        }
    }
}

void printEstatisticas(Estatisticas est) {
    cout << "-----------------------" << endl;
    cout << "Comparações      : " << est.comparacoes << endl;
    cout << "Movimentações    : " << est.movimentacoes << endl;
    cout << "Tempo de Execução: " << est.tempoExecucao << endl;
    cout << "-----------------------" << endl;
}
