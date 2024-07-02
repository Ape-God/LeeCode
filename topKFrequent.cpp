#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 主函数，用于找出出现频率前 k 高的元素
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; // 使用哈希表统计每个元素的出现次数
        for (int num : nums) {
            freqMap[num]++; // 增加对应元素的计数
        }

        // 使用向量存储元素及其出现次数，然后根据出现次数排序
        vector<pair<int, int>> freqPairs;
        for (auto& elem : freqMap) {
            freqPairs.emplace_back(elem.second, elem.first);
        }
        sort(freqPairs.rbegin(), freqPairs.rend()); // 降序排序

        vector<int> topK; // 存储出现频率前 k 高的元素
        for (int i = 0; i < k; ++i) {
            topK.push_back(freqPairs[i].second); // 添加元素到结果向量
        }

        return topK; // 返回结果向量
    }
};

class Solution {
public:
    // 定义比较函数，用于优先队列，确保出现次数更高的元素排在前面
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second; // 根据出现次数降序排列
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences; // 创建哈希表来存储每个元素的出现次数
        for (auto& v : nums) {
            occurrences[v]++; // 统计每个元素的出现次数
        }

        // 使用优先队列（最小堆）来存储元素及其出现次数
        // 优先队列的容量为 k，只保留出现次数最多的前 k 个元素
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                // 如果队列大小达到 k，并且当前元素的出现次数大于队尾元素的出现次数
                if (q.top().second < count) {
                    q.pop(); // 移除队尾元素
                    q.emplace(num, count); // 将当前元素加入队列
                }
            }
            else {
                q.emplace(num, count); // 将元素加入队列
            }
        }

        vector<int> ret; // 创建结果向量来存储出现次数最多的 k 个元素
        while (!q.empty()) {
            // 将队列中的元素按出现次数从高到低添加到结果向量
            ret.emplace_back(q.top().first);
            q.pop(); // 弹出队列顶部元素
        }
        // 由于我们从优先队列中弹出元素的顺序是出现次数从高到低，所以结果向量已经是正确顺序
        return ret;
    }
};


// 示例函数，用于演示 Solution 类的 topKFrequent 方法
int main() {
    Solution solution;
    // 创建示例数组和 k 值
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    // 调用 topKFrequent 方法并输出结果
    vector<int> topK = solution.topKFrequent(nums, k);
    cout << "The top " << k << " most frequent elements are: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}