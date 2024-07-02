#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int total = 0;
        int prevValue = 0;

        for (int i = s.length() - 1; i >= 0; --i) {
            int currValue = romanMap[s[i]];
            if (currValue >= prevValue) {
                total += currValue;
            }
            else {
                total -= currValue;
            }
            prevValue = currValue;
        }

        return total;
    }
};

int main() {
    Solution solution;
    std::string s = "MCMXCIV";
    int result = solution.romanToInt(s);
    std::cout << "The integer representation of " << s << " is: " << result << std::endl;
    return 0;
}