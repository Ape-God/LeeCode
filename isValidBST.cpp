#include <iostream>
using namespace std;

// 定义二叉树节点结构
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
    // 辅助函数，用于递归地验证二叉树是否为有效的二叉搜索树
    bool helper(TreeNode* node, long minVal, long maxVal) {
        // 空节点是有效的
        if (!node) return true;

        // 检查当前节点的值是否在允许的范围内
        if (node->val <= minVal || node->val >= maxVal) return false;

        // 递归地检查左子树和右子树
        // 左子树的所有值必须小于当前节点的值
        // 右子树的所有值必须大于当前节点的值
        return helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);
    }

    // 验证二叉树是否为有效的二叉搜索树
    bool isValidBST(TreeNode* root) {
        // 初始调用时，节点的值范围是无限的
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

class Solution {
    // 用于记录上一个访问节点的值，初始化为最小的long long类型值
    long long lastVal = LLONG_MIN;

public:
    // 判断二叉树是否有效的BST
    bool isValidBST(TreeNode* root) {
        // 如果当前节点为空，说明已经到达叶子节点，返回true
        if (!root) {
            return true;
        }
        // 首先递归地检查左子树是否为有效的BST
        if (!isValidBST(root->left)) {
            return false;
        }
        // 检查当前节点的值是否大于上一个访问节点的值，如果不是，则不是有效的BST
        if (root->val <= lastVal) {
            return false;
        }
        // 更新上一个访问节点的值为当前节点的值
        lastVal = root->val;
        // 递归地检查右子树是否为有效的BST
        return isValidBST(root->right);
    }
};


// 主函数，用于测试Solution类的isValidBST成员函数
int main() {
    // 创建一个简单的二叉树
    //       2
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    // 创建Solution对象
    Solution solution;

    // 调用isValidBST函数，判断二叉树是否为有效的二叉搜索树
    bool result = solution.isValidBST(root);
    cout << (result ? "The binary tree is a valid BST." : "The binary tree is not a valid BST.") << endl;

    // 清理分配的内存
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}