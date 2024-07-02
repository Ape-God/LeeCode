#include <iostream>
#include <vector>

using namespace std;

// ����������ڵ�ṹ
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
    // �����������ڽ���������ת��Ϊƽ�����������
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }

private:
    // �������������ڵݹ�ع�������������
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int start, int end) {
        if (start > end) {
            // �����ʼ�������ڽ������������ؿ�ָ�룬��ʾû������
            return nullptr;
        }
        // ���㵱ǰ��������е㣬��������Ϊ�ڵ��ֵ
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        // �ݹ�ع�����������������
        node->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        node->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return node; // ���ع����õĶ����������ĸ��ڵ�
    }
};

// ʾ��������������ʾ Solution ��� sortedArrayToBST ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { -10, -3, 0, 5, 9 };
    // ���� sortedArrayToBST ������������
    TreeNode* root = solution.sortedArrayToBST(nums);
    // ���������Ӵ�������������֤����������

    // ע�⣺��ʵ��Ӧ���У�����Ҫ�ͷŶ���������ռ�õ��ڴ�
    // ���磬ʹ��һ���ݹ麯������������ɾ��ÿ���ڵ�

    return 0;
}