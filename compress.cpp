#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <algorithm> // 用于 std::reverse

using namespace std;

class Solution {
public:
    // 主函数，用于压缩字符串中的字符并添加计数
    int compress(vector<char>& chars) {
        int n = chars.size(); // 获取字符数组的长度
        int write = 0, left = 0; // 初始化写入位置和序列的起始位置
        for (int read = 0; read < n; ++read) { // 遍历字符数组
            // 如果到达字符串末尾或当前字符与下一个字符不同
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                // 将当前字符复制到 write 位置
                chars[write++] = chars[read];
                // 计算当前字符连续出现的次数
                int num = read - left + 1;
                // 如果连续出现次数大于1，则需要添加计数
                if (num > 1) {
                    // 记录计数将要开始的位置
                    int anchor = write;
                    // 将连续出现次数转换为字符并添加到数组中
                    while (num > 0) {
                        chars[write++] = num % 10 + '0'; // 转换当前最低位数字并添加到字符数组
                        num /= 10; // 移除已处理的最低位
                    }
                    // 反转计数字符，使其从低到高
                    reverse(&chars[anchor], &chars[write]);
                }
                // 更新序列的起始位置
                left = read + 1;
            }
        }
        // 返回压缩后的字符串长度
        return write;
    }
};


// 测试函数
void testSolution(Solution& solution, vector<char>& chars) {
    int newSize = solution.compress(chars);
    cout << "Compressed size: " << newSize << ", Array: [";
    for (int i = 0; i < newSize; ++i) {
        cout << chars[i];
        if (i < newSize - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    vector<char> chars1 = { 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c' };
    testSolution(solution, chars1);

    vector<char> chars2 = { 'a' };
    testSolution(solution, chars2);

    return 0;
}