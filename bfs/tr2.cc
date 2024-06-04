#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> Graf;

bool ok(int n, int m, int i, int j, const Graf& G){ //dentro de rango
    return 0 <= i and i < n and 0 <= j and j < m and G[i][j] != 'X';
}

int search(const Graf& g ,int f0, int c0){
    int n = g.size();
    int m = g[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(f0, c0));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<bool>> visitat(n, vector<bool>(m, false));
    dist[f0][c0] = 0;

    while(not q.empty()){
        int f = q.front().first;
        int c = q.front().second;
        q.pop();
        if(not visitat[f][c]) {
            visitat[f][c] = true;
            if (g[f][c] == 't') return dist[f][c];

            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};

            for (int k = 0; k < 4; ++k) {
                int ff = f + dx[k];
                int cc = c + dy[k];
                if (ok(n, m, ff, cc, g) and not visitat[ff][cc]) {
                    q.push(make_pair(ff, cc));
                    dist[ff][cc] = dist[f][c] + 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin >> n >> m;

    Graf g(n, VC(m));
    for(int i = 0; i < n; ++i){ //lectura entrada
        for(int j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    //funcion
    int result = search(g, x-1, y-1);
    if(result == -1) cout << "no es pot arribar a cap tresor" << endl;
    else cout << "distancia minima: " << result << endl;
    
}