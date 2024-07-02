#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};


int main() {
    Solution solution;
    std::vector<int> nums = { 0, 1, 2, 4, 5, 7 };

    std::vector<std::string> summary = solution.summaryRanges(nums);

    for (const std::string& range : summary) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    for (const auto& i : nums) {
        string temp = to_string(i);
        temp.append("->");
        cout << temp << endl;
    }


    return 0;
}