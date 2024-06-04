#include <iostream>
#include <vector>
using namespace std;

void prog(vector<string>& utiltzat, vector<string>& result, int idx){
    if(utiltzat.size() == idx){
        cout << "(";
        bool first = true;
        for(string x : result){
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
        int n = utiltzat.size();
        for(int i = 0; i < n; ++i){ //comprobar numeros a posar
            bool usat = false;
            for(int j = 0; j < idx and not usat; ++j){ //comprobar si el valor ha sido utilizado
                if(result[j] == utiltzat[i]) usat = true;
            }
            if(not usat){
                result[idx] = utiltzat[i];
                prog(utiltzat, result, idx + 1);
            }
        }
    }
}

void func(vector<string>& v){
    vector<string> result(v.size());
    prog(v, result, 0);
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    string p;
    for(int i = 0; i < n; ++i){
        cin >> p;
        v[i] = p;
    }
    func(v);
}