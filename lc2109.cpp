#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        /*int n = spaces.size();
        for(int i = n - 1; i >= 0; i--) {
            s.insert(spaces[i], 1, ' ');
        }
        return s;*/
        int j = 0;
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (j < spaces.size() && i == spaces[j]) {
                result += ' ';
                j++;
            }
            result += s[i];
        }
        return result;
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

int main() {
    Solution solution;
    
    // 测试用例1
    cout << "=== Test Case 1 ===" << endl;
    string s1 = "LeetcodeHelpsMeLearn";
    vector<int> spaces1 = {8, 13, 15};
    cout << "Input: s = \"" << s1 << "\", spaces = ";
    printVector(spaces1);
    cout << endl;
    
    string result1 = solution.addSpaces(s1, spaces1);
    cout << "Output: \"" << result1 << "\"" << endl;
    cout << "Expected: \"Leetcode Helps Me Learn\"" << endl << endl;
    
    // 测试用例2
    cout << "=== Test Case 2 ===" << endl;
    string s2 = "icodeinpython";
    vector<int> spaces2 = {1, 5, 7, 9};
    cout << "Input: s = \"" << s2 << "\", spaces = ";
    printVector(spaces2);
    cout << endl;
    
    string result2 = solution.addSpaces(s2, spaces2);
    cout << "Output: \"" << result2 << "\"" << endl;
    cout << "Expected: \"i code in py thon\"" << endl << endl;
    
    // 测试用例3
    cout << "=== Test Case 3 ===" << endl;
    string s3 = "spacing";
    vector<int> spaces3 = {0, 1, 2, 3, 4, 5, 6};
    cout << "Input: s = \"" << s3 << "\", spaces = ";
    printVector(spaces3);
    cout << endl;
    
    string result3 = solution.addSpaces(s3, spaces3);
    cout << "Output: \"" << result3 << "\"" << endl;
    cout << "Expected: \" s p a c i n g\"" << endl << endl;
    
    // 测试用例4：空spaces数组
    cout << "=== Test Case 4 (No Spaces) ===" << endl;
    string s4 = "hello";
    vector<int> spaces4 = {};
    cout << "Input: s = \"" << s4 << "\", spaces = ";
    printVector(spaces4);
    cout << endl;
    
    string result4 = solution.addSpaces(s4, spaces4);
    cout << "Output: \"" << result4 << "\"" << endl;
    cout << "Expected: \"hello\"" << endl << endl;
    
    // 测试用例5：单个字符
    cout << "=== Test Case 5 (Single Character) ===" << endl;
    string s5 = "a";
    vector<int> spaces5 = {0};
    cout << "Input: s = \"" << s5 << "\", spaces = ";
    printVector(spaces5);
    cout << endl;
    
    string result5 = solution.addSpaces(s5, spaces5);
    cout << "Output: \"" << result5 << "\"" << endl;
    cout << "Expected: \" a\"" << endl << endl;
    
    // 测试用例6：在开头和结尾添加空格
    cout << "=== Test Case 6 (Start and Middle) ===" << endl;
    string s6 = "helloworld";
    vector<int> spaces6 = {0, 5};
    cout << "Input: s = \"" << s6 << "\", spaces = ";
    printVector(spaces6);
    cout << endl;
    
    string result6 = solution.addSpaces(s6, spaces6);
    cout << "Output: \"" << result6 << "\"" << endl;
    cout << "Expected: \" hello world\"" << endl << endl;
    
    cout << "All tests completed!" << endl;
    return 0;
}
