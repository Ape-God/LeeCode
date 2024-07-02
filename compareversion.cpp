#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//class Solution {
//public:
//    int compareVersion(string version1, string version2) {
//        // 分割版本号字符串
//        vector<int> nums1, nums2;
//        istringstream v1(version1);
//        istringstream v2(version2);
//        string token;
//
//        // 填充整数数组
//        while (getline(v1, token, '.')) {
//            nums1.push_back(stoi(token));
//        }
//        while (getline(v2, token, '.')) {
//            nums2.push_back(stoi(token));
//        }
//
//        // 确保两个数组长度相同
//        int n = max(nums1.size(), nums2.size());
//        nums1.resize(n, 0);
//        nums2.resize(n, 0);
//
//        // 从左到右依次比较修订号
//        for (int i = 0; i < n; ++i) {
//            if (nums1[i] > nums2[i]) {
//                return 1;
//            }
//            else if (nums1[i] < nums2[i]) {
//                return -1;
//            }
//        }
//
//        // 如果所有修订号都相等，则返回0
//        return 0;
//    }
//};




class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long long x = 0;
            for (; i < n && version1[i] != '.'; ++i) {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            long long y = 0;
            for (; j < m && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};




// 主函数，用于测试
int main() {
    Solution solution;
    string version1 = "1.0";
    string version2 = "1.10";
    int result = solution.compareVersion(version1, version2);
    cout << "Comparing version \"" << version1 << "\" and \"" << version2 << "\" result: " << result << endl;

    return 0;
}