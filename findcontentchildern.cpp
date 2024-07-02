#include <iostream>
#include <vector>
#include <algorithm> // ���� sort
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); // �Ժ��ӵ�θ��ֵ��������
        sort(s.begin(), s.end()); // �Ա��ɵĳߴ��������
        int i = 0, j = 0, count = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) { // ������ɳߴ��㹻
                count++;         // ���ӱ�����
                i++;             // �ƶ�����һ�����ӵ�θ��ֵ
                j++;             // �ƶ�����һ�����
            }
            else {
                j++; // ���򣬳�����һ�����
            }
        }
        return count; // ��������ĺ�������
    }
};

// �����������ڲ���
int main() {
    Solution solution;
    vector<int> g = { 1, 2, 3 };
    vector<int> s = { 1, 1 };
    cout << "Number of content children: " << solution.findContentChildren(g, s) << endl; // Ӧ��� 1

    return 0;
}