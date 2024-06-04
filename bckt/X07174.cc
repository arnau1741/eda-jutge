#include <iostream>
#include <vector>
using namespace std;

bool comproba(int num, const vector<int>& div) {
    int m = div.size();
    for (int i = 0; i < m; ++i) {
        if (num % div[i] == 0) return false; //si es multiple
    }
    return true;
}

void func(const int& n, const vector<int>& divisors, vector<int>& sol, int index, int num){
    if(index == n){
        for(int i = 0; i < n; ++i) cout << sol[i];
        cout << endl;
    }
    else{
        for(int i = 0; i < 10; ++i){
            sol[index] = i;
            if(comproba(num*10 + i, divisors)) func(n, divisors, sol, index + 1, num*10+i);
        }
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector<int> divisors(m);
        for(int i = 0; i < divisors.size(); ++i){
            cin >> divisors[i]; 
        }
        vector<int> sol(n);
        func(n, divisors, sol, 0, 0);
        cout << "----------" << endl;
    }
}
