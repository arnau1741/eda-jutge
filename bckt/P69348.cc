#include <iostream>
#include <vector>
using namespace std;

void prog(vector<int>& v, int idx){
    if(v.size() == idx){
        cout << "(";
        bool first = true;
        for(int x : v){
            if(first){
                cout << x;
                first = false;
            }
            else{
                cout << "," << x;
            }
        }
        cout << ")" << endl;
    }
    else{
        int n = v.size();
        for(int i = 1; i <= n; ++i){ //comprobar numeros a posar
            bool usat = false;
            for(int j = 0; j < idx; ++j){ //comprobar si el valor ha sido utilizado
                if(v[j] == i) usat = true;
            }
            if(not usat){
                v[idx] = i;
                prog(v, idx + 1);
            }
        }
    }
}

void func(int n){
    vector<int> v(n);
    //vector, indice, cantidad 1, cantidad de unos, cantidad de ceros
    prog(v, 0);
}

int main(){
    int n;
    cin >> n;
    func(n);
}