#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// �����������ڵݹ������ڵ㵽Ҷ�ڵ��·������
void sumRootToLeafUtil(TreeNode* node, int currentSum, std::vector<int>& path, std::vector<int>& result) {
    if (!node) return;

    // ����ǰ�ڵ��ֵ��ӵ�·����
    path.push_back(node->val);
    currentSum = currentSum * 10 + node->val;

    // ����Ƿ񵽴�Ҷ�ڵ�
    if (!node->left && !node->right) {
        // �����Ҷ�ڵ㣬��·��������ӵ������
        result.push_back(currentSum);
    }
    else {
        // ���򣬼����ݹ������������
        sumRootToLeafUtil(node->left, currentSum, path, result);
        sumRootToLeafUtil(node->right, currentSum, path, result);
    }

    // ���ݣ���·�����Ƴ���ǰ�ڵ��ֵ��׼����һ�εݹ�
    path.pop_back();
}

// ��������Ӹ��ڵ㵽Ҷ�ڵ�����֮��
int sumNumbers(TreeNode* root) {
    std::vector<int> path, result;
    sumRootToLeafUtil(root, 0, path, result);
    int sum = 0;
    for (int num : result) {
        sum += num;
    }
    return sum;
}

class Solution {
public:
    int dfs(TreeNode* root, int prevSum) {
        if (root == nullptr) {
            return 0;
        }
        int sum = prevSum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }
        else {
            return dfs(root->left, sum) + dfs(root->right, sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};



// �����������ڲ���
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    int sum = solution.sumNumbers(root);
    std::cout << "The sum of all root-to-leaf numbers is: " << sum << std::endl; // Ӧ����� 111 + 222 + 333 = 666

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