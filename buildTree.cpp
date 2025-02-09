#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数，用于构建二叉树
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder,
    int& preorderIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd || preorderIndex >= preorder.size()) {
        return nullptr;
    }

    // 创建根节点
    TreeNode* node = new TreeNode(preorder[preorderIndex++]);
    int inIndex = -1;
    // 在中序遍历中找到根节点的位置
    for (int i = inorderStart; i <= inorderEnd; ++i) {
        if (inorder[i] == node->val) {
            inIndex = i;
            break;
        }
    }

    // 递归构建左子树和右子树
    node->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inIndex - 1);
    node->right = buildTree(preorder, inorder, preorderIndex, inIndex + 1, inorderEnd);

    return node;
}

// 构建二叉树的函数
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int preorderIndex = 0;
    return buildTree(preorder, inorder, preorderIndex, 0, inorder.size() - 1);
}

// 函数用于释放树内存
void deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 函数用于打印树（前序遍历）
void printTree(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}


class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // 前序遍历中的第一个节点就是根节点
        int preorder_root = preorder_left;
        // 在中序遍历中定位根节点
        int inorder_root = index[preorder[preorder_root]];

        // 先把根节点建立出来
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // 得到左子树中的节点数目
        int size_left_subtree = inorder_root - inorder_left;
        // 递归地构造左子树，并连接到根节点
        // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // 递归地构造右子树，并连接到根节点
        // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


int main() {
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    Solution solution;

    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "The constructed binary tree is: ";
    printTree(root);

    // 释放树内存
    deleteTree(root);

    return 0;
}