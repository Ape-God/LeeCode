#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = m - 1;
		int p2 = m - 1;
		int p = n + m - 1;
		while (p1 >= 0 && p2 >= 0) {
			if (nums1[p1] > nums2[p2]) {
				nums1[p--] = nums1[p1--];
			}
			else {
				nums1[p--] = nums2[p2--];
			}
		}
		if (p2 >= 0) {
			nums1[p--] = nums2[p2--];
		}
	}
};


int main() {
	 vector<int> nums1 = { 1,2,3,0,0,0 };
	 vector<int> nums2 = { 2,5,6 };
	 int m = 3;
	 int n = 3;
	 Solution solution;
	 solution.merge(nums1, m, nums2, n);
	 for (int num : nums1) {
		 cout << num << " ";
	 }
	 cout << endl;

	 return 0;
}