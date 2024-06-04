#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Graf;

bool cicles(const Graf& g, int u, vector<bool>& visited) {
    if(visited[u]) {
        return true;
    }
    
    visited[u] = true;

    for(int i = 0; i < g[u].size(); ++i) {
        int adj = g[u][i];
        if(cicles(g, adj, visited)) return true;
    }

    visited[u] = false; //mas de un ciclo podria tener que visitar el mismo nodo
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int x, y;
        Graf g(n);
        
        //lectura casos
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            g[x].push_back(y);
        }

        //funcion para saber si hay ciclo
        bool cicle = false;
        vector<bool> visited(n, false);

        for(int i = 0; i < n and not cicle; ++i) {
            if(!visited[i] and cicles(g, i, visited)) cicle = true;
        }

        //escritura del resultado
        if(cicle) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
