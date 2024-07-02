#include <iostream>

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
    void flatten(TreeNode* root) {
        if (!root) return;

        // 先序遍历：首先访问根节点，然后左子树，最后右子树
        flatten(root->left);
        flatten(root->right);

        // 将右子树连接到左子树的末尾
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        // 连接左子树的最后一个节点到右子树
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = temp;
    }
};

// 辅助函数，用于创建二叉树
TreeNode* createTreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(value, left, right);
}

// 辅助函数，用于释放二叉树内存
void deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// 辅助函数，用于打印链表
void printList(TreeNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

// 主函数，用于测试
int main() {
    TreeNode* root = createTreeNode(1,
        createTreeNode(2,
            createTreeNode(4),
            createTreeNode(5)),
        createTreeNode(3));
    Solution solution;
    std::cout << "Original binary tree in preorder traversal: ";
    printList(root);

    solution.flatten(root);

    std::cout << "Binary tree flattened to a linked list: ";
    printList(root);

    // 释放树内存
    deleteTree(root);

    return 0;
}