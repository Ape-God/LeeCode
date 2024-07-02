#include <iostream>
#include <queue>
using namespace std;

// ����������ڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// �ݹ麯������������Ľڵ����
int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// �����������ڲ���
int main() {
    // ����һ��ʾ����ȫ������
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // ���㲢����ڵ����
    std::cout << "The number of nodes in the binary tree is: " << countNodes(root) << std::endl;

    // �ͷ����ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ����������ڴ棩
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}