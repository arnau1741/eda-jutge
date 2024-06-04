#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int n_dirs = 4;
const int DI[n_dirs] = {1, 0, -1, 0};
const int DJ[n_dirs] = {0, 1, 0, -1};

void lectura(MC& graf){
    int n = graf.size();
    int m = graf[0].size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            graf[i][j] = c;
        }
    }
}

bool ok(int n, int m, int i, int j){ //dentro de rango
    return 0 <= i and i < n and 0 <= j and j < m;
}

void escriure(const vector<char>& cami){
    int n = cami.size();
    for(int i = 0; i < n; ++i){
        cout << cami[i];
    }
    cout << endl;
}

void dfs(const MC& graf, MB& bol, int f0, int c0, int f1, int c1, vector<char>& cami){
    //f0, c0 es la posicio inicial
    //f1, c1 es la posicio final
    int n = graf.size();
    int m = graf[0].size();
    if(not bol[f0][c0]){
        bol[f0][c0] = true;
        if(f0 == f1 and c0 == c1){
            for(char i : cami){
                cout << i;
            }
            cout << endl;
        }
        for(int i = 0; i < n_dirs; ++i){
            int ii = f0 + DI[i];
            int jj = c0 + DJ[i];
            if(ok(n, m, ii, jj)){
                cami.push_back(graf[ii][jj]);
                dfs(graf, bol, ii, jj, f1, c1, cami);
                cami.pop_back();
            }
        }
        //para poder visitarla por otro camino
        bol[f0][c0] = false;
    }
    return;
}

int main(){
    int i, j;
    cin >> i >> j;
    MC graf(i, VC(j));

    lectura(graf);

    int f0, c0, f1, c1;
    cin >> f0 >> c0 >> f1 >> c1;

    MB bol(i, VB(j, false));

    vector<char> cami;
    cami.push_back(graf[f0][c0]);
    
    dfs(graf, bol, f0, c0, f1, c1, cami);
}