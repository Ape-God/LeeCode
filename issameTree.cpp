#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 递归函数比较两棵树是否相同
bool isSameTree(TreeNode* p, TreeNode* q) {
    // 基本情况：两个节点都为空，它们是相同的
    if (!p && !q) return true;
    // 如果一个为空而另一个不为空，或者两个节点的值不相等
    if (!p || !q || p->val != q->val) return false;
    // 递归比较左右子树
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// 主函数，用于测试
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    std::cout << "The trees are " << (result ? "identical" : "not identical") << std::endl;

    // 释放树内存
    delete p->left;
    delete p->right;
    delete q->left;
    delete q->right;
    delete p;
    delete q;

    return 0;
}