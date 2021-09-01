//
//  main.cpp
//  Grafos
//
//  Created by Valeria Conde on 06/11/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

/*
 N M
 3 3
 0 1
 1 2
 0 2
 0
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, bool> vis;

void dfs(int node, vector<vector<int>> graph) {
    if(vis[node]) return;
    
    cout << node << endl;
    vis[node] = true;
    
    for(auto hijo : graph[node]) {
        dfs(hijo, graph);
    }
}

int main(int argc, const char * argv[]) {
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N);
    
    for(int i = 0; i < M; i++) {
        int source, dest;
        cin >> source >> dest;
        
        graph[source].push_back(dest);
    }
    
    for(int i = 0; i < N; i++) {
        dfs(i, graph);
    }
    
    return 0;
}
