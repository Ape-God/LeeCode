#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0; // 记录能够种植的花朵数量
        for (int i = 0; i < flowerbed.size(); ++i) {
            // 检查当前位置是否为空（0），并且左右位置（如果有的话）也是空的
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                // 如果可以种植，将当前位置设置为1，并增加花朵数量
                flowerbed[i] = 1;
                count++;
                // 如果已经种植了足够的花朵，提前返回true
                if (count >= n) {
                    return true;
                }
            }
        }
        // 如果没有足够的位置种植花朵，返回false
        return count >= n;
    }
};

// 测试函数
void testSolution(Solution& solution, vector<int>& flowerbed, int n) {
    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << "Can place " << n << " flowers? " << (result ? "Yes" : "No") << endl;
}

int main() {
    Solution solution;
    vector<int> flowerbed1 = { 1, 0, 0, 0, 1, 0, 0 };
    int n1 = 2;
    testSolution(solution, flowerbed1, n1);

    vector<int> flowerbed2 = { 1, 0, 0, 0, 1, 0, 0 };
    int n2 = 3;
    testSolution(solution, flowerbed2, n2);

    return 0;
}