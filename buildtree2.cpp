#include <vector>
#include <unordered_map>
#include<iostream>
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
private:
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder,
        int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        // 根节点
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // 左子树的节点数量
        int leftSize = inorderIndex[rootVal] - inStart;

        // 递归构建左子树和右子树
        root->left = buildTreeHelper(inorder, postorder, inStart, inStart + leftSize - 1, postStart, postStart + leftSize - 1);
        root->right = buildTreeHelper(inorder, postorder, inStart + leftSize + 1, inEnd, postStart + leftSize, postEnd - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 初始化中序遍历的索引映射
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        // 调用辅助函数构建整棵树
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

// 主函数，用于测试
int main() {
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    // 测试代码，打印树的中序遍历和后序遍历以验证结果
    cout << "Inorder traversal of the constructed tree: ";
    // 打印中序遍历（使用递归函数）
    // ...

    cout << "\nPostorder traversal of the constructed tree: ";
    // 打印后序遍历（使用递归函数）
    // ...

    // 释放树内存
    // ...

    return 0;
}