#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pos;
typedef vector<vector<char>> MC;
typedef vector<vector<bool>> MB;
typedef vector<vector<int>> MI;

const int DX[4] = {1, 0, -1, 0};
const int DY[4] = {0, 1, 0, -1};
const int INF = 2e9;

bool pos_ok(int i, int j, int n, int m, const MC& g){
    return i >= 0 and i < n and j >= 0 and j < m and g[i][j] != 'X'; 
}

int bfs_segon(const MC& g, Pos origen){
    int f = g.size();
    int c = g[0].size();
    MB vis(f, vector<bool>(c, false));
    MI dist(f, vector<int>(c, INF));
    vector<int> distancies;
    dist[origen.first][origen.second] = 0;
    queue<Pos> q;
    q.push(origen);

    while(not q.empty()){
        Pos actual = q.front();
        int x = actual.first;
        int y = actual.second;
        q.pop();

        if(not vis[x][y]){
            vis[x][y] = true;
            
            if(g[x][y] == 't'){
                distancies.push_back(dist[x][y]); //añadimos a vector de distancias de tesoros encontrados
            }

            for(int k = 0; k < 4; ++k){
                int ii = x + DX[k];
                int jj = y + DY[k];
                if(pos_ok(ii, jj, f, c, g) and dist[ii][jj] == INF){
                    dist[ii][jj] = dist[x][y] + 1;
                    q.push({ii, jj});
                }
            }
        }
    }
    if(distancies.size() < 2) return -1;
    else return distancies[distancies.size() - 2];
}

int main(){
    int n, m;
    cin >> n >> m;
    MC tauler(n, vector<char>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> tauler[i][j];
        }
    }

    Pos origen;
    int ox, oy;
    cin >> ox >> oy;

    origen.first = ox - 1;
    origen.second = oy - 1;

    int result = bfs_segon(tauler, origen);
    if(result == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
    else cout << "segona distancia maxima: " << result << endl;
}