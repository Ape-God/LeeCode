#include <vector>
#include <algorithm> // 用于max函数
#include <iostream>
using namespace std;

class Solution {
public:
    // 计算最高海拔
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0; // 用于记录最高海拔
        int currentAltitude = 0; // 当前海拔，初始为0

        // 遍历海拔高度差数组
        for (int i = 0; i < gain.size(); ++i) {
            // 更新当前海拔高度
            currentAltitude += gain[i];
            // 更新最高海拔高度
            highestAltitude = max(highestAltitude, currentAltitude);
        }

        // 返回计算出的最高海拔高度
        return highestAltitude;
    }
};

// 示例调用
int main() {
    Solution solution;
    vector<int> gain = { -5, 1, 5, 0, -7 }; // 示例输入

    int highestAltitude = solution.largestAltitude(gain); // 调用函数计算最高海拔
    cout << "The highest altitude is: " << highestAltitude << endl; // 输出最高海拔

    return 0;
}