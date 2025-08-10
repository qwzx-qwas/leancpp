#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*stack<int> st; 模拟栈。

inputNum 表示当前输入序列中要入栈的数字，从 1 开始。

对输出序列的每个 num：

如果栈为空或栈顶不是 num，就不断把输入序列的下一个数入栈；

如果栈顶是 num，就出栈。

最后如果栈空，就合法。

 */
//对常量容器的引用，既不复制，也不修改容器的内容。
bool isValidOutPut (const vector<int>& A) {
    stack<int> st;
    int inputNum = 1;
    int n = A.size();
    for (int num : A) {
        while(st.empty() || st.top() != num) {
            if(inputNum > n) {
                return false;
            }
            st.push(inputNum++);
        }
        st.pop();
    }
    return st.empty();
}

int main () {
    vector<int> A = {1, 3, 4, 5, 2};
    if (isValidOutPut(A)) {
        cout << "Valid Output" << endl;
    } else {
        cout << "Invalid Output" << endl;
    }
    return 0;
}
