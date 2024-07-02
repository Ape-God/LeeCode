#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1; // ���������һλ
            result |= (n & 1); // ��n�����λ��ӵ���������λ
            n >>= 1; // ��n����һλ��Ϊ��һ�ε�����׼��
        }
        return result;
    }
};

int main() {
    Solution solution;
    uint32_t number = 43261596; // ʾ������

    uint32_t reversed = solution.reverseBits(number);
    cout << "The reversed binary representation is: " << reversed << endl;

    return 0;
}