#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(&result, nums, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>* result, vector<int>& nums, int first) {
        if (first == nums.size()) {
            result->emplace_back(nums);
            return;
        }
        for (int i = first; i < nums.size(); ++i) {
            swap(nums[i], nums[first]); // ������ǰԪ�ص���λ
            backtrack(result, nums, first + 1); // �ݹ�����ʣ��Ԫ�ص�����
            swap(nums[i], nums[first]); // ����
        }
    }
};

// ��ӡȫ���н���ĸ�������
void printPermutations(const vector<vector<int>>& perms) {
    for (const auto& perm : perms) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };

    vector<vector<int>> perms = solution.permute(nums);
    printPermutations(perms);

    return 0;
}