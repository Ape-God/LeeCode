#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;

        int first = INT_MAX; // ��һ��������ʼ��Ϊ������
        int second = INT_MAX; // �ڶ���������ʼ��Ϊ������

        for (int num : nums) {
            if (num <= first) {
                // �����ǰ��С�ڻ����first������firstΪ��Сֵ
                first = num;
            }
            else if (num <= second) {
                // �����ǰ������first��С�ڻ����second������second
                second = num;
            }
            else {
                // �����ǰ������second���ҵ�������Ԫ��
                return true;
            }
        }
        return false; // û���ҵ�������Ԫ��
    }
};

// ���Ժ���
void testSolution(Solution& solution, vector<int>& nums) {
    bool result = solution.increasingTriplet(nums);
    cout << "Does the array have an increasing triplet? " << (result ? "Yes" : "No") << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    testSolution(solution, nums1);

    vector<int> nums2 = { 5, 4, 3, 2, 1 };
    testSolution(solution, nums2);

    vector<int> nums3 = { 1, 3, 2, 4, 6 };
    testSolution(solution, nums3);

    return 0;
}