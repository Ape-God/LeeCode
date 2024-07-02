#include <iostream>
#include <stack>
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
    // �ҵ�������������BST���е�kС��Ԫ�ص�ֵ
    int kthSmallest(TreeNode* root, int k) {
        // ʹ��һ��ջ������ʵ�ֵ����ķǵݹ����
        stack<TreeNode*> stack;

        // ѭ��ֱ��ջΪ�ջ���rootΪnullptr
        while (root != nullptr || !stack.empty()) {
            // ��root��Ϊ��ʱ�������������ӽڵ�ѹ��ջ��
            while (root != nullptr) {
                stack.push(root);
                root = root->left; // ���������ƶ���Ѱ����һ�����ӽڵ�
            }

            // ��ջ�ǿ�ʱ������ջ��Ԫ����Ϊ��ǰ�ڵ�
            root = stack.top();
            stack.pop();

            // ���ҵ���kС��Ԫ��ʱ��������ֵ
            if (--k == 0) {
                return root->val; // ÿ����һ��Ԫ�أ�k��1����k����0ʱ���ҵ���kС��Ԫ��
            }

            // ��������������
            root = root->right;
        }

        // ���û���ҵ���kС��Ԫ�أ�����-1
        return -1;
    }
};





// �����������ڲ���Solution���kthSmallest��Ա����
int main() {
    // ����һ���򵥵Ķ���������
    //       3
    //      / \
    //     1   4
    //       \   \
    //        2   5
    TreeNode* root = new TreeNode(3, new TreeNode(1), new TreeNode(4, new TreeNode(2), new TreeNode(5)));

    // ����Solution����
    Solution solution;

    // ����kthSmallest���������ҵ�3С��Ԫ��
    int k = 3;
    cout << "The " << k << "th smallest element is: " << solution.kthSmallest(root, k) << endl;

    // ���������ڴ�
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}