#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

//class Solution {
//public:
//    int compareVersion(string version1, string version2) {
//        // �ָ�汾���ַ���
//        vector<int> nums1, nums2;
//        istringstream v1(version1);
//        istringstream v2(version2);
//        string token;
//
//        // �����������
//        while (getline(v1, token, '.')) {
//            nums1.push_back(stoi(token));
//        }
//        while (getline(v2, token, '.')) {
//            nums2.push_back(stoi(token));
//        }
//
//        // ȷ���������鳤����ͬ
//        int n = max(nums1.size(), nums2.size());
//        nums1.resize(n, 0);
//        nums2.resize(n, 0);
//
//        // ���������αȽ��޶���
//        for (int i = 0; i < n; ++i) {
//            if (nums1[i] > nums2[i]) {
//                return 1;
//            }
//            else if (nums1[i] < nums2[i]) {
//                return -1;
//            }
//        }
//
//        // ��������޶��Ŷ���ȣ��򷵻�0
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
            ++i; // �������
            long long y = 0;
            for (; j < m && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // �������
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};




// �����������ڲ���
int main() {
    Solution solution;
    string version1 = "1.0";
    string version2 = "1.10";
    int result = solution.compareVersion(version1, version2);
    cout << "Comparing version \"" << version1 << "\" and \"" << version2 << "\" result: " << result << endl;

    return 0;
}