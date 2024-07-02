#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 辅助函数用于递归计算根节点到叶节点的路径数字
void sumRootToLeafUtil(TreeNode* node, int currentSum, std::vector<int>& path, std::vector<int>& result) {
    if (!node) return;

    // 将当前节点的值添加到路径中
    path.push_back(node->val);
    currentSum = currentSum * 10 + node->val;

    // 检查是否到达叶节点
    if (!node->left && !node->right) {
        // 如果是叶节点，将路径数字添加到结果中
        result.push_back(currentSum);
    }
    else {
        // 否则，继续递归遍历左右子树
        sumRootToLeafUtil(node->left, currentSum, path, result);
        sumRootToLeafUtil(node->right, currentSum, path, result);
    }

    // 回溯，从路径中移除当前节点的值，准备下一次递归
    path.pop_back();
}

// 函数计算从根节点到叶节点数字之和
int sumNumbers(TreeNode* root) {
    std::vector<int> path, result;
    sumRootToLeafUtil(root, 0, path, result);
    int sum = 0;
    for (int num : result) {
        sum += num;
    }
    return sum;
}

class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};



// 主函数，用于测试
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    int sum = solution.sumNumbers(root);
    std::cout << "The sum of all root-to-leaf numbers is: " << sum << std::endl; // 应该输出 111 + 222 + 333 = 666

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