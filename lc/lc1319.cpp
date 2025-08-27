#include <vector>
#include <iostream>
using namespace std;

class Djset {
private:
    vector<int> parent;  //记录父结点
    vector<int> rank;   //记录高度
    int count;          //记录独立的连通分量个数
    int rest;           //记录多余边数
public:
    Djset(int n): parent(n), rank(n,0),count(n),rest(0) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--; //每次成功链接两个独立的集合就-1
        } else {
            rest++;  //当我们尝试联通两个集合，但
                     //如果这俩集合已经联通，则多余边数+1
        }
    }

    int getCount() const {
        return count;
    }

    int getRest() const {
        return rest;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; //边数不够，直接返回-1

        Djset djs(n);
        for (const auto& conn : connections) {
            djs.unite(conn[0], conn[1]);
        }
        if (djs.getRest() < djs.getCount() - 1) return -1; //如果链接需要的边数大于多余边数，返回-1
        return djs.getCount() - 1;
    }
};

// 辅助函数：打印二维vector
void printConnections(const vector<vector<int>>& connections) {
    cout << "[";
    for (int i = 0; i < connections.size(); i++) {
        cout << "[" << connections[i][0] << "," << connections[i][1] << "]";
        if (i < connections.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1：LeetCode官方示例1
    cout << "=== Test Case 1 ===" << endl;
    int n1 = 4;
    vector<vector<int>> connections1 = {{0,1},{0,2},{1,2}};
    cout << "Input: n = " << n1 << ", connections = ";
    printConnections(connections1);
    cout << endl;
    
    int result1 = solution.makeConnected(n1, connections1);
    cout << "Output: " << result1 << endl;
    cout << "Expected: 1" << endl;
    cout << "Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3." << endl << endl;
    
    // 测试用例2：LeetCode官方示例2
    cout << "=== Test Case 2 ===" << endl;
    int n2 = 6;
    vector<vector<int>> connections2 = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout << "Input: n = " << n2 << ", connections = ";
    printConnections(connections2);
    cout << endl;
    
    int result2 = solution.makeConnected(n2, connections2);
    cout << "Output: " << result2 << endl;
    cout << "Expected: 2" << endl;
    cout << "Explanation: We have 3 components and need 2 operations to connect them." << endl << endl;
    
    // 测试用例3：LeetCode官方示例3
    cout << "=== Test Case 3 ===" << endl;
    int n3 = 6;
    vector<vector<int>> connections3 = {{0,1},{0,2},{0,3},{1,2}};
    cout << "Input: n = " << n3 << ", connections = ";
    printConnections(connections3);
    cout << endl;
    
    int result3 = solution.makeConnected(n3, connections3);
    cout << "Output: " << result3 << endl;
    cout << "Expected: -1" << endl;
    cout << "Explanation: There are not enough cables." << endl << endl;
    
    // 测试用例4：已经全连通
    cout << "=== Test Case 4 (Already Connected) ===" << endl;
    int n4 = 4;
    vector<vector<int>> connections4 = {{0,1},{1,2},{2,3}};
    cout << "Input: n = " << n4 << ", connections = ";
    printConnections(connections4);
    cout << endl;
    
    int result4 = solution.makeConnected(n4, connections4);
    cout << "Output: " << result4 << endl;
    cout << "Expected: 0" << endl;
    cout << "Explanation: All computers are already connected." << endl << endl;
    
    // 测试用例5：单个节点
    cout << "=== Test Case 5 (Single Node) ===" << endl;
    int n5 = 1;
    vector<vector<int>> connections5 = {};
    cout << "Input: n = " << n5 << ", connections = ";
    printConnections(connections5);
    cout << endl;
    
    int result5 = solution.makeConnected(n5, connections5);
    cout << "Output: " << result5 << endl;
    cout << "Expected: 0" << endl;
    cout << "Explanation: Single computer is already connected." << endl << endl;
    
    // 测试用例6：两个节点，无连接
    cout << "=== Test Case 6 (Two Nodes, No Connection) ===" << endl;
    int n6 = 2;
    vector<vector<int>> connections6 = {};
    cout << "Input: n = " << n6 << ", connections = ";
    printConnections(connections6);
    cout << endl;
    
    int result6 = solution.makeConnected(n6, connections6);
    cout << "Output: " << result6 << endl;
    cout << "Expected: -1" << endl;
    cout << "Explanation: Not enough cables to connect 2 computers." << endl << endl;
    
    // 测试用例7：复杂情况
    cout << "=== Test Case 7 (Complex Case) ===" << endl;
    int n7 = 8;
    vector<vector<int>> connections7 = {{0,1},{1,2},{2,0},{3,4},{4,5},{3,5},{6,7}};
    cout << "Input: n = " << n7 << ", connections = ";
    printConnections(connections7);
    cout << endl;
    
    int result7 = solution.makeConnected(n7, connections7);
    cout << "Output: " << result7 << endl;
    cout << "Expected: 2" << endl;
    cout << "Explanation: 3 components: {0,1,2}, {3,4,5}, {6,7}. Need 2 operations to connect all." << endl << endl;
    
    // 测试用例8：大量冗余连接
    cout << "=== Test Case 8 (Many Redundant Connections) ===" << endl;
    int n8 = 5;
    vector<vector<int>> connections8 = {{0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    cout << "Input: n = " << n8 << ", connections = ";
    printConnections(connections8);
    cout << endl;
    
    int result8 = solution.makeConnected(n8, connections8);
    cout << "Output: " << result8 << endl;
    cout << "Expected: 0" << endl;
    cout << "Explanation: All computers are connected with many redundant cables." << endl << endl;
    
    cout << "All tests completed!" << endl;
    return 0;
}
