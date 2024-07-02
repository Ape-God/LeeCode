#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 主函数，用于找出每个元素与其左侧所有元素的乘积，以及与其右侧所有元素的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // 获取输入数组的大小
        vector<int> answer(n, 1); // 初始化答案数组，所有元素先设为1

        // 计算左侧所有元素的乘积
        for (int i = 1; i < n; ++i) {
            // answer[i] 为当前元素之前所有元素的乘积
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int rightProduct = 1; // 初始化右侧元素乘积为1

        // 计算右侧所有元素的乘积，并更新答案数组
        for (int i = n - 1; i >= 0; --i) {
            // 将当前的右侧乘积累加到 answer[i] 上
            answer[i] *= rightProduct;
            // 更新右侧乘积
            rightProduct *= nums[i];
        }

        // 返回答案数组
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 2, 3, 4 };
    std::vector<int> product = solution.productExceptSelf(nums);

    std::cout << "Product of each element and its neighbors: ";
    for (int num : product) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}