#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> num_map;
		for (int i = 0; i < nums.size(); i++) {
			int completement = target - nums[i];
			if (num_map.find(completement) != num_map.end()) {
				return {num_map[completement],i};
			}
			num_map[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	Solution solution;
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	vector<int> indices(2, 0);
	indices = solution.twoSum(nums, target);
	if (!indices.empty()) {
		cout << " Index 1: " << indices[0] << " Index 2: " << indices[1] << endl;
	}
	else {
		cout << "No sum solution found" << endl;
	}
	return 0;
}