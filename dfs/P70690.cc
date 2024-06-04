#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int n_dirs = 4;
const int DI[n_dirs] = {1, 0, -1, 0};
const int DJ[n_dirs] = {0, 1, 0, -1};

bool ok(int n, int m, int i, int j){ //dentro de rango
    return 0 <= i and i < n and 0 <= j and j < m;
}

bool search(const MC& mat, int n, int m, int i, int j, MB& bol){
    if(not bol[i][j]){
        bol[i][j] = true;
        if(mat[i][j] == 't') return true;
        for(int k = 0; k < n_dirs; ++k){ //comprobar direcciones
            int ii = i + DI[k];
            int jj = j + DJ[k];
            if(ok(n, m, ii, jj) and mat[ii][jj] != 'X'){
                if(search(mat, n, m, ii, jj, bol)) return true;
            }
        }
    }
    return false;
}

//X = no se puede pasar
//t = tresor

int main(){
    int n, m; //tamaÃ±os matriz
    cin >> n >> m;
    MC mat(n, VC(m)); //tauler
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> mat[i][j];
        }
    }

    int f, c; //posicions inicials
    cin >> f >> c;

    MB bol(n, VB(m, false)); //bools visitats

    if(search(mat, n, m, f-1, c-1, bol)) cout << "yes" << endl;
    else cout << "no" << endl;
}

