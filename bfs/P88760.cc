#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool canJump(const Point& p1, double r1, const Point& p2, double r2, double d) {
    return distance(p1, p2) - r1 - r2 <= d;
}

int func(const vector<pair<Point, double>>& p, 
const int& d){
    int n = p.size();
    queue<pair<int, int>> q;
    vector<bool> visited(n);
    q.push({0, 0});
    while(not q.empty()){
        int index = q.front().first;
        int jumps = q.front().second;
        q.pop();
        if(not visited[index]){
            if(index == n-1) return jumps;
            visited[index] = true;
            for(int i = 0; i < n; ++i){
                if(not visited[i] and canJump(p[index].first, p[index].second, p[i].first, p[i].second, d)){
                    q.push({i, jumps + 1});
                }                
            }
        }
    }
    return -1;
}

int main(){
    int n;
    double d;
    while(cin >> n >> d){ //casos
        vector<pair<Point, double>> p;
        for(int i = 0; i < n; ++i){ //lectura piedras
            double x, y, r;
            cin >> x >> y >> r;
            Point t;
            t.x = x;
            t.y = y;
            p.push_back({t, r});
        }
        int result = func(p, d);
        if(result == -1) cout << "Xof!" << endl;
        else{
            cout << result << endl;
        }
    }    
}