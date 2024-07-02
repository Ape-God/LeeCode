#include <iostream>

int trailingZeroes(int n) {
    int count = 0;
    // 从 5 开始，因为 2 的数量总是多于 5 的数量
    for (int i = 5; n / i >= 1; i *= 5) {
        count += n / i;
    }
    return count;
}

int main() {
    int n = 25;
    int result = trailingZeroes(n);
    std::cout << "The number of trailing zeroes in " << n << "! is: " << result << std::endl;
    return 0;
}