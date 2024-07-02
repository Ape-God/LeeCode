#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 使用哈希表统计数组中每个数字的出现次数
        unordered_map<int, int> occurrences;
        for (int num : arr) {
            occurrences[num]++;
        }

        // 创建一个集合来存储不同出现次数的值
        unordered_set<int> uniqueCounts;
        for (const auto& pair : occurrences) {
            uniqueCounts.insert(pair.second); // 只插入出现次数
        }

        // 如果集合的大小与哈希表的大小相同，说明每个数的出现次数都是独一无二的
        return uniqueCounts.size() == occurrences.size();
    }
};

int main() {
    Solution solution;
    // 创建示例数组
    vector<int> arr1 = { 1, 2, 2, 3, 3 };
    vector<int> arr2 = { 1, 2, 3, 4, 4, 4 };

    // 调用 uniqueOccurrences 方法并输出结果
    cout << "Array 1 has " << (solution.uniqueOccurrences(arr1) ? "unique" : "non-unique") << " occurrences." << endl;
    cout << "Array 2 has " << (solution.uniqueOccurrences(arr2) ? "unique" : "non-unique") << " occurrences." << endl;

    return 0;
}