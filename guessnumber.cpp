#include <iostream>
using namespace std;

// 假设这是预先定义好的接口
int guess(int num) {
    // 这里是模拟实现，实际的实现会根据游戏的规则返回-1, 1, 或 0
    int picked = 42; // 假设正确答案是42
    if (num == picked) {
        return 0;
    }
    else if (num > picked) {
        return -1;
    }
    else {
        return 1;
    }
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) { // 循环直至区间左右端点相同
            int mid = left + (right - left) / 2; // 防止计算时溢出
            if (guess(mid) <= 0) {
                right = mid; // 答案在区间 [left, mid] 中
            }
            else {
                left = mid + 1; // 答案在区间 [mid+1, right] 中
            }
        }
        // 此时有 left == right，区间缩为一个点，即为答案
        return left;
    }
};


// 测试函数
void testSolution(Solution& solution, int n) {
    int result = solution.guessNumber(n);
    cout << "The picked number is: " << result << endl;
}

int main() {
    Solution solution;
    int n = 100; // 假设n为100
    testSolution(solution, n);

    return 0;
}