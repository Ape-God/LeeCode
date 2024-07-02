#include <iostream>
#include <vector>
#include <algorithm> // ���� sort �� max

using namespace std;

// �������ںϲ������ص�������
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // �����������Ϊ�գ�ֱ�ӷ��ؿ�����
    if (intervals.empty()) return {};

    // ������ʼ�˵�������������
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged; // �洢�ϲ��������
    // ����һ��������뵽merged����
    merged.push_back(intervals[0]);

    // �����������飬�ӵڶ������俪ʼ
    for (const auto& interval : intervals) {
        // �����ǰ�������ʼ�˵����merged���������һ������Ľ����˵�
        if (interval[0] > merged.back()[1]) {
            // ���ص���ֱ����ӵ�merged����
            merged.push_back(interval);
        }
        else {
            // ���򣬺ϲ���ǰ������merged���������һ������
            // ����merged���������һ������Ľ����˵�Ϊ����������������˵�
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged; // ���غϲ������������
}

class Solution {
public:
    // �ϲ��ص�������
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans; // �洢�ϲ��������
        // ���ȶ����䰴��ʼλ�ý�������
        sort(intervals.begin(), intervals.end());

        // ��ʼ����һ���������ʼ�ͽ���λ��
        int start = intervals[0][0], end = intervals[0][1];

        // ��������������
        for (int i = 1; i < intervals.size(); ++i) {
            // �����ǰ�������ʼλ�ô�����һ������Ľ���λ��
            if (intervals[i][0] > end) {
                // ����ǰ������������飬��������ʼ�ͽ���λ��
                ans.push_back({ start, end });
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                // ������ص������½���λ��Ϊ�����������λ�õ����ֵ
                end = max(end, intervals[i][1]);
            }
        }
        // �����һ���������������
        ans.push_back({ start, end });
        return ans; // ���غϲ��������
    }
};



// �����������ڲ���merge����
int main() {
    vector<vector<int>> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
    vector<vector<int>> mergedIntervals = merge(intervals);

    // ��ӡ���
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}