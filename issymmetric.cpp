#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//class Solution {
//public:
//    bool isSymmetric(TreeNode* root) {
//        if (!root) return true; // ��������������ǶԳƵ�
//        return isMirror(root->left, root->right); // �����ڵ�����������Ƿ���Գ�
//    }
//
//private:
//    bool isMirror(TreeNode* left, TreeNode* right) {
//        if (!left && !right) return true; // �����սڵ��ǶԳƵ�
//        if (!left || !right) return false; // һ��Ϊ�գ�һ���ǿգ����ǶԳƵ�
//        if (left->val != right->val) return false; // �ڵ�ֵ����ȣ����ǶԳƵ�
//
//        // �ݹ��飺����������ڵ������������ҽڵ㣬���������ҽڵ�������������ڵ�
//        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
//    }
//};


class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};




// �����������ڲ���
int main() {
    // ����һ���ԳƵĶ�����
    TreeNode* root = new TreeNode(1,
        new TreeNode(2,
            new TreeNode(3),
            new TreeNode(4)
        ),
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(3)
        )
    );

    Solution solution;
    bool result = solution.isSymmetric(root);
    std::cout << "The binary tree is " << (result ? "symmetric" : "not symmetric") << "." << std::endl;

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