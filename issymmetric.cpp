#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if (!root) return true; // 基本情况：空树是对称的
//        return isMirror(root->left, root->right); // 检查根节点的左右子树是否镜像对称
//    }
//
//private:
//    bool isMirror(TreeNode* left, TreeNode* right) {
//        if (!left && !right) return true; // 两个空节点是对称的
//        if (!left || !right) return false; // 一个为空，一个非空，不是对称的
//        if (left->val != right->val) return false; // 节点值不相等，不是对称的
//
//        // 递归检查：左子树的左节点与右子树的右节点，左子树的右节点与右子树的左节点
//        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
//    }
//};


class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};




// 主函数，用于测试
int main() {
    // 创建一个对称的二叉树
    TreeNode* root = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(3),
            new TreeNode(4)
        ),
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(3)
        )
    );

    Solution solution;
    bool result = solution.isSymmetric(root);
    std::cout << "The binary tree is " << (result ? "symmetric" : "not symmetric") << "." << std::endl;

    // 释放树内存
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}