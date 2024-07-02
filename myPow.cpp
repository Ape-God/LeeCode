#include <iostream>
#include <cmath> // 引入cmath库，用于使用pow函数

class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};


int main() {
    Solution solution;
    double x = 1.0; // 示例底数
    int n = -2147483648; // 示例指数

    double result = solution.myPow(x, n);
    std::cout << "The result of " << x << " raised to the power of " << n << " is: " << result << std::endl;

    return 0;
}