#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1; // 初始化进位为1
        int n = digits.size();

        // 从最低位开始遍历数组
        for (int i = n - 1; i >= 0 && carry; --i) {
            // 将当前位与进位相加，得到新的位值
            int sum = digits[i] + carry;
            // 更新数组中的当前位
            digits[i] = sum % 10;
            // 更新进位
            carry = sum / 10;
        }

        // 如果进位不为0，说明需要在数组前面添加一位
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main() {
    Solution solution;
    std::vector<int> digits = { 1, 2, 3 }; // 示例数组

    std::vector<int> result = solution.plusOne(digits);
    std::cout << "The result of adding one: ";
    for (int num : result) {
        std::cout << num;
    }
    std::cout << std::endl;

    return 0;
}