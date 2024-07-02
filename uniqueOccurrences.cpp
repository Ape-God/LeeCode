#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // ʹ�ù�ϣ��ͳ��������ÿ�����ֵĳ��ִ���
        unordered_map<int, int> occurrences;
        for (int num : arr) {
            occurrences[num]++;
        }

        // ����һ���������洢��ͬ���ִ�����ֵ
        unordered_set<int> uniqueCounts;
        for (const auto& pair : occurrences) {
            uniqueCounts.insert(pair.second); // ֻ������ִ���
        }

        // ������ϵĴ�С���ϣ��Ĵ�С��ͬ��˵��ÿ�����ĳ��ִ������Ƕ�һ�޶���
        return uniqueCounts.size() == occurrences.size();
    }
};

int main() {
    Solution solution;
    // ����ʾ������
    vector<int> arr1 = { 1, 2, 2, 3, 3 };
    vector<int> arr2 = { 1, 2, 3, 4, 4, 4 };

    // ���� uniqueOccurrences ������������
    cout << "Array 1 has " << (solution.uniqueOccurrences(arr1) ? "unique" : "non-unique") << " occurrences." << endl;
    cout << "Array 2 has " << (solution.uniqueOccurrences(arr2) ? "unique" : "non-unique") << " occurrences." << endl;

    return 0;
}