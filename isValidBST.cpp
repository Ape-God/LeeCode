#include <iostream>
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
    // �������������ڵݹ����֤�������Ƿ�Ϊ��Ч�Ķ���������
    bool helper(TreeNode* node, long minVal, long maxVal) {
        // �սڵ�����Ч��
        if (!node) return true;

        // ��鵱ǰ�ڵ��ֵ�Ƿ�������ķ�Χ��
        if (node->val <= minVal || node->val >= maxVal) return false;

        // �ݹ�ؼ����������������
        // ������������ֵ����С�ڵ�ǰ�ڵ��ֵ
        // ������������ֵ������ڵ�ǰ�ڵ��ֵ
        return helper(node->left, minVal, node->val) && helper(node->right, node->val, maxVal);
    }

    // ��֤�������Ƿ�Ϊ��Ч�Ķ���������
    bool isValidBST(TreeNode* root) {
        // ��ʼ����ʱ���ڵ��ֵ��Χ�����޵�
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

class Solution {
    // ���ڼ�¼��һ�����ʽڵ��ֵ����ʼ��Ϊ��С��long long����ֵ
    long long lastVal = LLONG_MIN;

public:
    // �ж϶������Ƿ���Ч��BST
    bool isValidBST(TreeNode* root) {
        // �����ǰ�ڵ�Ϊ�գ�˵���Ѿ�����Ҷ�ӽڵ㣬����true
        if (!root) {
            return true;
        }
        // ���ȵݹ�ؼ���������Ƿ�Ϊ��Ч��BST
        if (!isValidBST(root->left)) {
            return false;
        }
        // ��鵱ǰ�ڵ��ֵ�Ƿ������һ�����ʽڵ��ֵ��������ǣ�������Ч��BST
        if (root->val <= lastVal) {
            return false;
        }
        // ������һ�����ʽڵ��ֵΪ��ǰ�ڵ��ֵ
        lastVal = root->val;
        // �ݹ�ؼ���������Ƿ�Ϊ��Ч��BST
        return isValidBST(root->right);
    }
};


// �����������ڲ���Solution���isValidBST��Ա����
int main() {
    // ����һ���򵥵Ķ�����
    //       2
    //      / \
    //     1   3
    TreeNode* root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    // ����Solution����
    Solution solution;

    // ����isValidBST�������ж϶������Ƿ�Ϊ��Ч�Ķ���������
    bool result = solution.isValidBST(root);
    cout << (result ? "The binary tree is a valid BST." : "The binary tree is not a valid BST.") << endl;

    // ���������ڴ�
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}