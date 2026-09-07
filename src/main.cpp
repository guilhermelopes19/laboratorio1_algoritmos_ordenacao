#include <iostream>
#include <cstdlib>
#include <Estatisticas.h>
#include <menus.h>
#include <Ordenacao.h>
#include <vector>

using namespace std;

int main() {
    vector<int> dados = {8, 7, 6, 5, 4, 3, 2, 1};

    Estatisticas est;

    Ordenacao::quickSort(dados, est);

    for (int valor : dados)
    {
        cout << valor << " ";
    }

    cout << endl;
    cout << "Comparacoes: " << est.comparacoes << endl;
    cout << "Movimentacoes: " << est.movimentacoes << endl;
    cout << "Tempo: " << est.tempoExecucao << endl;

}
