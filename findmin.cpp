#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // �м�Ԫ�ر��ұ߽�Ԫ�ش�˵����Сֵ��mid���ұߣ�����mid��right
                left = mid + 1;
            }
            else {
                // �м�Ԫ��С�ڻ�����ұ߽�Ԫ�أ���Сֵ������mid����߻�mid����
                right = mid;
            }
        }
        // ��left == rightʱ��left��right��ָ����СԪ��
        return nums[left];
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4,5,6,7,0,1,2 }; // ʾ������

    int minVal = solution.findMin(nums);
    cout << "The minimum element in the rotated sorted array is: " << minVal << endl;

    return 0;
}