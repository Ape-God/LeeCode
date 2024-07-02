#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k) {
		unordered_set<int> s;
		int length = nums.size();
		for (int i = 0; i < length; ++i) {
			if (i > k) {
				s.erase(nums[i - k - 1]);
			}
			if (s.count(nums[i])) {
				return true;
			}
			s.emplace(nums[i]);
		}
		return false;
	}
};

int main()
{
	Solution solution;
	vector<int> duplicate{ 1,2,3,1 };
	int result = solution.containsNearbyDuplicate(duplicate, 3);
	cout << result << endl;
	return 0;
}