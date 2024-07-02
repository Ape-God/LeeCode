#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1; // 将结果左移一位
            result |= (n & 1); // 将n的最低位添加到结果的最低位
            n >>= 1; // 将n右移一位，为下一次迭代做准备
        }
        return result;
    }
};

int main() {
    Solution solution;
    uint32_t number = 43261596; // 示例整数

    uint32_t reversed = solution.reverseBits(number);
    cout << "The reversed binary representation is: " << reversed << endl;

    return 0;
}