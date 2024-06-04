#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> MC;
typedef vector<vector<bool>> MB;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool pos_ok(int i, int j, int n, int m){
    return i>=0 and i<n and j>=0 and j<m;
}

void escriure(const MB& bol){
    int n = bol.size();
    int m = bol[0].size();

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(bol[i][j]) cout << 'R';
            else cout << '.';;
        }
        cout << endl;
    }
    cout << endl;
}

bool posible(const MB& bol, int i, int j){
    int n = bol.size();
    int m = bol[0].size();

    if(bol[i][j]) return false;

    // Verificar fila
    for(int k = 0; k < m; ++k){
        if(bol[i][k] and pos_ok(i, k, n, m)) return false;
    }

    // Verificar columna
    for(int k = 0; k < n; ++k){
        if(bol[k][j] and pos_ok(i, k, n, m)) return false;
    }
    return true; //posicion segura
}

void func(int& max_torres, MB& bol, int torres, int i, int j){
    int n = bol.size();
    int m = bol[0].size();

    if(torres == max_torres){
        escriure(bol);
    }
    else{
        bool primer = true;
        for(int x = i; x < n; ++x){
            for(int y = 0; y < m; ++y){
                if(posible(bol, x, y)){
                    bol[x][y] = true;
                    func(max_torres, bol, torres + 1, x, y);
                    bol[x][y] = false;
                }
            }
        }
    }
}

void func(int max_torres, int f, int c){
    MB bol(f, vector<bool>(c, false));
    func(max_torres, bol, 0, 0, 0); //num max torres, bol, torres, i, j
}

int main(){
    int n, m;
    cin >> n >> m;
    func(n, n, m);
}
