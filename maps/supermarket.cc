#include<iostream>
#include<map>
#include<queue>
#include<sstream>

using namespace std;

void lectura(int cues, map<int, queue<string>>& m){
    string clients;
    getline(cin, clients);
    for(int i = 0; i < cues; ++i){
        string s; 
        getline(cin ,s);
        istringstream ss(s);
        string x;
        queue<string> q;
        while(ss >> x){
            q.push(x);
        }
        m[i] = q;
    }
}

void escriure(const vector<string>& sortides, const map<int, queue<string>>& m){
    cout << "SORTIDES" << endl;
    cout << "--------" << endl;

    for(int i = 0; i < sortides.size(); ++i){
        cout << sortides[i] << endl;
    }

    cout << endl;

    cout << "CONTINGUTS FINALS" << endl;
    cout << "-----------------" << endl;

    map<int, queue<string>>::const_iterator it = m.begin();
    for(; it != m.end(); ++it){ //iteramos sobre las colas
        cout << "cua " << it->first + 1 << ":";
        bool first = true;
        queue<string> q = it->second;
        if(q.empty()){
            cout << endl;
            continue;
        }
        while(not q.empty()){
            if(first){
                cout << ' ';
                cout << q.front();
                first = false;
            }
            else{
                cout << ' ' << q.front();
            }
            q.pop();
        }
        cout << endl;
    }

}

int main(){
    int cues;
    cin >> cues;
    map<int, queue<string>> m;

    lectura(cues, m);

    /*Un client arriba a una cua: Si la cua està entre 1 i n, el client entra a la cua. Altrament, el succés s’ignora.
    Un client surt d’una cua: Si la cua està entre 1 i n, i la cua no és buida, el primer client de la cua surt. Altrament, el succés s’ignora.*/

    vector<string> sortides;

    string inst;
    string nombre;
    int numero; 

    while(cin >> inst){
        if(inst == "SURT"){
            cin >> numero;
            if(numero - 1 <= cues - 1 and numero - 1 >= 0){ //existeix
                if(not m[numero - 1].empty()){
                    sortides.push_back(m[numero - 1].front());
                    m[numero - 1].pop();
                }
            }
        }
        else if(inst == "ENTRA"){
            cin >> nombre >> numero;
            if(numero - 1 <= cues - 1 and numero - 1 >= 0){ //existeix
                m[numero - 1].push(nombre);
            }
        }
    }
    escriure(sortides, m);
}