#include <iostream>

class Solution {
public:
    int totalTime(int n, int m, int k) {
        int time = 0;
        int cur = k; // 初始时刻为 k
        int cnt = 0; // 已刷题数

        while (cnt < n) {
            time += cur; // 累加当前时刻
            if (cur == m && cnt > 0) { // 如果当前题是第 m 题，并且已刷题数大于 0
                break; // 停止刷题
            }
            cur++; // 进入下一个时刻
            cnt++; // 已刷题数加 1
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