//
//  main.cpp
//  appGrafo
//
//  Created by Valeria Conde on 09/11/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

map<int, bool> visited;

// Complejidad: O(m)
void loadGraph(int n, int m, vector<vector<int>>& matriz, vector<vector<int>>& lista) {
    for(int i = 0; i < m; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        
        matriz[source][destination] = weight;
        matriz[destination][source] = weight;
        
        lista[source].push_back(destination);
        lista[destination].push_back(source);
    }
}

// Complejidad: O(n+m)
void DFS(vector<vector<int>>& graph, int s) {
    if(visited[s]) return;
    
    cout << s << endl;
    visited[s] = 1;
    for(int i = 1; i < graph.size(); i++) {
        if (graph[s][i] > 0 && !visited[i]) {
            DFS(graph, i);
        }
    }
}

// Complejidad: O(n+m)
void BFS(vector<vector<int>>& lista, int s) {
    queue<int> q;
    q.push(s);
    visited.clear();
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if(visited[node]) continue;
        visited[node] = 1;
        cout << node << endl;
        
        for (int hija : lista[node]) {
            if (!visited[hija]) {
                q.push(hija);
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    vector<vector<int>> lista(n+1, vector<int>());
    
    loadGraph(n, m, graph, lista);
    DFS(graph,s);
    BFS(lista, s);
    
    // 4 6 1 1 2 10 1 3 8 1 4 6 2 3 15 2 4 12 3 4 3
    
    return 0;
}
