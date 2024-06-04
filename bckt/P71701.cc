#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VC;
typedef vector<VC> MC;

typedef vector<bool> VB;
typedef vector<VB> MB;

const int n_dirs = 8;
//las primeras cuatro son las basicas, las 4 ultimas las diagonales
int dx[n_dirs] = {-1, 1, 0, 0, -1, 1, 1, -1}; //filas
int dy[n_dirs] = {0, 0, -1, 1, 1, 1, -1, -1}; //columnas

bool pos_ok(int n, int m, int i, int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

bool posible(const MB& bol, int f, int c){
    //int f, c és la posicio actual en el tauler
    int n = bol.size();
    int m = bol[0].size();

    if(bol[f][c]) return false;
    for(int i = 0; i < n_dirs; ++i){
        int ii = f + dx[i];
        int jj = c + dy[i];
        if(pos_ok(n, m, ii, jj) and bol[ii][jj]){
            return false; //posicion insegura
        }
    }
    return true; //posicion segura
}

void escriure(const MB& bol){
    int n = bol.size();
    int m = bol[0].size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(bol[i][j]){
                cout << 'K';
            }
            else cout << '.';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

void prin(int& r, MB& bol, int k, int x, int y){
    int n = bol.size();

    if(k == r){ //se han podido poner o el grafo esta vacio
        escriure(bol);
    }
    else{
        bool primer = true;
        for(int i = x; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(primer){ //se hace para empezar a buscar desde la ultima posicion del rey
                    j = y;
                    primer = false;
                }
                if(posible(bol, i, j)){
                    bol[i][j] = true; //poner rei
                    prin(r, bol, k+1, i, j); // se pone i,j para no volver a comprobar ya las hechas
                    bol[i][j] = false; //sin rei
                }
            }
        }
    }
}

void func(int n, int r){
    MB bol(n, VB(n, false));
    prin(r, bol, 0, 0, 0); //r, bol, contador reyes, bucle 1, bucle 2
}

int main(){
    int n, r; //taulers n x n, r reis
    cin >> n >> r;
    func(n, r);
}