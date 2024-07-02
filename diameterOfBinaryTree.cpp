#include <iostream>
#include <vector>

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
private:
    int ans; // 用于存储二叉树的直径

    // 辅助函数，用于计算以rt为根的子树的深度，并更新ans
    int depth(TreeNode* rt) {
        if (rt == NULL) {
            return 0; // 如果访问到空节点，返回0
        }
        int L = depth(rt->left); // 递归计算左子树的深度
        int R = depth(rt->right); // 递归计算右子树的深度

        // 更新ans为当前子树的左深度L与右深度R之和加1（包括rt节点）
        ans = max(ans, L + R + 1);

        // 返回以当前节点为根的子树的深度，即左右子树中较大的深度加1
        return max(L, R) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1; // 初始化ans为1，因为直径至少为1（单个节点）
        depth(root); // 计算以root为根的子树的深度，并更新ans
        // 返回ans-1，因为ans在递归过程中多计算了一次根节点
        return ans - 1;
    }
};

// 示例函数，用于演示 Solution 类的 diameterOfBinaryTree 方法
int main() {
    Solution solution;
    // 创建一个示例二叉树
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    // 调用 diameterOfBinaryTree 方法并输出结果
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "The diameter of the binary tree is: " << diameter << endl;

    // 注意：在实际应用中，你需要释放二叉树占用的内存
    // 例如，使用一个递归函数来遍历树并删除每个节点

    return 0;
}