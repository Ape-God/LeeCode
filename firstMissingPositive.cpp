#include <iostream>
#include <vector>
#include <cstdlib> // ����abs����

using namespace std;

class Solution {
public:
    // �������������ҳ�δ���ֵ���С������
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // �����з������ʹ���n�����ŵ������ĩβ
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // �ٴα������飬�ҵ���һ�������� nums[i] == i + 1 ��λ��
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1; // �������λ�õ�������
            }
        }

        return n + 1; // ���������1��n���ڣ�����n+1
    }
};

// ʾ��������������ʾ Solution ��� firstMissingPositive ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 3, 4, -1, 1 };
    // ���� firstMissingPositive ������������
    int missing = solution.firstMissingPositive(nums);
    cout << "The first missing positive is: " << missing << endl;

    // ������Ӹ���Ĳ��԰���
    vector<int> nums2 = { 7, 8, 9, 11, 12 };
    missing = solution.firstMissingPositive(nums2);
    cout << "The first missing positive is: " << missing << endl;

    vector<int> nums3 = { 1, 2, 0 };
    missing = solution.firstMissingPositive(nums3);
    cout << "The first missing positive is: " << missing << endl;

    return 0;
}