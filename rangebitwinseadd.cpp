#include <iostream>
using namespace std;

//class Solution {
//public:
//    int rangeBitwiseAnd(int left, int right) {
//        int shift = 0;
//        // 找到left和right二进制表示的差异
//        while (left < right) {
//            left >>= 1;
//            right >>= 1;
//            ++shift;
//        }
//        // 将left左移回原来的位置，此时left和right的按位与操作的结果就是区间内所有数字的按位与结果
//        return left << shift;
//    }
//};

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == 0) {
            return 0;
        }
        while (left < right) {
            right &= (right - 1);
        }
        return right;
    }
};



//class Solution {
//public:
//    int rangeBitwiseAnd(int m, int n) {
//        int shift = 0;
//        // 找到公共前缀
//        while (m < n) {
//            m >>= 1;
//            n >>= 1;
//            ++shift;
//        }
//        return m << shift;
//    }
//};


int main() {
    Solution solution;
    int left = 5;  // 示例区间左端点
    int right = 7; // 示例区间右端点

    cout << "The bitwise AND of numbers in range [" << left << ", " << right << "] is: "
        << solution.rangeBitwiseAnd(left, right) << endl;

    return 0;
}