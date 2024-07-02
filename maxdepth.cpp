#include <iostream>

// 定义二叉树节点结构
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr),right(nullptr){}
};

// 计算二叉树的最大深度
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        // 基本情况：如果树为空，深度为0
        return 0;
    }
    else {
        // 递归计算左右子树的最大深度，并加上当前节点
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}

// 主函数，用于测试
int main() {
    // 创建一个示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 计算并输出最大深度
    std::cout << "The maximum depth of the binary tree is: " << maxDepth(root) << std::endl;

    // 释放树内存（在实际应用中应该添加代码来释放整个树的内存）
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}