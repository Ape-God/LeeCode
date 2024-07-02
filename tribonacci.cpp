#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算第 n 个泰波那契数
    int tribonacci(int n) {
        // 基础情况：如果 n 为 0，返回 0
        if (n == 0) {
            return 0;
        }
        // 基础情况：如果 n 为 1 或 2，返回 1
        if (n <= 2) {
            return 1;
        }

        // 初始化前三个泰波那契数
        int p = 0, q = 0, r = 1, s = 1; // p, q, r 用于迭代计算，s 存储当前的泰波那契数
        for (int i = 3; i <= n; ++i) {
            // 通过迭代计算第 i 个泰波那契数
            // 将前三个数向前移动，并将新的泰波那契数计算出来
            p = q; // p 存储 T(i-2) 的值
            q = r; // q 存储 T(i-1) 的值
            r = s; // r 存储 T(i-0) 的值
            s = p + q + r; // s 计算 T(i) 的值
        }

        // 返回第 n 个泰波那契数
        return s;
    }
};


// 示例函数，用于演示 Solution 类的 tribonacci 方法
int main() {
    Solution solution;
    // 调用 tribonacci 方法并输出结果
    for (int i = 0; i < 10; ++i) { // 测试前 10 个泰波那契数
        cout << "The 5th tribonacci number is: " << solution.tribonacci(i) << endl;
    }

    return 0;
}