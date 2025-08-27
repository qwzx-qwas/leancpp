#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n,-1);
        unordered_map<int,int> tmp;
        
        for(int i = 0; i < n2; i++) {
            tmp[nums2[i]] = i;
        }

        for(int j = 0; j < n; j++) {
            bool skip = false;
            for(int k = tmp[nums1[j]]; k < n2; k++) {
                int t = nums2[k];
                if(t > nums2[tmp[nums1[j]]]){
                    ans[j] = t;
                   break;
                }
            }
            if(skip) {continue;}
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

int main() {
    Solution solution;
    
    // 测试用例1：LeetCode官方示例1
    cout << "=== Test Case 1 ===" << endl;
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};
    cout << "Input: nums1 = ";
    printVector(nums1_1);
    cout << ", nums2 = ";
    printVector(nums2_1);
    cout << endl;
    
    vector<int> result1 = solution.nextGreaterElement(nums1_1, nums2_1);
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    cout << "Expected: [-1, 3, -1]" << endl;
    cout << "Explanation: 4->no greater, 1->3, 2->no greater" << endl << endl;
    
    // 测试用例2：LeetCode官方示例2
    cout << "=== Test Case 2 ===" << endl;
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};
    cout << "Input: nums1 = ";
    printVector(nums1_2);
    cout << ", nums2 = ";
    printVector(nums2_2);
    cout << endl;
    
    vector<int> result2 = solution.nextGreaterElement(nums1_2, nums2_2);
    cout << "Output: ";
    printVector(result2);
    cout << endl;
    cout << "Expected: [3, -1]" << endl;
    cout << "Explanation: 2->3, 4->no greater" << endl << endl;
    
    // 测试用例3：单个元素
    cout << "=== Test Case 3 (Single Element) ===" << endl;
    vector<int> nums1_3 = {1};
    vector<int> nums2_3 = {1, 2};
    cout << "Input: nums1 = ";
    printVector(nums1_3);
    cout << ", nums2 = ";
    printVector(nums2_3);
    cout << endl;
    
    vector<int> result3 = solution.nextGreaterElement(nums1_3, nums2_3);
    cout << "Output: ";
    printVector(result3);
    cout << endl;
    cout << "Expected: [2]" << endl << endl;
    
    // 测试用例4：降序排列
    cout << "=== Test Case 4 (Descending Order) ===" << endl;
    vector<int> nums1_4 = {5, 4, 3};
    vector<int> nums2_4 = {5, 4, 3, 2, 1};
    cout << "Input: nums1 = ";
    printVector(nums1_4);
    cout << ", nums2 = ";
    printVector(nums2_4);
    cout << endl;
    
    vector<int> result4 = solution.nextGreaterElement(nums1_4, nums2_4);
    cout << "Output: ";
    printVector(result4);
    cout << endl;
    cout << "Expected: [-1, -1, -1]" << endl;
    cout << "Explanation: All elements have no greater element" << endl << endl;
    
    // 测试用例5：升序排列
    cout << "=== Test Case 5 (Ascending Order) ===" << endl;
    vector<int> nums1_5 = {1, 2, 3};
    vector<int> nums2_5 = {1, 2, 3, 4, 5};
    cout << "Input: nums1 = ";
    printVector(nums1_5);
    cout << ", nums2 = ";
    printVector(nums2_5);
    cout << endl;
    
    vector<int> result5 = solution.nextGreaterElement(nums1_5, nums2_5);
    cout << "Output: ";
    printVector(result5);
    cout << endl;
    cout << "Expected: [2, 3, 4]" << endl << endl;
    
    // 测试用例6：复杂情况
    cout << "=== Test Case 6 (Complex Case) ===" << endl;
    vector<int> nums1_6 = {1, 5, 3, 6};
    vector<int> nums2_6 = {1, 3, 5, 6, 2, 8};
    cout << "Input: nums1 = ";
    printVector(nums1_6);
    cout << ", nums2 = ";
    printVector(nums2_6);
    cout << endl;
    
    vector<int> result6 = solution.nextGreaterElement(nums1_6, nums2_6);
    cout << "Output: ";
    printVector(result6);
    cout << endl;
    cout << "Expected: [3, 6, 5, 8]" << endl;
    cout << "Explanation: 1->3, 5->6, 3->5, 6->8" << endl << endl;
    
    // 测试用例7：nums1只有一个元素且是最大的
    cout << "=== Test Case 7 (Largest Element) ===" << endl;
    vector<int> nums1_7 = {10};
    vector<int> nums2_7 = {1, 5, 10, 3};
    cout << "Input: nums1 = ";
    printVector(nums1_7);
    cout << ", nums2 = ";
    printVector(nums2_7);
    cout << endl;
    
    vector<int> result7 = solution.nextGreaterElement(nums1_7, nums2_7);
    cout << "Output: ";
    printVector(result7);
    cout << endl;
    cout << "Expected: [-1]" << endl << endl;
    
    cout << "All tests completed!" << endl;
    return 0;
}
