#include <iostream>
#include <vector>
using namespace std;

void prog(vector<int>& v, int idx){
    if(v.size() == idx){
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
        return;
    }
    else{
        v[idx] = 0;
        prog(v, idx + 1);

        v[idx] = 1;
        prog(v, idx + 1);
    }
}

void func(int n){
    vector<int> v(n);
    prog(v, 0);
}

int main(){
    int n;
    cin >> n;
    func(n);
}