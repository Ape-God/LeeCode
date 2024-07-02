#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

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
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTreeHelper(const vector<int>& inorder, const vector<int>& postorder,
        int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return nullptr;
        }
        // ���ڵ�
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // �������Ľڵ�����
        int leftSize = inorderIndex[rootVal] - inStart;

        // �ݹ鹹����������������
        root->left = buildTreeHelper(inorder, postorder, inStart, inStart + leftSize - 1, postStart, postStart + leftSize - 1);
        root->right = buildTreeHelper(inorder, postorder, inStart + leftSize + 1, inEnd, postStart + leftSize, postEnd - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // ��ʼ���������������ӳ��
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        // ���ø�����������������
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

// �����������ڲ���
int main() {
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };

    Solution solution;
    TreeNode* root = solution.buildTree(inorder, postorder);

    // ���Դ��룬��ӡ������������ͺ����������֤���
    cout << "Inorder traversal of the constructed tree: ";
    // ��ӡ���������ʹ�õݹ麯����
    // ...

    cout << "\nPostorder traversal of the constructed tree: ";
    // ��ӡ���������ʹ�õݹ麯����
    // ...

    // �ͷ����ڴ�
    // ...

    return 0;
}