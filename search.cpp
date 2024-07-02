#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return target == nums[0] ? 0 : -1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid; // �ҵ�Ŀ��ֵ����������
            }

            // �ж���벿���Ƿ�����
            if (nums[left] <= nums[mid]) {
                // ��벿������
                if (target >= nums[left] && target < nums[mid]) {
                    // Ŀ��ֵ����벿��
                    right = mid - 1;
                }
                else {
                    // Ŀ��ֵ���Ұ벿��
                    left = mid + 1;
                }
            }
            else {
                // �Ұ벿������
                if (target > nums[mid] && target <= nums[right]) {
                    // Ŀ��ֵ���Ұ벿��
                    left = mid + 1;
                }
                else {
                    // Ŀ��ֵ����벿��
                    right = mid - 1;
                }
            }
        }
        return -1; // δ�ҵ�Ŀ��ֵ������-1
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 0;

    int index = solution.search(nums, target);
    if (index != -1) {
        cout << "The target " << target << " is at index: " << index << endl;
    }
    else {
        cout << "The target " << target << " is not in the array." << endl;
    }

    return 0;
}