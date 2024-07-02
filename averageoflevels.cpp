#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

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
//    vector<double> averageOfLevels(TreeNode* root) {
//        auto averages = vector<double>();
//        auto q = queue<TreeNode*>();
//        q.push(root);
//        while (!q.empty()) {
//            double sum = 0;
//            int size = q.size();
//            for (int i = 0; i < size; i++) {
//                auto node = q.front();
//                q.pop();
//                sum += node->val;
//                auto left = node->left, right = node->right;
//                if (left != nullptr) {
//                    q.push(left);
//                }
//                if (right != nullptr) {
//                    q.push(right);
//                }
//            }
//            averages.push_back(sum / size);
//        }
//        return averages;
//    }
//};



class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        auto counts = vector<int>();
        auto sums = vector<double>();
        dfs(root, 0, counts, sums);
        auto averages = vector<double>();
        int size = sums.size();
        for (int i = 0; i < size; i++) {
            averages.push_back(sums[i] / counts[i]);
        }
        return averages;
    }

    void dfs(TreeNode* root, int level, vector<int>& counts, vector<double>& sums) {
        if (root == nullptr) {
            return;
        }
        if (level < sums.size()) {
            sums[level] += root->val;
            counts[level] += 1;
        }
        else {
            sums.push_back(1.0 * root->val);
            counts.push_back(1);
        }
        dfs(root->left, level + 1, counts, sums);
        dfs(root->right, level + 1, counts, sums);
    }
};



// 主函数，用于测试
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

    Solution solution;
    vector<double> result = solution.averageOfLevels(root);

    cout << "Average of levels: ";
    for (double avg : result) {
        cout << avg << " ";
    }
    cout << endl;

    // 释放树内存
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}