#include <vector>
#include <iostream>
#include <functional>
using namespace std;


bool isRootedTree(int vi, vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    // 计算每个节点的入度
    for (int v = 0; v < n; ++v) {
        for (int u : graph[v]) {
            inDegree[u]++;
        }
    }
    //验证入度
    if(inDegree[vi] != 0) return false;
    
    for(int i = 0; i < n; ++i) {
        if(i != vi && inDegree[i] != 1) return false;
    }

    //检查连通性，以保证是树而不是森林
    vector<bool> visited(n, false);
   
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    };
    dfs(vi);

    for(bool v : visited) {
        if(!v) return false;
    }
    return true;
}
