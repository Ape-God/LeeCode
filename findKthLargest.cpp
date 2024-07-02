#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

int findKthLargest(vector<int>& nums, int k);

class Solution {
public:
	//int findKthLargest(std::vector<int>& nums, int k) {
	//	std::sort(nums.begin(), nums.end(), std::greater<int>());
	//	return nums[k - 1];
	//}

	int findKthLargest(vector<int>& nums, int k)
	{
		priority_queue<int, vector<int>, greater<int> > maxHeap;

		for (int i = 0; i < k; ++i) {
			maxHeap.push(nums[i]);
		}

		for (int i = k; i < nums.size(); ++i) {
			if (nums[i] > maxHeap.top()) {
				maxHeap.pop();
				maxHeap.push(nums[i]);
			}
		}

		return maxHeap.top();
	}


};


int main()
{
	vector<int> nums = { 3,2,1,5,6,4,7,10,1,7,19,16,15,112 };
	int k = 8;
	Solution solution;
	int KthLargest = solution.findKthLargest(nums, 8);


	/*int KthLargest = findKthLargest(nums, k);*/
	cout << "The" << k << " th largest element is :" << KthLargest << endl;

	return 0;
}





