#include <iostream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 翻转二叉树
TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        // 基本情况：如果树为空，返回空
        return nullptr;
    }

    // 递归翻转左右子树
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    // 交换左右子节点
    std::swap(root->left, root->right);

    // 返回翻转后的根节点
    return root;
}

// 主函数，用于测试
int main() {
    // 创建一个示例二叉树
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // 翻转二叉树
    TreeNode* newRoot = invertTree(root);

    // 打印翻转后的二叉树（这里仅打印根节点的值，实际使用中可能需要遍历整棵树）
    std::cout << "The root of the inverted binary tree is: " << newRoot->val << std::endl;

    // 释放树内存（在实际应用中应该添加代码来释放整个树的内存）
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}