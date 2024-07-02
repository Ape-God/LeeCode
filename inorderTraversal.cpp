#include <vector>
#include <iostream>
#include <stack>
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
    // 中序遍历函数
    vector<int> inorderTraversal(TreeNode* root) {
        // 初始化结果数组
        vector<int> result;
        // 递归中序遍历二叉树
        inorder(root, result);
        // 返回结果数组
        return result;
    }

private:
    // 辅助函数，用于递归实现中序遍历
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            // 如果当前节点为空，直接返回
            return;
        }
        // 先遍历左子树
        inorder(node->left, result);
        // 访问当前节点，将其值添加到结果数组中
        result.push_back(node->val);
        // 再遍历右子树
        inorder(node->right, result);
    }
};


class Solution {
public:
    // 辅助函数，用于递归实现中序遍历
    // 接收当前节点root和用于存储结果的向量res
    void inorder(TreeNode* root, vector<int>& res) {
        // 如果当前节点为空，直接返回
        if (!root) {
            return;
        }
        // 递归遍历左子树
        inorder(root->left, res);
        // 访问当前节点，将节点的值添加到结果向量中
        res.push_back(root->val);
        // 递归遍历右子树
        inorder(root->right, res);
    }

    // 公共接口函数，用于获取二叉树的中序遍历结果
    // 接收二叉树的根节点root
    vector<int> inorderTraversal(TreeNode* root) {
        // 初始化结果向量res
        vector<int> res;
        // 调用辅助函数inorder，传入根节点和结果向量
        inorder(root, res);
        // 返回存储中序遍历结果的向量
        return res;
    }
};


class Solution {
public:
    // 实现二叉树的中序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        // 初始化用于存储中序遍历结果的向量
        vector<int> ans;
        // 定义当前遍历的节点cur，初始为根节点
        TreeNode* cur = root;
        // 初始化一个栈用于辅助遍历
        stack<TreeNode*> stk;

        // 当当前节点不为空或者栈不为空时，继续遍历
        while (cur || !stk.empty()) {
            // 当当前节点cur不为空时，将其入栈
            // 并继续向左子树遍历
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            // 当cur为空时，说明已经到达左子树的尽头
            // 此时栈顶元素是当前需要访问的节点
            cur = stk.top();
            // 弹出栈顶元素，因为已经访问完毕
            stk.pop();
            // 将当前节点的值添加到结果向量中
            ans.push_back(cur->val);
            // 将cur设置为当前节点的右子节点，准备向右子树遍历
            cur = cur->right;
        }

        // 返回中序遍历的结果
        return ans;
    }
};




// 示例代码，展示如何调用inorderTraversal函数
int main() {
    // 创建示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = nullptr; // 根节点没有左子节点
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3); // 右子节点的左子节点

    // 创建Solution对象
    Solution solution;
    // 调用inorderTraversal函数，获取中序遍历结果
    vector<int> traversal = solution.inorderTraversal(root);
    // 打印结果
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    // 清理分配的内存
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}