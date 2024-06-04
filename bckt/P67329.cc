#include <iostream>
#include <vector>
using namespace std;

void escriu(const vector<char>& v){
    int n = v.size();

    for(int i = 0; i < n; ++i){
        cout << v[i];
    }
    cout << endl;
}

void func(int index, int n, vector<char>& lletres, vector<char>& sol){
    if(index == n){
        escriu(sol);
        return;
    }
    else{
        for(int i = 0; i < 4; ++i){
            sol[index] = lletres[i];
            func(index + 1, n, lletres, sol);
        }
    }
}

void lletreslectura(vector<char>& v){
    v[0] = 'A';
    v[1] = 'C';
    v[2] = 'G';
    v[3] = 'T';
}

int main(){
    int n;
    cin >> n;
    vector<char> sol(n);
    vector<char> lletres(4);

    lletreslectura(lletres);

    func(0, n, lletres, sol);
}
