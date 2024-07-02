#include <string>
#include <stack>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for (auto& digit : num) {
            while (stk.size() > 0 && stk.back() > digit && k) {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k) {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto& digit : stk) {
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};


// ʾ��
int main() {
    std::string num = "1432219";
    int k = 3;
    Solution solution;
    std::string smallest = solution.removeKdigits(num, k);
    std::cout << "The smallest number after removing K digits is: " << smallest << std::endl;
    return 0;
}