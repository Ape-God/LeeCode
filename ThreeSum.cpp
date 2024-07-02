#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		vector<vector<int>> ans;
		if (n < 3) {
			return ans;
		}
		for (int i = 0; i < n - 2; ++i) {
			int l = i + 1, r = n - 1;
			if (nums[i] > 0) {
				break;
			}
			while (l < r) {
				if (nums[l] + nums[r] == -nums[i]) { //ПаµИ
					ans.push_back({ nums[i],nums[l],nums[r] });
					while (l < r && nums[l] == nums[l + 1]) {
						++l;
					}
					while (l < r && nums[r] == nums[r - 1]) {
						--r;
					}
					++l;
					--r;
				}
				else if (nums[i] + nums[l] + nums[r] > 0) {
					--r;
				}
				else {
					++l;
				}
			}
			while (i + 1 < n && nums[i] == nums[i + 1]) {
				++i;
			}
		}
		return ans;
	}
};

int main() 
{
	Solution solution;
	vector<int> threesum = { -1,0,1,2,-1,-4 };
	vector<vector<int>> result;
	result = solution.threeSum(threesum);
	for (const auto& triplet : result) {
		for (int num : triplet) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}