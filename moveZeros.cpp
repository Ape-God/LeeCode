#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZeroCount = 0; // 记录非零元素的数量
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            // 如果当前元素是非零的，将它移动到前面
            nums[nonZeroCount++] = nums[i];
        }
    }
    // 将剩余的位置用0填充
    for (int i = nonZeroCount; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

class Solution {
public:
    // 主函数，用于将数组中的零移动到末尾，同时保持非零元素的顺序
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); // 获取数组的长度
        int left = 0, right = 0; // 初始化左右指针

        // 使用 while 循环，直到右指针遍历完整个数组
        while (right < n) {
            // 如果当前元素是非零元素
            if (nums[right]) {
                // 交换左指针和右指针所指向的元素，将非零元素移动到左侧
                swap(nums[left], nums[right]);
                // 左指针右移，指向下一个待处理的元素
                left++;
            }
            // 无论当前元素是零还是非零，右指针都向右移动
            right++;
        }
    }
};



int main() {
    vector<int> nums = { 0, 1, 0, 3, 12 };
    Solution solution;
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}