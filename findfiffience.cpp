#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<iostream>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int, int> count1; // 用于统计 nums1 中每个数字的出现次数
//        unordered_map<int, int> count2; // 用于统计 nums2 中每个数字的出现次数
//
//        // 统计 nums1 中每个数字的出现次数
//        for (int num : nums1) {
//            count1[num]++;
//        }
//
//        // 统计 nums2 中每个数字的出现次数
//        for (int num : nums2) {
//            count2[num]++;
//        }
//
//        // 用于存储结果的两个列表
//        vector<int> diff1, diff2;
//
//        // 找出只出现在 nums1 中的数字
//        for (const auto& pair : count1) {
//            if (count2.find(pair.first) == count2.end()) {
//                diff1.push_back(pair.first);
//            }
//        }
//
//        // 找出只出现在 nums2 中的数字
//        for (const auto& pair : count2) {
//            if (count1.find(pair.first) == count1.end()) {
//                diff2.push_back(pair.first);
//            }
//        }
//
//        // 返回包含两个列表的答案
//        return { diff1, diff2 };
//    }
//};


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;   // nums1 与 nums2 所有元素的哈希集合
        for (int num : nums1) {
            set1.insert(num);
        }
        for (int num : nums2) {
            set2.insert(num);
        }
        vector<vector<int>> res(2);
        for (int num : set1) {
            if (!set2.count(num)) {
                res[0].push_back(num);
            }
        }
        for (int num : set2) {
            if (!set1.count(num)) {
                res[1].push_back(num);
            }
        }
        return res;
    }
};




// 示例函数，用于演示 Solution 类的 findDifference 方法
int main() {
    Solution solution;
    vector<int> nums1 = { 1, 2, 3, 4, 5 };
    vector<int> nums2 = { 3, 4, 5, 6, 7 };
    auto result = solution.findDifference(nums1, nums2);

    cout << "Elements in nums1 but not in nums2: ";
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << "\nElements in nums2 but not in nums1: ";
    for (int num : result[1]) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}