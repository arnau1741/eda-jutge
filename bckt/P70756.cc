#include <iostream>
#include <vector>
using namespace std;

typedef vector<string> VI;

void lectura(VI& cas){
    for(int i = 0; i < cas.size(); ++i){
        cin >> cas[i];
    }
}

void escriure(const vector<string>& pal, const vector<int>& sol, int n, int p){
    for (int i = 0; i < p; ++i) {
		cout << "subconjunt " << i+1 << ": {";
		bool primer = true;
		for (int j = 0; j < n; ++j){
			if (sol[j] == i){
				if (primer) primer = false;
				else cout << ','; 
				cout << pal[j];
			}
		}
		cout << "}" << endl;
	}
	cout << endl;
}

void func(const int& p, vector<string>& pal, int n, int index, vector<int>& sol){
    if(index == n){
        escriure(pal, sol, n, p);
    }
    else{
        for(int j = 0; j < p; ++j){
            sol[index] = j;
            func(p, pal, n, index + 1, sol);
        }
    }
}

int main(){
    int n; 
    cin >> n;

    VI pal(n);
    lectura(pal);

    int p;
    cin >> p;
    vector<int> sol(n);

    func(p, pal, n, 0, sol);

}