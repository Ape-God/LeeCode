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
public:
    // 主函数，用于将有序数组转换为平衡二叉搜索树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    // 辅助函数，用于递归地构建二叉搜索树
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if (start > end) {
            // 如果开始索引大于结束索引，返回空指针，表示没有子树
            return nullptr;
        }
        // 计算当前子数组的中点，并将其作为节点的值
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        // 递归地构建左子树和右子树
        node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return node; // 返回构建好的二叉搜索树的根节点
    }
};

// 示例函数，用于演示 Solution 类的 sortedArrayToBST 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { -10, -3, 0, 5, 9 };
    // 调用 sortedArrayToBST 方法并输出结果
    TreeNode* root = solution.sortedArrayToBST(nums);
    // 这里可以添加代码来遍历或验证二叉搜索树

    // 注意：在实际应用中，你需要释放二叉搜索树占用的内存
    // 例如，使用一个递归函数来遍历树并删除每个节点

    return 0;
}