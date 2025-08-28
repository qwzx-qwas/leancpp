#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBSTTree (int low , int high) {
    if (low > high) return nullptr;
    int mid = low + (high - low) / 2;
    TreeNode* root = new TreeNode(mid);
    root->left = buildBSTTree(low, mid - 1);
    root->right = buildBSTTree(mid + 1, high);
    return root;
}

void getSearchLengths (TreeNode* root, vector<int>& lengths, int depth) {
    if (!root) return;
    lengths[root->val] = depth;
    getSearchLengths(root->left, lengths, depth + 1);
    getSearchLengths(root->right, lengths, depth + 1);
}


int main() {
    int n = 20;
    TreeNode* root = buildBSTTree(0, n - 1);

    vector<int> lengths(n);  // lengths[i] = 查找下标 i 的长度
    getSearchLengths(root, lengths, 0);

    // 输出每个元素的查找长度
    for (int i = 0; i < n; ++i) {
        cout << "Index " << i << ": length = " << lengths[i] << endl;
    }

    return 0;
}
