#include <iostream>

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ��ת������
TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        // ��������������Ϊ�գ����ؿ�
        return nullptr;
    }

    // �ݹ鷭ת��������
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    // ���������ӽڵ�
    std::swap(root->left, root->right);

    // ���ط�ת��ĸ��ڵ�
    return root;
}

// �����������ڲ���
int main() {
    // ����һ��ʾ��������
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    // ��ת������
    TreeNode* newRoot = invertTree(root);

    // ��ӡ��ת��Ķ��������������ӡ���ڵ��ֵ��ʵ��ʹ���п�����Ҫ������������
    std::cout << "The root of the inverted binary tree is: " << newRoot->val << std::endl;

    // �ͷ����ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ����������ڴ棩
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}