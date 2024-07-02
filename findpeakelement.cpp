#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // ��� mid Ԫ�ص��ұ�Ԫ�ظ�����ô��ֵһ���� mid �ұ�
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else {
                // ���򣬷�ֵ�� mid ��߻��߾��� mid
                right = mid;
            }
        }
        // �� left == right ʱ��left �� right ��ָ����ܵķ�ֵ
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3, 1 }; // ʾ������

    int peakIndex = solution.findPeakElement(nums);
    cout << "The index of the peak element is: " << peakIndex << endl;

    return 0;
}