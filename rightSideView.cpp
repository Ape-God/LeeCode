#include <vector>
#include <queue>
#include <algorithm> // 用于reverse函数
#include <iostream>

using namespace std;

// 定义二叉树的节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 生成二叉树的右视图
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; // 存储右视图的结果
        if (!root) return result; // 如果根节点为空，直接返回空结果

        queue<TreeNode*> q; // 使用队列来辅助实现层序遍历
        q.push(root); // 将根节点加入队列

        while (!q.empty()) {
            int levelSize = q.size(); // 当前层的节点数量
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // 取出队列的第一个节点
                q.pop(); // 弹出队列的第一个节点
                // 如果是该层的最后一个节点，将其值加入结果
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                // 将当前节点的左右子节点加入队列，以便下一轮层序遍历
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result; // 返回右视图的结果
    }
};

// 示例调用
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5); // 2的右子节点
    root->right->left = new TreeNode(4); // 3的左子节点

    Solution solution;
    vector<int> rightView = solution.rightSideView(root);

    // 输出右视图的结果
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    // 释放二叉树占用的内存
    delete root->left->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}