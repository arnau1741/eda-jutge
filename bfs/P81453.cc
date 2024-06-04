#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> matriz;

vector<int> bfs(const matriz& mat, const int& n) {
    queue<pair<int,vector<int>>> Q;
    vector<int> vis(n, false);
    int dist_max = 1000000;
    vector<int> cami_curt;
    Q.push({0,{0}});
    while (not Q.empty()) {
        int u = Q.front().first;
        vector<int> cami = Q.front().second;
        Q.pop();
        if (u == n-1) {
            if (cami.size() < dist_max or (cami.size() == dist_max and cami < cami_curt)) {
                dist_max = cami.size();
                cami_curt = cami;
            }
        }
        else {
            vis[u] = true;
            for (int j = 0; j < mat[u].size(); ++j) {
                if (vis[mat[u][j]] == false) {
                    vector<int> aux = cami;
                    aux.push_back({mat[u][j]});
                    Q.push({mat[u][j], aux});
                }
            }
        }
    }
    if (dist_max != 1000000) return cami_curt;
    else return {-1};
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        matriz mat(n);
        int x, y;
        for (int i = 0; i < m; ++i) {
            cin >> x >> y;
            mat[x].push_back(y);
        }
        vector<int> cami_curt = bfs(mat, n);
        int mida = cami_curt.size();
        if (mida != 1) {
            for (int i = 0; i < mida; ++i) {
                if (i == 0) cout << cami_curt[i];
                else cout << ' ' << cami_curt[i];
            }
        }
        cout << endl;
    }

}