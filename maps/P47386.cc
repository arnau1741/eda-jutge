#include<iostream>
#include<set>
using namespace std;

void escriure(const set<pair<string, string>>& liats, const set<string>& sols){
    cout << "PARELLES:" << endl;
    for(const auto& p : liats){
        cout << p.first << ' ' << p.second << endl;
    }

    cout << "SOLS:" << endl;
    for(const auto& s : sols){
        cout << s << endl;
    }
    cout << "----------" << endl;
}

void buscar_pareja(set<pair<string, string>>& liats, set<string>& sols, string nom){
    set<pair<string, string>>::const_iterator it = liats.begin();
    while(it != liats.end()){
        if(it->first == nom){
            sols.insert({it->second});
            liats.erase(it);
            return;
        }
        else if(it->second == nom){
            sols.insert({it->first});
            liats.erase(it);
            return;
        }
        else{
            ++it;
        }
    }
}

int main(){
    string inst, nom1, nom2;
    
    set<pair<string, string>> liats;
    set<string> sols;

    while(cin >> inst){
        if(inst == "liats"){
            cin >> nom1 >> nom2; //los que se lian
            //eliminarlos de la lista de solos si lo estan
            if(sols.find(nom1) != sols.end()) sols.erase(nom1);
            if(sols.find(nom2) != sols.end()) sols.erase(nom2);
            //buscar si ya tienen pareja y enviar a la segunda a sols o al re y borrar vieja parejaves
            buscar_pareja(liats, sols, nom1);
            buscar_pareja(liats, sols, nom2);
            //añadirlos como pareja
            if(nom1 < nom2) liats.insert({nom1, nom2});
            else liats.insert({nom2, nom1});
        }
        else if(inst == "info"){    
            escriure(liats, sols);
        }
    }
}