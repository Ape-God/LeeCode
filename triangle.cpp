#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int mininumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<int> f(n);
		f[0] = triangle[0][0];
		for (int i = 1; i < n; ++i) {
			f[i] = f[i - 1] + triangle[i][i];
			for (int j = i - 1; j > 0; --j) {
				f[j] = min(f[j], f[j - 1]) + triangle[i][j];
			}
			f[0] = f[0] + triangle[i][0];
		}
		return *min_element(f.begin(), f.end());
	}
};



int main()
{
	Solution solution;
	vector<vector<int>> triangle = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	int result = solution.mininumTotal(triangle);
	cout << "mininum path sum  == " << result << endl;
	return 0;
}