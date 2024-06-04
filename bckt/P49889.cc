#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> VI;

void lectura(VI& cons, VI& voc, const int& n){
    for(int i = 0; i < n; ++i){
        cin >> cons[i];
    }

    for(int i = 0; i < n; ++i){
        cin >> voc[i];
    }
}

bool contiene(VI& res, char letter, int index){
    for (int i = 0; i < index; ++i) {
        if (res[i] == letter) {
            return true;
        }
    }
    return false;
}

void func(int index, VI& result, VI& cons, VI& voc){
    if(index == result.size()){
        for(char c : result){
            cout << c;
        }
        cout << endl;
        return;
    }
    else{ //comenzar en consonante y luego turnarse entre cons y voc
        int n = result.size();
        if(index % 2 == 0){ //consonante
            for(char c : cons){
                if(not contiene(result, c, index)){
                    result[index] = c;
                    func(index + 1, result, cons, voc);
                }
            }
        }
        else{ //vocal
            for(char v : voc){
                if(not contiene(result, v, index)){
                    result[index] = v;
                    func(index + 1, result, cons, voc);
                }
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    VI cons(n);
    VI voc(n);

    lectura(cons, voc, n);

    VI res(2*n);

    func(0, res, cons, voc);
}