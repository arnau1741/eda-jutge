#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int DI[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DJ[8] = {0, 1, 0, -1, 1, -1, 1, -1};

bool pos_ok(int n, int m, int i, int j, const MC& mat){
    return i < n and j < m and 0 <= i and 0 <= j and mat[i][j] != 'X';
}

bool adyacente(int n, int m, int i, int j, const MC& mat){
    for(int a = 0; a < 8; ++a){
        int ii = i + DI[a];
        int jj = j + DJ[a];
        if(pos_ok(n, m, ii, jj, mat)){
            if(mat[ii][jj] == 'F'){
                return true;
            }
        } 
    }
    return false;
}

bool dfs(int i, int j, int n, int m, const MC& mat, MB& bol){
    if(not bol[i][j]){
        bol[i][j] = true;
        if(mat[i][j] == 'B') return true;
        for(int a = 0; a < 4; ++a){
            int ii = i + DI[a];
            int jj = j + DJ[a];
            if(pos_ok(n, m, ii, jj, mat) and !adyacente(n, m, ii, jj, mat)){
                if(dfs(ii, jj, n, m, mat, bol)) return true;
            }
        }
    }
    return false;
}

int main(){
    int n, m;
    int a, b;
    while(cin >> n >> m){
        MC mat(n, VC(m));
        MB bol(n, VB(m, false));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                char c;
                cin >> c;
                mat[i][j] = c;
                if(c == 'P'){
                    a = i;
                    b = j;
                }
            }
        }
        
        if(not adyacente(n, m, a, b, mat) and dfs(a, b, n, m, mat, bol)){
            cout << "yes" << endl;
        }
        else cout << "no" << endl;
    }
}