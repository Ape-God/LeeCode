#include <iostream>

// ����������ڵ�ṹ
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

// �����������������
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        // ��������������Ϊ�գ����Ϊ0
        return 0;
    }
    else {
        // �ݹ�������������������ȣ������ϵ�ǰ�ڵ�
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
}

// �����������ڲ���
int main() {
    // ����һ��ʾ��������
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // ���㲢���������
    std::cout << "The maximum depth of the binary tree is: " << maxDepth(root) << std::endl;

    // �ͷ����ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ����������ڴ棩
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}