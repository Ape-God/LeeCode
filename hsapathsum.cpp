#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool hasPathSum(TreeNode* root, int targetSum) {
    // ���������������ڵ�Ϊ�գ����� false
    if (!root) return false;

    // ��鵱ǰ�ڵ��Ƿ���Ҷ�ӽڵ㣬������ֵ����Ŀ���
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }

    // �ݹ�����������
    return hasPathSum(root->left, targetSum - root->val) ||
        hasPathSum(root->right, targetSum - root->val);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    int targetSum = 22; // 5 + 4 + 11 + 2

    bool result = hasPathSum(root, targetSum);
    std::cout << "Has path sum: " << (result ? "true" : "false") << std::endl;

    // �ͷ����ڴ�
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}