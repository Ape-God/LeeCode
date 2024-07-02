#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int result = 0;
//        for (int i = 0; i < 32; ++i) {  // 对于int类型，最多32位
//            int count = 0;
//            // 第一次遍历，计算第i位为1的个数
//            for (const int num : nums) {
//                if ((num >> i) & 1) {
//                    count++;
//                }
//            }
//            // 如果个数不是3的倍数，将第i位加到结果上
//            if (count % 3 != 0) {
//                result |= (1 << i);
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto  [num, occ] : freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};




int main() {
    Solution solution;
    vector<int> nums = { 30000, 500, 100, 30000, 100, 30000, 100 }; // 示例数组

    int single = solution.singleNumber(nums);
    cout << "The number that appears only once is: " << single << endl;

    return 0;
}