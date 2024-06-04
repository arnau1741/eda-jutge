#include <iostream>
#include <vector>
using namespace std;

bool usat(const vector<char>& sol, char c, int idx){
    for(int i = 0; i < idx; ++i){
        if(sol[i] == c) return true;
    }
    return false;
}

void func(int n, vector<char>& sol, const vector<char>& alf, int index){
    if(index == n){
        for(char x : sol){
            cout << x;
        }
        cout << endl;
    }
    else{
        for(char c : alf){
            if(not usat(sol, c, index)){
                // no permetem que y estigui immediatament a la dreta de x i y sigui la lletra següent a x dins de l'alfabet
                if(sol.size() == 0){
                    sol[index] = c;
                    func(n, sol, alf, index);
                }
                else{
                    if(sol[index - 1] != char(c - 1)){
                        sol[index] = c;
                        func(n, sol, alf, index + 1);
                    } 
                }
                //else escogera la siguiente letra
            }
        }
    }
}

void lletres(vector<char>& alf, int n){
    char a = 'a';
    for(int i = 0; i < n; ++i){
        alf.push_back(a + i);
    }
}

void func(int n){
    vector<char> sol(n);
    vector<char> alf;
    lletres(alf, n);
    func(n, sol, alf, 0);
}

int main(){
    int n;
    cin >> n;
    func(n);
}