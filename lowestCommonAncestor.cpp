#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// �ݹ麯�����������ڵ�������������
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root; // �������������ǿ�ʱ����ǰ�ڵ���LCA
    }
    else {
        return left ? left : right; // ���򣬷��طǿ�������LCA
    }
}

// �����������ڲ���
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode* p = root->left; // �ڵ� 1
    TreeNode* q = root->right; // �ڵ� 3

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    std::cout << "The Lowest Common Ancestor of nodes " << p->val << " and " << q->val
        << " is: " << lca->val << std::endl;

    // �ͷ����ڴ�
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}