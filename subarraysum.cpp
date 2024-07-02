#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        int count = 0, sum = 0;
//        unordered_map<int, int> um;
//        um[0] = 1; // ���������ǰ׺��Ϊ0����1��
//
//        for (int i = 0; i < nums.size(); ++i) {
//            sum += nums[i]; // ����ǰ׺��
//            count += um[sum - k]; // ����Ϊk������������
//            um[sum]++; // ����ǰ׺��sum���ֵĴ���
//        }
//
//        return count;
//    }
//};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};



// ���Ժ���
void testSolution(Solution& solution, vector<int>& nums, int k) {
    int result = solution.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " = " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums = { 1, 1, 1 }; // ��������
    int k = 2; // Ŀ���

    testSolution(solution, nums, k);

    // ������Ӹ���Ĳ�������
    return 0;
}