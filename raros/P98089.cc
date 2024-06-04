#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int suma_manies(vector<int> disposicio, vector<vector<int>>& manies) {
    int suma = 0;
    for (int i = 0; i < disposicio.size() - 1; i++) {
        suma += manies[disposicio[i]][disposicio[i + 1]];
    }
    return suma;
}

void troba_disposicio_optima(vector<string>& persones, vector<vector<int>>& manies, vector<int>& disposicio_optima, int& suma_minima, int n) {
    suma_minima = 1000000000000;
    vector<int> disposicio_aux(n);

    function<void(int)> backtrack = [&](int i) {
        if (i == n) {
            int suma = suma_manies(disposicio_aux, manies);
            if (suma < suma_minima) {
                suma_minima = suma;
                disposicio_optima = disposicio_aux;
            }
        } else {
            for (int j = i; j < n; j++) {
                swap(disposicio_aux[i], disposicio_aux[j]);
                backtrack(i + 1);
                swap(disposicio_aux[i], disposicio_aux[j]);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        disposicio_aux[i] = i;
    }

    backtrack(0);
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<string> persones(n);
        for (int i = 0; i < n; i++) {
            cin >> persones[i];
        }

        vector<vector<int>> manies(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> manies[i][j];
                manies[j][i] = manies[i][j];
            }
        }

        vector<int> disposicio_optima(n);
        int suma_minima = 1000000000000;
        troba_disposicio_optima(persones, manies, disposicio_optima, suma_minima, n);

        cout << suma_minima << endl;
        for (int i = 0; i < n; i++) {
            cout << persones[disposicio_optima[i]] << " ";
        }
        cout << endl;
    }

    return 0;
}