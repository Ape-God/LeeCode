#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1; // ��ʼ����λΪ1
        int n = digits.size();

        // �����λ��ʼ��������
        for (int i = n - 1; i >= 0 && carry; --i) {
            // ����ǰλ���λ��ӣ��õ��µ�λֵ
            int sum = digits[i] + carry;
            // ���������еĵ�ǰλ
            digits[i] = sum % 10;
            // ���½�λ
            carry = sum / 10;
        }

        // �����λ��Ϊ0��˵����Ҫ������ǰ�����һλ
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};

int main() {
    Solution solution;
    std::vector<int> digits = { 1, 2, 3 }; // ʾ������

    std::vector<int> result = solution.plusOne(digits);
    std::cout << "The result of adding one: ";
    for (int num : result) {
        std::cout << num;
    }
    std::cout << std::endl;

    return 0;
}