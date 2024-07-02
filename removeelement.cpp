#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; // 指向最新有效尾部的指针
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i]; // 将不等于val的元素移动到前面
                ++j; // 移动指针
            }
        }
        return j; // 返回与val不同的元素的数量
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;

    int newLength = solution.removeElement(nums, val);
    cout << "The number of elements after removal: " << newLength << endl;
    // 打印数组的前 newLength 个元素
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}