#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // 0 的平方根是 0

        long long start = 1, end = x; // 初始化搜索区间
        while (start <= end) { // 使用 while 循环进行二分查找
            long long mid = start + (end - start) / 2; // 计算中间值
            long long square = mid * mid; // 计算中间值的平方

            if (square == x) {
                return mid; // 如果完全平方，返回结果
            }
            else if (square < x) {
                start = mid + 1; // 如果平方小于 x，更新下界
            }
            else {
                end = mid - 1; // 如果平方大于 x，更新上界
            }
        }

        return end; // 由于 end 可能大于实际平方根，返回较小的整数解
    }
};

int main() {
    Solution solution;
    int x = 4;
    int result = solution.mySqrt(x);

    std::cout << "The square root of " << x << " is: " << result << std::endl;

    return 0;
}