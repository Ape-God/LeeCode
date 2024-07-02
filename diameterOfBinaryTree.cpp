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
private:
    int ans; // ���ڴ洢��������ֱ��

    // �������������ڼ�����rtΪ������������ȣ�������ans
    int depth(TreeNode* rt) {
        if (rt == NULL) {
            return 0; // ������ʵ��սڵ㣬����0
        }
        int L = depth(rt->left); // �ݹ���������������
        int R = depth(rt->right); // �ݹ���������������

        // ����ansΪ��ǰ�����������L�������R֮�ͼ�1������rt�ڵ㣩
        ans = max(ans, L + R + 1);

        // �����Ե�ǰ�ڵ�Ϊ������������ȣ������������нϴ����ȼ�1
        return max(L, R) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1; // ��ʼ��ansΪ1����Ϊֱ������Ϊ1�������ڵ㣩
        depth(root); // ������rootΪ������������ȣ�������ans
        // ����ans-1����Ϊans�ڵݹ�����ж������һ�θ��ڵ�
        return ans - 1;
    }
};

// ʾ��������������ʾ Solution ��� diameterOfBinaryTree ����
int main() {
    Solution solution;
    // ����һ��ʾ��������
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(4), new TreeNode(5));
    root->right = new TreeNode(3);

    // ���� diameterOfBinaryTree ������������
    int diameter = solution.diameterOfBinaryTree(root);
    cout << "The diameter of the binary tree is: " << diameter << endl;

    // ע�⣺��ʵ��Ӧ���У�����Ҫ�ͷŶ�����ռ�õ��ڴ�
    // ���磬ʹ��һ���ݹ麯������������ɾ��ÿ���ڵ�

    return 0;
}