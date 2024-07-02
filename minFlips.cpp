#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 主函数，用于计算最小翻转次数
    int minFlips(int a, int b, int c) {
        int ans = 0; // 初始化翻转次数的累计变量
        // 遍历所有可能的位（从0到30，因为int是32位的）
        for (int i = 0; i < 31; ++i) {
            // 获取a的当前位
            int bit_a = (a >> i) & 1;
            // 获取b的当前位
            int bit_b = (b >> i) & 1;
            // 获取c的当前位
            int bit_c = (c >> i) & 1;

            // 如果c的当前位是0，那么a和b的当前位必须都是0或1，翻转次数加a和b当前位为1的个数
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            }
            // 如果c的当前位是1，那么a和b的当前位必须至少有一个是1，翻转次数加a和b当前位为0的次数
            else {
                ans += (bit_a + bit_b == 0);
            }
        }
        return ans; // 返回总翻转次数
    }
};

// 示例函数，用于演示 Solution 类的 minFlips 方法
int main() {
    Solution solution;
    // 调用 minFlips 方法并输出结果
    int a = 2;
    int b = 6;
    int c = 5;
    cout << "Minimum flips needed: " << solution.minFlips(a, b, c) << endl;

    return 0;
}