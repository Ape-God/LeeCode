#include <iostream>
using namespace std;

//class Solution {
//public:
//    int rangeBitwiseAnd(int left, int right) {
//        int shift = 0;
//        // �ҵ�left��right�����Ʊ�ʾ�Ĳ���
//        while (left < right) {
//            left >>= 1;
//            right >>= 1;
//            ++shift;
//        }
//        // ��left���ƻ�ԭ����λ�ã���ʱleft��right�İ�λ������Ľ�������������������ֵİ�λ����
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
//        // �ҵ�����ǰ׺
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
    int left = 5;  // ʾ��������˵�
    int right = 7; // ʾ�������Ҷ˵�

    cout << "The bitwise AND of numbers in range [" << left << ", " << right << "] is: "
        << solution.rangeBitwiseAnd(left, right) << endl;

    return 0;
}