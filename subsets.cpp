#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    // ���ݺ����������������п��ܵ��Ӽ�
    void backtrack(int index, vector<int>& current, vector<vector<int>>& result, const vector<int>& nums) {
        // ����ǰ���Ӽ���ӵ������
        result.push_back(current);
        // �� index ��ʼ������������� nums �е�Ԫ�ص���ǰ�Ӽ�
        for (int i = index; i < nums.size(); ++i) {
            // ��� nums[i] ����ǰ�Ӽ�
            current.push_back(nums[i]);
            // �ݹ���ã�ʹ�� i + 1 ��Ϊ��һ����ʼ����
            backtrack(i + 1, current, result, nums);
            // ���ݣ��Ƴ���ǰ��ӵ�Ԫ�أ��Գ����������
            current.pop_back();
        }
    }

    // �������Ӽ�����
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;  // �洢���п��ܵ��Ӽ�
        vector<int> current;  // �洢��ǰ���Ӽ�
        // ������ 0 ��ʼ�����û��ݺ������������Ӽ�
        backtrack(0, current, result, nums);
        // �������п��ܵ��Ӽ�
        return result;
    }
};

// ʾ������
int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 3 };
    vector<vector<int>> subsets1 = solution.subsets(nums1);
    // ��ӡ���ʾ��1
    for (const auto& subset : subsets1) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "[]\n";
    }

    vector<int> nums2 = { 0 };
    vector<vector<int>> subsets2 = solution.subsets(nums2);
    // ��ӡ���ʾ��2
    for (const auto& subset : subsets2) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "[]\n";
    }

    return 0;
}