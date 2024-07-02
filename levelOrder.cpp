#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 定义二叉树节点结构体
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
    // 层序遍历函数
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // 存储层序遍历的结果
        if (!root) return result; // 如果根节点为空，直接返回空结果

        queue<TreeNode*> q; // 使用队列来辅助实现层序遍历
        q.push(root); // 将根节点入队

        while (!q.empty()) {
            int levelSize = q.size(); // 当前层的节点数量
            vector<int> currentLevel; // 当前层的节点值

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // 取出队列的第一个节点
                q.pop(); // 弹出队列的第一个节点
                currentLevel.push_back(node->val); // 将节点的值加入到当前层的数组中

                // 如果左子节点不为空，将其加入队列
                if (node->left) q.push(node->left);
                // 如果右子节点不为空，将其加入队列
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel); // 将当前层的节点值加入到结果中
        }

        return result; // 返回层序遍历的结果
    }
};

// 示例调用
int main() {
    // 构建示例二叉树
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> levels = solution.levelOrder(root);

    // 输出层序遍历的结果
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }

    // 释放二叉树占用的内存
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}