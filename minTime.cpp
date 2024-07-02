#include <iostream>

class Solution {
public:
    int totalTime(int n, int m, int k) {
        int time = 0;
        int cur = k; // ��ʼʱ��Ϊ k
        int cnt = 0; // ��ˢ����

        while (cnt < n) {
            time += cur; // �ۼӵ�ǰʱ��
            if (cur == m && cnt > 0) { // �����ǰ���ǵ� m �⣬������ˢ�������� 0
                break; // ֹͣˢ��
            }
            cur++; // ������һ��ʱ��
            cnt++; // ��ˢ������ 1
        }
        return time;
    }
};

int main() {
    Solution solution;
    int n = 5;
    int m = 3;
    int k = 1;
    int result = solution.totalTime(n, m, k);
    std::cout << "Total time needed is: " << result << std::endl;
    return 0;
}