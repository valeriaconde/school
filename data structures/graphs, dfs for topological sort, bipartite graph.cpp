//
//  main.cpp
//  appGrafo2
//
//  Created by Valeria Conde on 15/11/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
// 4 6 1 1 2 10 1 3 8 1 4 6 2 3 15 2 4 12 3 4 3
vector<int> inDegree;
vector<int> color;
map<int, bool> visited;
bool hasCycle = 0;

// Complejidad: O(m)
void loadGraph(int n, int m, vector<vector<int>>& lista) {
    for(int i = 0; i < m; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        source--;
        destination--;
        inDegree[destination]++;

        lista[source].push_back(destination);
    }
}

// DFS to check if its tree
void DFS(int node, vector<vector<int>>& lista) {
    visited[node] = 1;

    for (int hijo : lista[node]) {
        if(!visited[hijo]) DFS(hijo, lista);
        else hasCycle = 1;
    }
}

// Complejidad: O(n)
bool isTree(int n, int m, vector<vector<int>>& lista) {
    bool hasZero = 0;
    int root = -1;
    
    // checks inDegree of nodes
    for(int i = 0; i < n; i++) {
        if(inDegree[i] == 0 && hasZero) return 0;
        if(inDegree[i] == 0 && !hasZero) {
            hasZero = 1;
            root = i;
        }
        if(inDegree[i] > 1) return 0;
    }
    
    visited.clear();
    DFS(root, lista);
    
    // checks if visited during DFS
    for (int i = 0; i < n; i++) {
        if(!visited[i]) return 0;
    }

    // checks for cycle
    if(hasCycle) return 0;
    
    return 1;
}

// DFS for topological sort
void DFS(int node, stack<int>& st, vector<vector<int>>& lista) {
    visited[node] = 1;

    for (int hijo : lista[node]) {
        if(!visited[hijo]) DFS(hijo, st, lista);
    }
    st.push(node);
}

// Complejidad: O(n)
void topological(int n, int m, vector<vector<int>>& lista) {
    stack<int> st;
    visited.clear();
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) DFS(i, st, lista);
    }
    
    while(!st.empty()) {
        cout << st.top() + 1 << " ";
        st.pop();
    }
    cout << endl;
}

// DFS for bipartite graph
bool bpDFS(int node, vector<vector<int>>& lista) {
    visited[node] = 1;
    for(int hijo : lista[node]) {
        if(visited[hijo]) {
            if(color[hijo] == color[node]) return 0;
        } else {
            color[hijo] = !color[node];
            if(!bpDFS(hijo, lista)) return 0;
        }
    }
    return 1;
}

// Complejidad: O(n)
bool bipartiteGraph(int n, int m, vector<vector<int>>& lista) {
    visited.clear();
    color[0] = 0;
    visited[0] = 1;
    return bpDFS(0, lista);
}


int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    inDegree.resize(n, 0);
    color.resize(n);
    vector<vector<int>> lista(n, vector<int>());
    
    loadGraph(n, m, lista);
    cout << isTree(n, m, lista) << endl;
    topological(n, m, lista);
    cout << bipartiteGraph(n, m, lista) << endl;
    
    
    return 0;
}
