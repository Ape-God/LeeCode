#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

//class Solution {
//public:
//    vector<int> findRightInterval(vector<vector<int>>& intervals) {
//        vector<pair<int, int>> startIntervals;
//        int n = intervals.size();
//        for (int i = 0; i < n; i++) {
//            startIntervals.emplace_back(intervals[i][0], i);
//        }
//        sort(startIntervals.begin(), startIntervals.end());
//
//        vector<int> ans(n, -1);
//        for (int i = 0; i < n; i++) {
//            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
//            if (it != startIntervals.end()) {
//                ans[i] = it->second;
//            }
//        }
//        return ans;
//    }
//};



class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());

        vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; i++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j++;
            }
            if (j < n) {
                ans[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return ans;
    }
};




// 示例
int main() {
    vector<vector<int>> intervals = { {3, 10}, {2, 6}, {1, 5} };
    Solution solution;
    vector<int> result = solution.findRightInterval(intervals);
    // 打印结果
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}