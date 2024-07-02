#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0; // 左侧指针，从数组头部开始
        int right = numbers.size() - 1; // 右侧指针，从数组尾部开始

        while (left < right) { // 循环直到左右指针相遇
            int sum = numbers[left] + numbers[right]; // 计算当前两个指针指向的元素之和

            if (sum == target) {
                return { left + 1, right + 1 }; // 如果和为目标值，返回这对解
            }
            else if (sum < target) {
                left++; // 如果和小于目标值，移动左侧指针向右
            }
            else {
                right--; // 如果和大于目标值，移动右侧指针向左
            }
        }

        return {}; // 如果没有找到解，返回空数组（虽然题目中数组是有序的，总能找到解）
    }
};

int main() {
    Solution solution;
    std::vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;

    std::vector<int> result = solution.twoSum(numbers, target);
    if (!result.empty()) {
        std::cout << "Two Sum found: " << result[0] << " and " << result[1] << std::endl;
    }
    else {
        std::cout << "No two sum found." << std::endl;
    }

    return 0;
}