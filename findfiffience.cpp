#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<iostream>
using namespace std;

//class Solution {
//public:
//    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//        unordered_map<int, int> count1; // ����ͳ�� nums1 ��ÿ�����ֵĳ��ִ���
//        unordered_map<int, int> count2; // ����ͳ�� nums2 ��ÿ�����ֵĳ��ִ���
//
//        // ͳ�� nums1 ��ÿ�����ֵĳ��ִ���
//        for (int num : nums1) {
//            count1[num]++;
//        }
//
//        // ͳ�� nums2 ��ÿ�����ֵĳ��ִ���
//        for (int num : nums2) {
//            count2[num]++;
//        }
//
//        // ���ڴ洢����������б�
//        vector<int> diff1, diff2;
//
//        // �ҳ�ֻ������ nums1 �е�����
//        for (const auto& pair : count1) {
//            if (count2.find(pair.first) == count2.end()) {
//                diff1.push_back(pair.first);
//            }
//        }
//
//        // �ҳ�ֻ������ nums2 �е�����
//        for (const auto& pair : count2) {
//            if (count1.find(pair.first) == count1.end()) {
//                diff2.push_back(pair.first);
//            }
//        }
//
//        // ���ذ��������б�Ĵ�
//        return { diff1, diff2 };
//    }
//};


class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1, set2;   // nums1 �� nums2 ����Ԫ�صĹ�ϣ����
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




// ʾ��������������ʾ Solution ��� findDifference ����
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