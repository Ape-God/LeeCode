#include <vector>
#include <iostream>
#include <numeric> // ���� accumulate
#include <algorithm>
using namespace std;

//class Solution {
//public:
//    double findMaxAverage(vector<int>& nums, int k) {
//        double maxAverage = accumulate(nums.begin(), nums.begin() + k, 0.0) / k; // �����һ���������ƽ����
//        double windowSum = maxAverage * k; // ��ǰ���ڵĺ�
//
//        // �ӵڶ�������Ϊ k �������鿪ʼ����
//        for (int i = k; i < nums.size(); ++i) {
//            // ���´��ںͣ���ȥ��ǰ��������Ԫ�أ������½��봰�ڵ�Ԫ��
//            windowSum += nums[i] - nums[i - k];
//            // �������ƽ����
//            maxAverage = max(maxAverage, windowSum / k);
//        }
//
//        return maxAverage;
//    }
//};

class Solution {
public:
    // �������������ҳ��������ڴ�С k �Ļ��������е����ƽ��ֵ
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0; // ��ʼ�����ڵĺ�Ϊ0
        int n = nums.size(); // ��ȡ���� nums �Ĵ�С
        // ���㴰�ڵĳ�ʼ��
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum; // ��ʼ������Ϊ��ʼ���ڵĺ�

        // �������飬���ڴ�СΪ k���ҳ���󴰿ں�
        for (int i = k; i < n; ++i) {
            // �������ڣ���ȥ��������Ԫ�أ����ϴ����Ҳ��Ԫ��
            sum = sum - nums[i - k] + nums[i];
            // ������󴰿ں�
            maxSum = max(maxSum, sum);
        }

        // ����󴰿ں�ת��Ϊƽ��ֵ�����أ����ڴ�СΪ k
        return static_cast<double>(maxSum) / k;
    }
};


// ���Ժ���
void testSolution(Solution& solution,vector<int>& nums, int k) {
    double result = solution.findMaxAverage(nums, k);
    cout << "Max average of a " << k << "-element subarray is: " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 12, 15, 8, 7, 9, 12 };
    int k1 = 3;
    testSolution(solution, nums1, k1);

    vector<int> nums2 = { 4, 3, 1 };
    int k2 = 2;
    testSolution(solution, nums2, k2);

    return 0;
}