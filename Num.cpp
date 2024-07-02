#include<iostream>
#include<vector>
using namespace std;

//给定一个整数数组，找到一个具有最和的连续子数组，返回最大和


//class Solution {
//public:
//	int numvector(vector<int> & nums) {
//		int ret = 0;
//		if (nums.size() == 0) {
//			return 0;
//		}
//		if (nums.size() == 1) {
//			return nums[0];
//		}
//		int n = nums.size();
//		int left = 0;
//		int right = 1;
//		vector<int> ans;
//		int i = 0;
//		for (left = 0; left < n; ++left) {
//			int temp = 0;
//			while (nums[left] + nums[right] > temp) {
//				temp = nums[left] + nums[right];
//				right++;
//			}
//			left++;
//			ans[i] = temp;
//
//
//		}
//		//return ret;
//
//	}
//};



//class Solution {
//public:
//    int maxSubArray(vector<int>& nums) {
//        int pre = 0, maxAns = nums[0];
//        for (const auto& x : nums) {
//            pre = max(pre + x, x);
//            maxAns = max(maxAns, pre);
//        }
//        return maxAns;
//    }
//};

class Solution {
public:
    int maxSubArraySum(const vector<int>& nums) {
        if (nums.empty()) return 0;

        int max_so_far = nums[0];
        int current_max = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            current_max = max(nums[i], current_max + nums[i]);
            max_so_far = max(max_so_far, current_max);
        }

        return max_so_far;
    }
};


int main() {
    vector<int> nums = { 1,4,5,6,2,6,1,6,8,3,5,8,23,234,65,1,5,77,76,8,3,3,5,65,4,32,35,6,8,3,5,356,365 };
    Solution solution;
    int ret = solution.maxSubArraySum(nums);
    cout << ret << endl;
    return 0;
}