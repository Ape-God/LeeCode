#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归函数查找两个节点的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
        return root; // 当左右子树都非空时，当前节点是LCA
    }
    else {
        return left ? left : right; // 否则，返回非空子树的LCA
    }
}

// 主函数，用于测试
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    TreeNode* p = root->left; // 节点 1
    TreeNode* q = root->right; // 节点 3

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    std::cout << "The Lowest Common Ancestor of nodes " << p->val << " and " << q->val
        << " is: " << lca->val << std::endl;

    // 释放树内存
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}