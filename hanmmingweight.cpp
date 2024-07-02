#include <iostream>
using namespace std;

//class Solution {
//public:
//    int hammingWeight(uint32_t n) {
//        int count = 0;
//        while (n) {
//            count += n & 1; // ������λ�Ƿ�Ϊ1
//            n >>= 1;        // ����һλ
//        }
//        return count;
//    }
//};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};


int main() {
    Solution solution;
    uint32_t number = 29; // ʾ��������������Ϊ 11101����3��1

    cout << "The number of 1's in the binary representation of " << number << " is: "
        << solution.hammingWeight(number) << endl;

    return 0;
}