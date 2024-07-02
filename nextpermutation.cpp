#include <vector>
#include <algorithm> // ���� reverse
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


//class Solution {
//public:
//    void nextPermutation(vector<int>& nums) {
//        int n = nums.size();
//        // ����1���ҵ��½���
//        int i = n - 2;
//        while (i >= 0 && nums[i] >= nums[i + 1]) {
//            i--;
//        }
//
//        // ���i < 0��˵�������ǽ���ģ�ֱ�ӷ�ת����
//        if (i == -1) {
//            reverse(nums.begin(), nums.end());
//            return;
//        }
//
//        // ����2���ҵ������½������СԪ�ز�����
//        int j = n - 1;
//        while (nums[j] <= nums[i]) {
//            j--;
//        }
//        swap(nums[i], nums[j]);
//
//        // ����3����ת�½���֮�������Ԫ��
//        reverse(nums.begin() + i + 1, nums.end());
//    }
//};

// �����������ڲ���
int main() {
    Solution solution;
    vector<int> nums = { 1, 2, 3 };
    solution.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}