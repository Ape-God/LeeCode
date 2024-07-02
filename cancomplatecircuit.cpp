#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_tank = 0, current_tank = 0, start = 0;
        int curr_start = 0;

        for (int i = 0; i < n; ++i) {
            // �����������͵�ǰ����
            total_tank += gas[i] - cost[i];
            current_tank += gas[i] - cost[i];

            // �����ǰ���������Ե�����һ������վ�������µ���ʼ��
            if (current_tank < 0) {
                curr_start = i + 1;
                current_tank = 0;
            }
        }

        // ������������������һȦ������-1
        if (total_tank < 0) return -1;

        // ����������������ʼ����վ����
        return curr_start;
    }
};

int main() {
    Solution solution;
    vector<int> gas = { 1, 2 };
    vector<int> cost = { 2, 1 };

    int start = solution.canCompleteCircuit(gas, cost);
    cout << "The starting gas station is at index: " << start << endl;

    return 0;
}