#include <iostream>
#include <stack>
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
    // 找到二叉搜索树（BST）中第k小的元素的值
    int kthSmallest(TreeNode* root, int k) {
        // 使用一个栈来辅助实现迭代的非递归遍历
        stack<TreeNode*> stack;

        // 循环直到栈为空或者root为nullptr
        while (root != nullptr || !stack.empty()) {
            // 当root不为空时，将其所有左子节点压入栈中
            while (root != nullptr) {
                stack.push(root);
                root = root->left; // 继续向左移动，寻找下一个左子节点
            }

            // 当栈非空时，弹出栈顶元素作为当前节点
            root = stack.top();
            stack.pop();

            // 当找到第k小的元素时，返回其值
            if (--k == 0) {
                return root->val; // 每弹出一个元素，k减1，当k减到0时，找到第k小的元素
            }

            // 继续遍历右子树
            root = root->right;
        }

        // 如果没有找到第k小的元素，返回-1
        return -1;
    }
};





// 主函数，用于测试Solution类的kthSmallest成员函数
int main() {
    // 创建一个简单的二叉搜索树
    //       3
    //      / \
    //     1   4
    //       \   \
    //        2   5
    TreeNode* root = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), new TreeNode(5)));

    // 创建Solution对象
    Solution solution;

    // 调用kthSmallest函数，查找第3小的元素
    int k = 3;
    cout << "The " << k << "th smallest element is: " << solution.kthSmallest(root, k) << endl;

    // 清理分配的内存
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}