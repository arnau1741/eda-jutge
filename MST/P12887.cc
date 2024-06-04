#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int trees(const vector<vector<P>>& Graf, int n){
    vector<bool> vis(n, false);
    vis[0] = true;
    priority_queue<P, vector<P>, greater<P>> pq;
    for(P x : Graf[0]) pq.push(x);
    int sz = 1;
    int sum = 0;
    while(sz < n){
        int c = pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if(not vis[x]){
            vis[x] = true;
            for(P y : Graf[x]) pq.push(y);
            sum += c;
            ++sz;
        }
    }
    return sum;
}

void lectura(vector<vector<P>>& Graf, int m){
    int n = Graf.size();
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        Graf[u - 1].push_back({w, v - 1});
        Graf[v - 1].push_back({w, u - 1});
    }
}


int main(){
    int n, m;
    while(cin >> n >> m){
        vector<vector<P>> Graf(n);
        lectura(Graf, m);
        int peso = trees(Graf, n);
        cout << peso << endl;
    }
}

