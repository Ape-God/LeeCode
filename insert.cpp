#include <iostream>
#include <vector>
#include <algorithm> // ���� std::min �� std::max
using namespace std;

// �������ںϲ����䲢����������
//std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
//    std::vector<std::vector<int>> result;
//    int i = 0;
//
//    // ����ǰ����������н�����С��newInterval��ʼ�������
//    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
//        result.push_back(intervals[i]);
//        ++i;
//    }
//
//    // �����ص����䲢�ϲ�
//    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
//        newInterval[0] = std::min(newInterval[0], intervals[i][0]);
//        newInterval[1] = std::max(newInterval[1], intervals[i][1]);
//        ++i;
//    }
//
//    // ��Ӻϲ��������
//    result.push_back(newInterval);
//
//    // ���ʣ�������
//    for (; i < intervals.size(); ++i) {
//        result.push_back(intervals[i]);
//    }
//
//    return result;
//}

vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
    vector<vector<int>> ans;
    int n = a.size(), i = 0;
    while (i < n && a[i][1] < b[0]) {
        ans.push_back(a[i++]);
    }
    if (i < n) {
        b[0] = min(a[i][0], b[0]);
        while (i < n && a[i][0] <= b[1]) {
            b[1] = max(a[i++][1], b[1]);
        }
    }
    ans.push_back(b);
    while (i < n) {
        ans.push_back(a[i++]);
    }
    return ans;
}




// �����������ڲ���insert����
int main() {
    std::vector<std::vector<int>> intervals = { {1, 3}, {6, 9} };
    std::vector<int> newInterval = { 2, 5 };
    std::vector<std::vector<int>> updatedIntervals = insert(intervals, newInterval);

    // ��ӡ���
    for (const auto& interval : updatedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "]" << std::endl;
    }

    return 0;
}