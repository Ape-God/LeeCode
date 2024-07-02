#include <vector>
#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        // ��ʼ���������
        vector<int> result;
        // �ݹ��������������
        inorder(root, result);
        // ���ؽ������
        return result;
    }

private:
    // �������������ڵݹ�ʵ���������
    void inorder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
            return;
        }
        // �ȱ���������
        inorder(node->left, result);
        // ���ʵ�ǰ�ڵ㣬����ֵ��ӵ����������
        result.push_back(node->val);
        // �ٱ���������
        inorder(node->right, result);
    }
};


class Solution {
public:
    // �������������ڵݹ�ʵ���������
    // ���յ�ǰ�ڵ�root�����ڴ洢���������res
    void inorder(TreeNode* root, vector<int>& res) {
        // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
        if (!root) {
            return;
        }
        // �ݹ����������
        inorder(root->left, res);
        // ���ʵ�ǰ�ڵ㣬���ڵ��ֵ��ӵ����������
        res.push_back(root->val);
        // �ݹ����������
        inorder(root->right, res);
    }

    // �����ӿں��������ڻ�ȡ������������������
    // ���ն������ĸ��ڵ�root
    vector<int> inorderTraversal(TreeNode* root) {
        // ��ʼ���������res
        vector<int> res;
        // ���ø�������inorder��������ڵ�ͽ������
        inorder(root, res);
        // ���ش洢����������������
        return res;
    }
};


class Solution {
public:
    // ʵ�ֶ��������������
    vector<int> inorderTraversal(TreeNode* root) {
        // ��ʼ�����ڴ洢����������������
        vector<int> ans;
        // ���嵱ǰ�����Ľڵ�cur����ʼΪ���ڵ�
        TreeNode* cur = root;
        // ��ʼ��һ��ջ���ڸ�������
        stack<TreeNode*> stk;

        // ����ǰ�ڵ㲻Ϊ�ջ���ջ��Ϊ��ʱ����������
        while (cur || !stk.empty()) {
            // ����ǰ�ڵ�cur��Ϊ��ʱ��������ջ
            // ������������������
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            // ��curΪ��ʱ��˵���Ѿ������������ľ�ͷ
            // ��ʱջ��Ԫ���ǵ�ǰ��Ҫ���ʵĽڵ�
            cur = stk.top();
            // ����ջ��Ԫ�أ���Ϊ�Ѿ��������
            stk.pop();
            // ����ǰ�ڵ��ֵ��ӵ����������
            ans.push_back(cur->val);
            // ��cur����Ϊ��ǰ�ڵ�����ӽڵ㣬׼��������������
            cur = cur->right;
        }

        // ������������Ľ��
        return ans;
    }
};




// ʾ�����룬չʾ��ε���inorderTraversal����
int main() {
    // ����ʾ��������
    TreeNode* root = new TreeNode(1);
    root->left = nullptr; // ���ڵ�û�����ӽڵ�
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3); // ���ӽڵ�����ӽڵ�

    // ����Solution����
    Solution solution;
    // ����inorderTraversal��������ȡ����������
    vector<int> traversal = solution.inorderTraversal(root);
    // ��ӡ���
    for (int val : traversal) {
        cout << val << " ";
    }
    cout << endl;

    // ���������ڴ�
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}