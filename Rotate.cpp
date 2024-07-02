#include <vector>
#include<iostream>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    // 就地旋转数组nums向右k步
//    void rotate(vector<int>& nums, int k) {
//        int n = nums.size(); // 获取数组的长度
//        // 此处代码被注释掉了，实际上这行代码是必要的，用于处理k大于数组长度的情况
//        // k = k % n;
//
//        // 如果k为0，说明不需要旋转，直接返回
//        if (k == 0) {
//            return;
//        }
//
//        // 创建一个临时数组来存储旋转后的数组
//        vector<int> rotated(n);
//        // 将原数组的元素复制到临时数组的相应位置
//        for (int i = 0; i < n; ++i) {
//            rotated[(i + k) % n] = nums[i]; // 使用模运算来计算新位置
//        }
//
//        // 将临时数组的元素复制回原数组，完成旋转
//        for (int i = 0; i < n; ++i) {
//            nums[i] = rotated[i];
//        }
//    }
//};


class Solution {
public:
    // 就地旋转数组nums的元素，使其向右旋转k步
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // 获取数组的长度
        // 取k与数组长度n的模，以处理k大于n的情况
        k = k % n;

        // 计算k和n的最大公约数，以减少旋转次数
        // 因为如果k是n的倍数，数组旋转后不会发生变化
        int count = gcd(k, n);

        // 遍历数组，每次处理长度为count的子数组
        for (int start = 0; start < count; ++start) {
            // 初始化当前索引和该索引处的元素值
            int current = start;
            int prev = nums[start];

            // 使用do-while循环实现链式交换
            do {
                // 计算下一个元素的索引，使用模n运算确保索引在数组范围内
                int next = (current + k) % n;
                // 交换当前元素和下一个元素的值
                // 使用标准库中的swap函数进行交换
                swap(nums[next], prev);
                // 更新当前索引为下一个索引
                current = next;
            }
            // 继续循环直到所有元素回到原始起始位置，完成一轮旋转
            while (start != current);
        }
    }

    // gcd函数原型，实际定义在类的其他部分
    // int gcd(int a, int b) {
};




int main() {
    // 创建Solution对象
    Solution solution;

    // 创建一个整数数组并初始化
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3; // 旋转步数

    // 输出原始数组
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 调用rotate方法进行旋转
    solution.rotate(nums, k);

    // 输出旋转后的数组
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}