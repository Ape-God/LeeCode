#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*> stack;

    void leftmostInorder(TreeNode* node) {
        while (node) {
            stack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        leftmostInorder(root);
    }

    bool hasNext() {
        return !stack.empty();
    }

    int next() {
        // ������ǰ�����ڵ㣬������ֵ�����������ӽڵ�ѹ��ջ��
        TreeNode* top = stack.top();
        stack.pop();
        if (top->right) {
            leftmostInorder(top->right);
        }
        return top->val;
    }
};

// �����������ڲ���
int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator iterator(root);
    while (iterator.hasNext()) {
        std::cout << iterator.next() << " ";
    }
    std::cout << std::endl;

    // �ͷ����ڴ�
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}