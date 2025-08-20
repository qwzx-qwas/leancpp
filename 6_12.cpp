#include <iostream>
#include <vector>
using namespace std;

bool dfs (int u, int target, vector<vector<int>>& graph, vector<bool>& visited) {
    if (u == target) return true; // 找到目标节点
    visited[u] = true; // 标记当前节点为已访问

    for (int v : graph[u]) { // 遍历所有邻接节点
        if (!visited[v] && dfs(v, target, graph, visited)) {
            return true; // 如果找到目标节点，返回 true
        }
    }
    return false; // 没有找到目标节点
}


bool hasPath (vector<vector<int>>& graph, int vi, int vj) {
    int n = graph.size();
    vector<bool> visited(n, false); // 初始化访问标记
    return dfs(vi, vj, graph, visited);
}

int main() {
    int n = 6; // 顶点数：0..5
    vector<vector<int>> graph(n);

    // 添加边 (有向图)
    graph[0] = {1, 2};  // 0 -> 1, 0 -> 2
    graph[1] = {3};     // 1 -> 3
    graph[2] = {4};     // 2 -> 4
    graph[4] = {5};     // 4 -> 5

    int vi = 0, vj = 5;
    if (hasPath(graph, vi, vj)) {
        cout << "存在路径" << endl;
    } else {
        cout << "不存在路径" << endl;
    }

    return 0;
}
