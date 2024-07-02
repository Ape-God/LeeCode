#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        string res = "";
        for (size_t i = 0; i < roman.size(); ++i) {
            while (num >= roman[i].first) {
                res += roman[i].second;
                num -= roman[i].first;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    int num = 1994;
    string roman = solution.intToRoman(num);
    cout << "The Roman numeral representation of " << num << " is: " << roman << endl;
    return 0;
}