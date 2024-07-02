#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // 主函数，用于计算每个数字的二进制表示中1的个数
    vector<int> countBits(int n) {
        vector<int> ans(n + 1); // 创建一个长度为 n + 1 的数组
        for (int i = 0; i <= n; ++i) {
            ans[i] = bitsCount(i); // 计算数字 i 的二进制表示中1的个数
        }
        return ans; // 返回数组
    }

private:
    // 辅助函数，用于计算一个数字的二进制表示中1的个数
    int bitsCount(int num) {
        int count = 0; // 初始化计数器
        while (num > 0) { // 当数字大于0时
            count += num & 1; // 如果当前最低位是1，计数器加1
            num >>= 1; // 将数字右移一位
        }
        return count; // 返回计数器的值
    }
};

// 示例函数，用于演示 Solution 类的 countBits 方法
int main() {
    Solution solution;
    // 调用 countBits 方法并输出结果
    int n = 5;
    vector<int> ans = solution.countBits(n);
    cout << "Bits count for numbers 0 to " << n << " is: ";
    for (int i = 0; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}