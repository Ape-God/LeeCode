#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// ����������ڵ�ṹ��
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
    // �����������
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // �洢��������Ľ��
        if (!root) return result; // ������ڵ�Ϊ�գ�ֱ�ӷ��ؿս��

        queue<TreeNode*> q; // ʹ�ö���������ʵ�ֲ������
        q.push(root); // �����ڵ����

        while (!q.empty()) {
            int levelSize = q.size(); // ��ǰ��Ľڵ�����
            vector<int> currentLevel; // ��ǰ��Ľڵ�ֵ

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // ȡ�����еĵ�һ���ڵ�
                q.pop(); // �������еĵ�һ���ڵ�
                currentLevel.push_back(node->val); // ���ڵ��ֵ���뵽��ǰ���������

                // ������ӽڵ㲻Ϊ�գ�����������
                if (node->left) q.push(node->left);
                // ������ӽڵ㲻Ϊ�գ�����������
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel); // ����ǰ��Ľڵ�ֵ���뵽�����
        }

        return result; // ���ز�������Ľ��
    }
};

// ʾ������
int main() {
    // ����ʾ��������
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> levels = solution.levelOrder(root);

    // �����������Ľ��
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }

    // �ͷŶ�����ռ�õ��ڴ�
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}