#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> tauler;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int n_dirs = 4;
const int dx[n_dirs] = {-1, 1, 0, 0};
const int dy[n_dirs] = {0, 0, 1, -1};

bool pos_ok(int i, int j, int n, int m){
    return i < n and i >= 0 and j < m and j >= 0; 
}

bool adyacente(int ii, int jj, const tauler& graf){
    int n = graf.size();
    int m = graf[0].size();
    for(int k = 0; k < 4; ++k){
        int SI = ii + dx[k];
        int SJ = jj + dy[k];
        if(pos_ok(SI, SJ, n, m)){
            if(graf[SI][SJ] == 'M') return true;
        }
    }
    return false;
}


bool dfs(int f0, int c0, int f1, int c1, const tauler& graf, MB& bol){
    int n = graf.size();
    int m = graf[0].size();
    if(not bol[f0][c0]){
        bol[f0][c0] = true;
        if(f0 == f1 and c0 == c1){
            return true;
        }
        for(int k = 0; k < 4; ++k){
            int ii = f0 + dx[k];
            int jj = c0 + dy[k];
            if(pos_ok(ii, jj, n, m) and not adyacente(ii, jj, graf)){
                if(dfs(ii, jj, f1, c1, graf, bol)) return true;
            }
        }
    }
    return false;
}

void lectura(tauler& graf, int& f0, int& c0, int& f1, int& c1){
    int n = graf.size();
    int m = graf[0].size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c; 
            graf[i][j] = c;
            if(c == 'I'){
                f0 = i;
                c0 = j;
            }
            else if(c == 'F'){
                f1 = i;
                c1 = j;
            }
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        tauler graf(n, VC(m));
        int f0, c0, f1, c1;
        f0 = c0 = f1 = c1 = -1;
        lectura(graf, f0, c0, f1, c1);

        MB bol(n, VB(m, false));
        
        if(dfs(f0, c0, f1, c1, graf, bol)) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}
