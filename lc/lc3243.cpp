#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < n - 1; i++) {
            graph[i].push_back(i + 1);
        }

        vector<int> ans;
        
        auto bfs = [&](int start, int target) {
            vector<int> dist(n, -1);
            queue<int> q;
            dist[start] = 0;
            q.push(start);

            while(!q.empty()) {
                int u = q.front();
                q.pop();
                if(u == target) {
                    return dist[u];
                }
                for (auto &v : graph[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            return -1;
        };

        for (auto &query : queries) {
            int u = query[0];
            int v = query[1];
            graph[u].push_back(v);  // 修正：应该是从u到v的边
            ans.push_back(bfs(0, n-1));  // 修正：计算从0到n-1的最短距离
        }
        return ans;
    }
};

// 辅助函数：打印vector<int>
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

// 辅助函数：打印二维vector
void printQueries(const vector<vector<int>>& queries) {
    cout << "[";
    for (int i = 0; i < queries.size(); i++) {
        cout << "[" << queries[i][0] << "," << queries[i][1] << "]";
        if (i < queries.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1：LeetCode官方示例1
    cout << "=== Test Case 1 ===" << endl;
    int n1 = 5;
    vector<vector<int>> queries1 = {{2,4},{0,2},{0,4}};
    cout << "Input: n = " << n1 << ", queries = ";
    printQueries(queries1);
    cout << endl;
    
    vector<int> result1 = solution.shortestDistanceAfterQueries(n1, queries1);
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [3, 2, 1]" << endl;
    cout << "Explanation:" << endl;
    cout << "- Initial path: 0->1->2->3->4 (distance=4)" << endl;
    cout << "- After adding (2,4): 0->1->2->4 (distance=3)" << endl;
    cout << "- After adding (0,2): 0->2->4 (distance=2)" << endl;
    cout << "- After adding (0,4): 0->4 (distance=1)" << endl << endl;
    
    // 测试用例2：LeetCode官方示例2
    cout << "=== Test Case 2 ===" << endl;
    int n2 = 4;
    vector<vector<int>> queries2 = {{0,3},{0,2}};
    cout << "Input: n = " << n2 << ", queries = ";
    printQueries(queries2);
    cout << endl;
    
    vector<int> result2 = solution.shortestDistanceAfterQueries(n2, queries2);
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [1, 1]" << endl;
    cout << "Explanation:" << endl;
    cout << "- Initial path: 0->1->2->3 (distance=3)" << endl;
    cout << "- After adding (0,3): 0->3 (distance=1)" << endl;
    cout << "- After adding (0,2): still 0->3 (distance=1)" << endl << endl;
    
    // 测试用例3：单个查询
    cout << "=== Test Case 3 (Single Query) ===" << endl;
    int n3 = 6;
    vector<vector<int>> queries3 = {{1,5}};
    cout << "Input: n = " << n3 << ", queries = ";
    printQueries(queries3);
    cout << endl;
    
    vector<int> result3 = solution.shortestDistanceAfterQueries(n3, queries3);
    cout << "Output: ";
    printVector(result3);
    cout << endl;
    cout << "Expected: [2]" << endl;
    cout << "Explanation: 0->1->5 (distance=2)" << endl << endl;
    
    // 测试用例4：最小情况
    cout << "=== Test Case 4 (Minimal Case) ===" << endl;
    int n4 = 3;
    vector<vector<int>> queries4 = {{0,2}};
    cout << "Input: n = " << n4 << ", queries = ";
    printQueries(queries4);
    cout << endl;
    
    vector<int> result4 = solution.shortestDistanceAfterQueries(n4, queries4);
    cout << "Output: ";
    printVector(result4);
    cout << endl;
    cout << "Expected: [1]" << endl;
    cout << "Explanation: Direct path 0->2 (distance=1)" << endl << endl;
    
    // 测试用例5：多个不相关的查询
    cout << "=== Test Case 5 (Multiple Independent Queries) ===" << endl;
    int n5 = 7;
    vector<vector<int>> queries5 = {{1,3},{2,5},{4,6}};
    cout << "Input: n = " << n5 << ", queries = ";
    printQueries(queries5);
    cout << endl;
    
    vector<int> result5 = solution.shortestDistanceAfterQueries(n5, queries5);
    cout << "Output: ";
    printVector(result5);
    cout << endl;
    cout << "Expected: [4, 3, 3]" << endl;
    cout << "Explanation:" << endl;
    cout << "- After (1,3): 0->1->3->4->5->6 (distance=5)" << endl;
    cout << "- After (2,5): 0->1->2->5->6 (distance=4)" << endl;
    cout << "- After (4,6): 0->1->2->5->6 or 0->1->3->4->6 (distance=4)" << endl << endl;
    
    // 测试用例6：逐步缩短路径
    cout << "=== Test Case 6 (Gradually Shortening Path) ===" << endl;
    int n6 = 8;
    vector<vector<int>> queries6 = {{1,4},{2,6},{0,7}};
    cout << "Input: n = " << n6 << ", queries = ";
    printQueries(queries6);
    cout << endl;
    
    vector<int> result6 = solution.shortestDistanceAfterQueries(n6, queries6);
    cout << "Output: ";
    printVector(result6);
    cout << endl;
    cout << "Expected: [4, 2, 1]" << endl;
    cout << "Explanation:" << endl;
    cout << "- After (1,4): 0->1->4->5->6->7 (distance=4)" << endl;
    cout << "- After (2,6): 0->1->2->6->7 (distance=3)" << endl;
    cout << "- After (0,7): 0->7 (distance=1)" << endl << endl;
    
    // 测试用例7：无效果的查询
    cout << "=== Test Case 7 (No Effect Query) ===" << endl;
    int n7 = 5;
    vector<vector<int>> queries7 = {{0,1},{1,2}};
    cout << "Input: n = " << n7 << ", queries = ";
    printQueries(queries7);
    cout << endl;
    
    vector<int> result7 = solution.shortestDistanceAfterQueries(n7, queries7);
    cout << "Output: ";
    printVector(result7);
    cout << endl;
    cout << "Expected: [4, 4]" << endl;
    cout << "Explanation: These edges already exist, so no change in distance" << endl << endl;
    
    cout << "All tests completed!" << endl;
    return 0;
}
