#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VI;


void escriure(const VI& sol, const VI& mon, int x) {
    cout << x << " = ";
    int n = sol.size();
    bool primer = true;
    for(int i = 0; i < n; ++i) {
        if (sol[i]) {
            if (primer) primer = false;
            else cout << " + ";
            cout << mon[i];
            if (i%2 == 1) cout << 'p'; //si es impar significa que es la otra cara
        }
    }
    cout << endl;
}

void canvi(const VI& mon, VI& sol, int x, int idx, int sum_aux) {
    if (sum_aux > x) return;
    int n = mon.size();
    if (n == idx) { //si llenamos vector
       if (sum_aux == x) escriure(sol, mon, x); //si la suma es la que queremos
    }
    else {
        sol[idx] = true; //lo cojo
        canvi(mon, sol, x, idx+1, sum_aux + mon[idx]);
        sol[idx] = false; //no lo cojo
        canvi(mon, sol, x, idx+1, sum_aux);
    }
}

int main() {
    int x, n;
    while (cin >> x >> n) {
        VI monedes(2*n);
        for (int i = 0; i < 2*n; i+=2) {
            cin >> monedes[i];
            monedes[i+1] = monedes[i];
        }
        sort(monedes.begin(), monedes.end());
        VI sol(2*n, false);
        canvi(monedes, sol, x, 0, 0);
        cout << "----------" << endl;
    }
}