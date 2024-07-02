#include <iostream>
#include <vector>
#include <algorithm> // 用于 abs
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;
        inOrderTraversal(root, inorder);
        int minDiff = abs(inorder[1] - inorder[0]); // 至少有两个节点
        for (size_t i = 2; i < inorder.size(); ++i) {
            minDiff = min(minDiff, abs(inorder[i] - inorder[i - 1]));
        }
        return minDiff;
    }

    void inOrderTraversal(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        inOrderTraversal(node->left, vals);
        vals.push_back(node->val);
        inOrderTraversal(node->right, vals);
    }
};

// 主函数，用于测试
int main() {
    TreeNode* root = new TreeNode(4,
        new TreeNode(2,
            new TreeNode(1),
            new TreeNode(3)),
        new TreeNode(5));
    Solution solution;
    int minDiff = solution.getMinimumDifference(root);
    cout << "The minimum absolute difference is: " << minDiff << endl;

    // 释放树内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}