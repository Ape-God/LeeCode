#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, bool> hashTable;
    vector<int> result;

    // ������ϣ��
    for (int num : nums1) {
        hashTable[num] = true;
    }

    // ���ҽ���
    for (int num : nums2) {
        if (hashTable.find(num) != hashTable.end()) {
            result.push_back(num); // ��ӵ��������
            hashTable.erase(num); // �ӹ�ϣ�����Ƴ���ȷ��Ψһ��
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