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

const int dir_alfil = 4;
const int bx[dir_alfil] = {-1, -1, 1, 1};
const int by[dir_alfil] = {-1, 1, 1, -1};

void lectura(MC& Graf, const int& n, const int& m, vector<pair<char, pair<int, int>>>& fiches){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            Graf[i][j] = c;
            if(c == 'K' or c == 'B'){
                fiches.push_back(make_pair(c, make_pair(i, j)));
            }
        }
    }
}

bool pos_ok(int i, int j, int n, int m, const MC& Graf){
    return i >= 0 and i < n and j >= 0 and j < m and Graf[i][j] != 'T';
}

void bfs_b(MC& Graf, MB& bol, int f0, int c0, int n, int m, int& sum){ //grafo, bools, posicion inicial (f0, c0), tipo de ficha
    queue<pair<int, int>> q;
    q.push({f0, c0});
    while(not q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(not bol[i][j]){
            bol[i][j] = true;

            if(Graf[i][j] != 'T' and Graf[i][j] != '.' and Graf[i][j] != 'K' and Graf[i][j] != 'B'){
                sum += (Graf[i][j] - '0');
                Graf[i][j] = '.'; //quitamos la moneda si ya la hemos cogido
            }

            for(int a = 0; a < dir_alfil; ++a){
                int ii = i + bx[a];
                int jj = j + by[a];
                if(pos_ok(ii, jj, n, m, Graf) and not bol[ii][jj]){
                    q.push({ii, jj});
                }
            }
        }
    }
}

void bfs_k(MC& Graf, MB& bol, int f0, int c0, int n, int m, int& sum){ //grafo, bools, posicion inicial (f0, c0), tipo de ficha
    queue<pair<int, int>> q;
    q.push({f0, c0});
    while(not q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(not bol[i][j]){
            bol[i][j] = true;

            if(Graf[i][j] != 'T' and Graf[i][j] != '.' and Graf[i][j] != 'K' and Graf[i][j] != 'B'){
                sum += (Graf[i][j] - '0');
                Graf[i][j] = '.'; //quitamos la moneda si ya la hemos cogido
            }

            for(int a = 0; a < dir_cavall; ++a){
                int ii = i + kx[a];
                int jj = j + ky[a];
                if(pos_ok(ii, jj, n, m, Graf) and not bol[ii][jj]){
                    q.push({ii, jj});
                }
            }
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        MC Graf(n, VC(m));
        
        vector<pair<char, pair<int, int>>> fiches;

        lectura(Graf, n, m, fiches);

        int monedas = 0;

        MB bol_k(n, VB(m, false));
        MB bol_b(n, VB(m, false));
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(Graf[i][j] == 'B'){
                    bfs_b(Graf, bol_b, i, j, n, m, monedas);
                }
                else if(Graf[i][j] == 'K'){
                    bfs_k(Graf, bol_k, i, j, n, m, monedas);
                }
            }
        }
        cout << monedas << endl;
    }
}