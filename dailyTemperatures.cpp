#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // �����������ڼ���ÿ�����º������ָ��ߵ�����
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // ��ʼ�������飬���0
        stack<int> s; // ʹ��ջ�洢�������������

        for (int i = 0; i < temperatures.size(); ++i) {
            // ��ջ��Ϊ���ҵ�ǰ�¶ȸ���ջ��Ԫ�ض�Ӧ���¶�
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                // ����ջ��Ԫ�أ���������������´�����
                int index = s.top();
                s.pop();
                ans[index] = i - index;
            }
            // ����ǰ������ջ
            s.push(i);
        }

        return ans; // ���ش�����
    }
};

// ʾ��������������ʾ Solution ��� dailyTemperatures ����
int main() {
    Solution solution;
    // ����һ��ʾ����������
    vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
    // ���� dailyTemperatures ������������
    vector<int> ans = solution.dailyTemperatures(temperatures);
    cout << "Days after which a higher temperature will appear: ";
    for (int day : ans) {
        cout << day << " ";
    }
    cout << endl;

    return 0;
}