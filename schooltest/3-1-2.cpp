#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> inPutSeq = {1, 2, 3, 4, 5};
/*in (输入序列): 包含所有待入栈的数字。

st (栈): 用来存储已经入栈但尚未出栈的数字。

current (当前输出序列): 存储已经出栈的数字。

results (结果列表): 存储所有最终得到的、完整的出栈序列。 */

void backTrack (vector<int> in, stack<int> st, vector<int> current) {
    //如果输入序列 in 已经没数了，栈 st 也空了，
    //说明所有数都已经按照规则出栈，得到了一个完整的输出序列 → 存到 results。

    if(in.empty() && st.empty()) {
        results.push_back(current);
        return;
    }
    //入栈
    if (!in.empty()) {
        int num = in.front();
        in.erase(in.begin()); // 相当于 pop(0)
        st.push(num);
        backTrack(in, st, current);
        // 回溯不需要手动恢复，因为是值传递
    }
    // 选择2：出栈
    if (!st.empty()) {
        int num = st.top();
        st.pop();
        current.push_back(num);
        backTrack(in, st, current);
    }

   
}

int main() {
    stack<int> st;
    vector<int> current;
    backTrack(inPutSeq, st, current);

    for (auto &seq : results) {
        for (int x : seq) cout << x << " ";
        cout << endl;
    }
}
