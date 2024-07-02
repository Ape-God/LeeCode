#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // �������������ҳ�����Ƶ��ǰ k �ߵ�Ԫ��
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap; // ʹ�ù�ϣ��ͳ��ÿ��Ԫ�صĳ��ִ���
        for (int num : nums) {
            freqMap[num]++; // ���Ӷ�ӦԪ�صļ���
        }

        // ʹ�������洢Ԫ�ؼ�����ִ�����Ȼ����ݳ��ִ�������
        vector<pair<int, int>> freqPairs;
        for (auto& elem : freqMap) {
            freqPairs.emplace_back(elem.second, elem.first);
        }
        sort(freqPairs.rbegin(), freqPairs.rend()); // ��������

        vector<int> topK; // �洢����Ƶ��ǰ k �ߵ�Ԫ��
        for (int i = 0; i < k; ++i) {
            topK.push_back(freqPairs[i].second); // ���Ԫ�ص��������
        }

        return topK; // ���ؽ������
    }
};

class Solution {
public:
    // ����ȽϺ������������ȶ��У�ȷ�����ִ������ߵ�Ԫ������ǰ��
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second; // ���ݳ��ִ�����������
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences; // ������ϣ�����洢ÿ��Ԫ�صĳ��ִ���
        for (auto& v : nums) {
            occurrences[v]++; // ͳ��ÿ��Ԫ�صĳ��ִ���
        }

        // ʹ�����ȶ��У���С�ѣ����洢Ԫ�ؼ�����ִ���
        // ���ȶ��е�����Ϊ k��ֻ�������ִ�������ǰ k ��Ԫ��
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                // ������д�С�ﵽ k�����ҵ�ǰԪ�صĳ��ִ������ڶ�βԪ�صĳ��ִ���
                if (q.top().second < count) {
                    q.pop(); // �Ƴ���βԪ��
                    q.emplace(num, count); // ����ǰԪ�ؼ������
                }
            }
            else {
                q.emplace(num, count); // ��Ԫ�ؼ������
            }
        }

        vector<int> ret; // ��������������洢���ִ������� k ��Ԫ��
        while (!q.empty()) {
            // �������е�Ԫ�ذ����ִ����Ӹߵ�����ӵ��������
            ret.emplace_back(q.top().first);
            q.pop(); // �������ж���Ԫ��
        }
        // �������Ǵ����ȶ����е���Ԫ�ص�˳���ǳ��ִ����Ӹߵ��ͣ����Խ�������Ѿ�����ȷ˳��
        return ret;
    }
};


// ʾ��������������ʾ Solution ��� topKFrequent ����
int main() {
    Solution solution;
    // ����ʾ������� k ֵ
    vector<int> nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    // ���� topKFrequent ������������
    vector<int> topK = solution.topKFrequent(nums, k);
    cout << "The top " << k << " most frequent elements are: ";
    for (int num : topK) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}