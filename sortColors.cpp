#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于对颜色进行排序
    void sortColors(vector<int>& nums) {
        int n = nums.size(); // 获取数组长度
        int red = 0, white = 0, blue = n - 1; // 初始化三个指针

        // 遍历数组直到中间指针不越界
        while (white <= blue) {
            // 如果当前元素是红色，将其与red指针所指的元素交换，移动red和white指针
            if (nums[white] == 0) {
                swap(nums[red], nums[white]);
                red++;
                white++;
            }
            // 如果当前元素是白色，只移动white指针
            else if (nums[white] == 1) {
                white++;
            }
            // 如果当前元素是蓝色，将其与blue指针所指的元素交换，移动blue指针
            else {
                swap(nums[blue], nums[white]);
                blue--;
            }
        }
    }
};

// 示例函数，用于演示 Solution 类的 sortColors 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 2, 0, 2, 1, 1, 0 };
    // 调用 sortColors 方法并输出结果
    solution.sortColors(nums);
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << (num == 0 ? "red" : (num == 1 ? "white" : "blue")) << " ";
    }
    cout << endl;

    return 0;
}