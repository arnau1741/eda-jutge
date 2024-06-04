#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INFINITY = numeric_limits<int>::max();
typedef pair <double, int> ArcP;
typedef vector<vector<ArcP>> Graf;

void dijkstra(const Graf& g, int s, vector<double>& dist, vector<int>& prev){
    int n = g.size();
    dist = vector<double>(n, INFINITY);
    dist[s] = 0;
    prev = vector<int>(n, -1);
    vector<bool> S(n, false);
    priority_queue<ArcP, vector<ArcP>, greater<ArcP>> q;
    q.push(ArcP(0, s));

    while(not q.empty()){
        int u = q.top().second; q.pop();
        if(not S[u]){
            S[u] = true;
            for(int i = 0; i < int(g[u].size()); ++i){
                int v = g[u][i].first;
                int c = g[u][i].second;
                if(dist[v] > dist[u] + c){
                    dist[v] = dist[u] + c;
                    prev[v] = u;
                    q.push(ArcP(dist[v], v));
                }
            }
        }
    }

}

int main(){
    int n, m;
    while(cin >> n >> m){
        Graf g(n);
        for(int i = 0; i < m; ++i){ //lectura de casos
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back({v, c});
        }
        int x, y;
        cin >> x >> y;
        vector<double> dist;
        vector<int> prev;
        dijkstra(g, x, dist, prev);
        vector<int> v;
        if(dist[y] == INFINITY) cout << "no path from " << x << " to " << y;
        else{
            for(int i = y; i != x; i = prev[i]){
                v.push_back(i);
            }
            v.push_back(x);
            bool first = true;
            for(int i = v.size()-1; i >= 0; --i){
                if(first){
                    cout << v[i];
                    first = false;
                }
                else{
                    cout << ' ' << v[i];
                }
            }
        }
        cout << endl;
    }
}

