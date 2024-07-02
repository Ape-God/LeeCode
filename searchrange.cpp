#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    vector<int> searchRange(vector<int>& nums, int target) {
//        int n = nums.size();
//        vector<int> result = { -1, -1 };
//
//        // ����Ŀ��ֵ�����߽�
//        int left = 0, right = n - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] >= target) {
//                right = mid - 1;
//            }
//            else {
//                left = mid + 1;
//            }
//        }
//        if (left == n || nums[left] != target) {
//            return result; // Ŀ��ֵ������
//        }
//        result[0] = left; // ���߽�
//
//        // ����Ŀ��ֵ���Ҳ�߽�
//        left = 0, right = n - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] <= target) {
//                left = mid + 1;
//            }
//            else {
//                right = mid - 1;
//            }
//        }
//        result[1] = right; // �Ҳ�߽�
//
//        return result;
//    }
//};


class Solution {
public:
    // ���ֲ��ұ��֣����ڲ���Ŀ��ֵ�������е����������λ��
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = nums.size() - 1, ans = (int)nums.size(); // ��ʼ������ָ��ʹ�
        // ѭ��ֱ������ָ������
        while (left <= right) {
            int mid = left + (right - left) / 2; // �����м�λ��
            // ����м�ֵ����Ŀ��ֵ����������С�ڵ���Ŀ��ֵ�����������Ҹ�С��ֵ
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1; // �����ұ߽粢���´�
                ans = mid;
            }
            else {
                left = mid + 1; // ���������߽�
            }
        }
        return ans; // ����Ŀ��ֵ��λ�û�����֮���ĳ��λ��
    }

    // ����Ŀ��ֵ�������е���ʼ�ͽ���λ��
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true); // ͨ��binarySearch��������λ��
        int rightIdx = binarySearch(nums, target, false) - 1; // ͨ��binarySearch��������λ�ã���1����Ϊʵ�ʵ�����

        // ����ҵ��������Ƿ���Ч�����Ҷ�Ӧλ�õ�ֵȷʵΪĿ��ֵ
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return vector<int>{leftIdx, rightIdx}; // ����Ŀ��ֵ����ʼ�ͽ���λ��
        }
        // ���û���ҵ�Ŀ��ֵ������{-1, -1}
        return vector<int>{-1, -1};
    }
};



int main() {
    Solution solution;
    vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);
    if (result[0] == -1) {
        cout << "The target " << target << " is not in the array." << endl;
    }
    else {
        cout << "The target " << target << " is located in the range: ["
            << result[0] << ", " << result[1] << "]" << endl;
    }

    return 0;
}