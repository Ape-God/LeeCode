#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max 函数

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        // 初始化右边界为最大堆香蕉数
        for (int pile : piles) {
            right = max(right, pile);
        }
        // 使用二分查找最小速度 k
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 如果当前速度可以在 h 小时内吃完所有香蕉
            if (canEatAll(piles, h, mid)) {
                right = mid - 1; // 尝试更小的速度
            }
            else {
                left = mid + 1; // 需要更大的速度
            }
        }
        return left; // 返回找到的最小速度
    }

private:
    // 判断速度为 k 时，珂珂是否能在 h 小时内吃完所有香蕉
    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // 计算吃掉这堆香蕉需要的小时数
            if (hours > h) {
                return false; // 超出时间限制，返回 false
            }
        }
        return true; // 可以在 h 小时内吃完所有香蕉，返回 true
    }
};

// 示例函数
int main() {
    Solution solution;
    vector<int> piles = { 3, 6, 7, 11 };
    int h = 8;
    cout << "Minimum eating speed required: " << solution.minEatingSpeed(piles, h) << endl;
    return 0;
}