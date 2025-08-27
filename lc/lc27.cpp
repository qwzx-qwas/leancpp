#include <iostream>
#include <vector>


class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

// 辅助函数：打印数组
void printVector(const std::vector<int>& nums, int length) {
    std::cout << "[";
    for (int i = 0; i < length; i++) {
        std::cout << nums[i];
        if (i < length - 1) std::cout << ", ";
    }
    std::cout << "]";
}

int main() {
    Solution solution;
    
    // 测试用例1
    std::cout << "=== Test Case 1 ===" << std::endl;
    std::vector<int> nums1 = {3, 2, 2, 3};
    int val1 = 3;
    std::cout << "Input: nums = ";
    printVector(nums1, nums1.size());
    std::cout << ", val = " << val1 << std::endl;
    
    int newLength1 = solution.removeElement(nums1, val1);
    std::cout << "Output: " << newLength1 << ", nums = ";
    printVector(nums1, newLength1);
    std::cout << std::endl << std::endl;
    
    // 测试用例2
    std::cout << "=== Test Case 2 ===" << std::endl;
    std::vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int val2 = 2;
    std::cout << "Input: nums = ";
    printVector(nums2, nums2.size());
    std::cout << ", val = " << val2 << std::endl;
    
    int newLength2 = solution.removeElement(nums2, val2);
    std::cout << "Output: " << newLength2 << ", nums = ";
    printVector(nums2, newLength2);
    std::cout << std::endl << std::endl;
    
    // 测试用例3：空数组
    std::cout << "=== Test Case 3 (Empty Array) ===" << std::endl;
    std::vector<int> nums3 = {};
    int val3 = 1;
    std::cout << "Input: nums = ";
    printVector(nums3, nums3.size());
    std::cout << ", val = " << val3 << std::endl;
    
    int newLength3 = solution.removeElement(nums3, val3);
    std::cout << "Output: " << newLength3 << ", nums = ";
    printVector(nums3, newLength3);
    std::cout << std::endl << std::endl;
    
    // 测试用例4：所有元素都相同
    std::cout << "=== Test Case 4 (All Same Elements) ===" << std::endl;
    std::vector<int> nums4 = {1, 1, 1, 1};
    int val4 = 1;
    std::cout << "Input: nums = ";
    printVector(nums4, nums4.size());
    std::cout << ", val = " << val4 << std::endl;
    
    int newLength4 = solution.removeElement(nums4, val4);
    std::cout << "Output: " << newLength4 << ", nums = ";
    printVector(nums4, newLength4);
    std::cout << std::endl << std::endl;
    
    // 测试用例5：没有要移除的元素
    std::cout << "=== Test Case 5 (No Target Elements) ===" << std::endl;
    std::vector<int> nums5 = {1, 2, 3, 4, 5};
    int val5 = 6;
    std::cout << "Input: nums = ";
    printVector(nums5, nums5.size());
    std::cout << ", val = " << val5 << std::endl;
    
    int newLength5 = solution.removeElement(nums5, val5);
    std::cout << "Output: " << newLength5 << ", nums = ";
    printVector(nums5, newLength5);
    std::cout << std::endl;
    
    std::cout << "All tests completed!" << std::endl;
    return 0;
}

