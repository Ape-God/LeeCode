#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num : nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};


int main() {
    Solution solution;
    std::vector<int> nums = { 3,2,3 };
    int majority = solution.majorityElement(nums);
    std::cout << "The majority element is: " << majority << std::endl;
    return 0;
}