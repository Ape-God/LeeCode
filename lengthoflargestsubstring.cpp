#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, char> charIndexMap;
        int maxlength = 0;
        int start = 0;
        
        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = end;
            maxlength = max(maxlength, end - start + 1);
        }
        return maxlength;
    }
};

int main() {
    Solution solution;
    std::string input = "abcabcbb";
    int length = solution.lengthOfLongestSubstring(input);
    std::cout << "The length of the longest substring without repeating characters is: " << length << std::endl;
    return 0;
}