#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 2, 3, 2 }; // 示例数组，其中 3 只出现一次

    int single = solution.singleNumber(nums);
    cout << "The number that appears only once is: " << single << endl;

    return 0;
}