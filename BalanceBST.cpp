#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderValues;

    void getInorder(TreeNode* root) {
        if (root == nullptr) return;
        getInorder(root->left);
        inorderValues.push_back(root->val);
        getInorder(root->right);
    }

    TreeNode* build(int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l) / 2; // �޸���������  
        TreeNode* tree = new TreeNode(inorderValues[mid]);
        tree->left = build(l, mid - 1);
        tree->right = build(mid + 1, r);
        return tree;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return root;
        getInorder(root);
        TreeNode* balancedRoot = build(0, inorderValues.size() - 1);
        deleteTree(root); // �ͷ�ԭʼ�����ڴ�
        return balancedRoot;
    }

    void deleteTree(TreeNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
};

void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(4);

    Solution solution;
    TreeNode* balancedRoot = solution.balanceBST(root); // ע�⺯������Сд
    printInorder(balancedRoot);
    cout << endl;

    solution.deleteTree(balancedRoot); // �ͷ�ƽ�������ڴ�

    return 0;
}