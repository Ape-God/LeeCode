#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// �������������ڹ���������
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder,
    int& preorderIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd || preorderIndex >= preorder.size()) {
        return nullptr;
    }

    // �������ڵ�
    TreeNode* node = new TreeNode(preorder[preorderIndex++]);
    int inIndex = -1;
    // ������������ҵ����ڵ��λ��
    for (int i = inorderStart; i <= inorderEnd; ++i) {
        if (inorder[i] == node->val) {
            inIndex = i;
            break;
        }
    }

    // �ݹ鹹����������������
    node->left = buildTree(preorder, inorder, preorderIndex, inorderStart, inIndex - 1);
    node->right = buildTree(preorder, inorder, preorderIndex, inIndex + 1, inorderEnd);

    return node;
}

// �����������ĺ���
TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
    int preorderIndex = 0;
    return buildTree(preorder, inorder, preorderIndex, 0, inorder.size() - 1);
}

// ���������ͷ����ڴ�
void deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// �������ڴ�ӡ����ǰ�������
void printTree(TreeNode* node) {
    if (!node) return;
    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}


class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }

        // ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
        int preorder_root = preorder_left;
        // ����������ж�λ���ڵ�
        int inorder_root = index[preorder[preorder_root]];

        // �ȰѸ��ڵ㽨������
        TreeNode* root = new TreeNode(preorder[preorder_root]);
        // �õ��������еĽڵ���Ŀ
        int size_left_subtree = inorder_root - inorder_left;
        // �ݹ�ع����������������ӵ����ڵ�
        // ��������С��� ��߽�+1 ��ʼ�� size_left_subtree����Ԫ�ؾͶ�Ӧ����������С��� ��߽� ��ʼ�� ���ڵ㶨λ-1����Ԫ��
        root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // �ݹ�ع����������������ӵ����ڵ�
        // ��������С��� ��߽�+1+�������ڵ���Ŀ ��ʼ�� �ұ߽硹��Ԫ�ؾͶ�Ӧ����������С��� ���ڵ㶨λ+1 �� �ұ߽硹��Ԫ��
        root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // �����ϣӳ�䣬�������ǿ��ٶ�λ���ڵ�
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};


int main() {
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    Solution solution;

    TreeNode* root = solution.buildTree(preorder, inorder);

    cout << "The constructed binary tree is: ";
    printTree(root);

    // �ͷ����ڴ�
    deleteTree(root);

    return 0;
}