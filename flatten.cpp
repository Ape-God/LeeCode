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

        // ������������ȷ��ʸ��ڵ㣬Ȼ�������������������
        flatten(root->left);
        flatten(root->right);

        // �����������ӵ���������ĩβ
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = nullptr;

        // ���������������һ���ڵ㵽������
        TreeNode* current = root;
        while (current->right) {
            current = current->right;
        }
        current->right = temp;
    }
};

// �������������ڴ���������
TreeNode* createTreeNode(int value, TreeNode* left = nullptr, TreeNode* right = nullptr) {
    return new TreeNode(value, left, right);
}

// ���������������ͷŶ������ڴ�
void deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// �������������ڴ�ӡ����
void printList(TreeNode* node) {
    while (node) {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

// �����������ڲ���
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

    // �ͷ����ڴ�
    deleteTree(root);

    return 0;
}