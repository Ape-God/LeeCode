#include <vector>
#include <queue>
#include <algorithm> // ����reverse����
#include <iostream>

using namespace std;

// ����������Ľڵ�ṹ
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // ���ɶ�����������ͼ
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result; // �洢����ͼ�Ľ��
        if (!root) return result; // ������ڵ�Ϊ�գ�ֱ�ӷ��ؿս��

        queue<TreeNode*> q; // ʹ�ö���������ʵ�ֲ������
        q.push(root); // �����ڵ�������

        while (!q.empty()) {
            int levelSize = q.size(); // ��ǰ��Ľڵ�����
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); // ȡ�����еĵ�һ���ڵ�
                q.pop(); // �������еĵ�һ���ڵ�
                // ����Ǹò�����һ���ڵ㣬����ֵ������
                if (i == levelSize - 1) {
                    result.push_back(node->val);
                }
                // ����ǰ�ڵ�������ӽڵ������У��Ա���һ�ֲ������
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result; // ��������ͼ�Ľ��
    }
};

// ʾ������
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5); // 2�����ӽڵ�
    root->right->left = new TreeNode(4); // 3�����ӽڵ�

    Solution solution;
    vector<int> rightView = solution.rightSideView(root);

    // �������ͼ�Ľ��
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    // �ͷŶ�����ռ�õ��ڴ�
    delete root->left->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}