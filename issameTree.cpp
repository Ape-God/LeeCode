#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// �ݹ麯���Ƚ��������Ƿ���ͬ
bool isSameTree(TreeNode* p, TreeNode* q) {
    // ��������������ڵ㶼Ϊ�գ���������ͬ��
    if (!p && !q) return true;
    // ���һ��Ϊ�ն���һ����Ϊ�գ����������ڵ��ֵ�����
    if (!p || !q || p->val != q->val) return false;
    // �ݹ�Ƚ���������
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

// �����������ڲ���
int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);
    std::cout << "The trees are " << (result ? "identical" : "not identical") << std::endl;

    // �ͷ����ڴ�
    delete p->left;
    delete p->right;
    delete q->left;
    delete q->right;
    delete p;
    delete q;

    return 0;
}