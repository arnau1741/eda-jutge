#include <iostream>
#include <vector>
using namespace std;

void prog(vector<int>& v, int idx, int m, int uns, int zeros){
    if(v.size() == idx){
        if(uns == m){
            bool first = true; 
            for(int x : v){
                if(first){
                    cout << x;
                    first = false;
                }
                else{
                    cout << ' ' << x;
                }
            }
            cout << endl;
        }
        return;
    }
    else{
        if(zeros < v.size() - m){
            v[idx] = 0;
            prog(v, idx + 1, m, uns, zeros + 1);
        }
        if(uns < m){
            v[idx] = 1;
            prog(v, idx + 1, m, uns + 1, zeros);
        }
    }
}

void func(int n, int m){
    vector<int> v(n);
    //vector, indice, cantidad 1, cantidad de unos, cantidad de ceros
    prog(v, 0, m, 0, 0);
}

int main(){
    int n, m;
    cin >> n >> m;
    func(n, m);
}