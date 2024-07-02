#include <iostream>
#include <string>
using namespace std;

//class Solution {
//public:
//    string addBinary(string a, string b) {
//        int carry = 0; // ��λ
//        int i = a.size() - 1;
//        int j = b.size() - 1;
//        string result;
//
//        while (i >= 0 || j >= 0 || carry) {
//            int sum = carry;
//            if (i >= 0) sum += a[i--] - '0'; // ���ַ�ת��Ϊ����
//            if (j >= 0) sum += b[j--] - '0'; // ͬ��
//
//            carry = sum / 2; // �����µĽ�λ
//            result.push_back((sum % 2) + '0'); // ���㵱ǰλ�Ľ������ӵ�����ַ���
//        }
//
//        // ��ת����ַ�������Ϊ�����Ǵ����λ��ʼ������
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size()), carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};



int main() {
    Solution solution;
    string a = "11"; // ʾ���������ַ���1
    string b = "1";  // ʾ���������ַ���2

    cout << "The sum of binary " << a << " and " << b << " is: "
        << solution.addBinary(a, b) << endl;

    return 0;
}