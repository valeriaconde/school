// Act4.3 main
// Valeria Conde

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

// string -> vector<string>
// lista["1123"] -> [ ]
map<string, vector<string>> lista;
vector<string> nodes;

int main(int argc, const char * argv[]) {
    ifstream arcEnt("bitacora.txt");
    
    int n, m;
    arcEnt >> n >> m;
    
    for(int i = 0; i < n; i++) {
        string node;
        arcEnt >> node;
        nodes.push_back(node);
    }
    
    for(int i = 0; i < m; i++) {
        string mes, dia, hora, source, dest, msg;
        arcEnt >> mes >> dia >> hora >> source >> dest;
        getline(arcEnt, msg);
        
        string sourceSinPuerto, destSinPuerto;
        sourceSinPuerto = source.substr(0, source.find(":", 0));
        destSinPuerto = dest.substr(0, dest.find(":", 0));
        
        lista[sourceSinPuerto].push_back(destSinPuerto);
    }
    
    int maxFanOut = 0;
    for(auto it : lista) {
        if(it.second.size() > maxFanOut) {
            maxFanOut = (int) it.second.size();
        }
    }
    
    cout << "Botmaster(s):\n";
    for(auto it : lista) {
        if(it.second.size() == maxFanOut) {
            cout << it.first << " " << it.second.size() << endl;
        }
    }
    cout << endl;
    
    arcEnt.close();
    
    return 0;
}
