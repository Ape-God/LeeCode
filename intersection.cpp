#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, bool> hashTable;
    vector<int> result;

    // 创建哈希表
    for (int num : nums1) {
        hashTable[num] = true;
    }

    // 查找交集
    for (int num : nums2) {
        if (hashTable.find(num) != hashTable.end()) {
            result.push_back(num); // 添加到结果数组
            hashTable.erase(num); // 从哈希表中移除，确保唯一性
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = { 1, 2, 2, 3 };
    vector<int> nums2 = { 2, 3, 4 };
    vector<int> intersect = intersection(nums1, nums2);

    cout << "Intersection of the two arrays is: ";
    for (int num : intersect) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}