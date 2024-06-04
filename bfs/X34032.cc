#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int dir_cavall = 8;
const int kx[dir_cavall] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int ky[dir_cavall] = {-1, 1, -2, 2, -2, 2, -1, 1};

bool pos_ok(int i, int j, int n, int m, const MC& Graf){
    return i >= 0 and i < n and j >= 0 and j < m and Graf[i][j] != 'X';
}

int bfs(const int& n, const int&m, const MC& tauler, MB& bol, int f0, int c0){
    queue<pair<int, int>> q;
    q.push({f0, c0});
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[f0][c0] = 0;

    while(not q.empty()){
        int f = q.front().first;
        int c = q.front().second;
        q.pop();

        if(not bol[f][c]){
            bol[f][c] = true;
            if(tauler[f][c] == 'p') return dist[f][c];

            for(int k = 0; k < dir_cavall; ++k){
                int ii = f + kx[k];
                int jj = c + ky[k];
                if(pos_ok(ii, jj, n, m, tauler)){
                    q.push({ii, jj});
                    dist[ii][jj] = dist[f][c] + 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        MC tauler(n, VC(m));

        //lectura
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> tauler[i][j];
            }
        }

        int f0, c0;
        cin >> f0 >> c0;
        MB bol(n, VB(m, false));

        int result = bfs(n, m, tauler, bol, f0 - 1, c0 - 1);
        if(result == 0) cout << "no" << endl;
        else cout << result << endl;
    }
}
