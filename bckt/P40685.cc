#include <iostream>
#include <vector>
using namespace std;

void lectura(vector<int>& valors){
    for(int i = 0; i < valors.size(); ++i){
        cin >> valors[i];
    }
}

void escriure(const vector<bool>& sol, const vector<int>& v, int n){
    cout << '{';
    bool primer = true;
    for(int i = 0; i < n; ++i){
        if(sol[i]){
            if(primer) primer = false;
            else{
                cout << ',';
            } 
            cout << v[i];
        }
    }
    cout << '}' << endl;
}

void func(const vector<int>& v, int n, int s_total, vector<bool>& sol, int i, int suma){
    if(i == n){
        if(s_total == suma) escriure(sol, v, n);
    }
    else{
        sol[i] = false; //no lo cojo
        func(v, n, s_total, sol, i+1, suma);

        sol[i] = true;
        func(v, n, s_total, sol, i+1, suma + v[i]);
    }
}

int main(){
    int valor_def;
    cin >> valor_def;

    int n;
    cin >> n;
    vector<int> valors(n);

    lectura(valors);

    vector<bool> sol(n);

    func(valors, n, valor_def, sol, 0, 0);
}