#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits> // 用于INT_MAX
#include <string> // 用于std::string和to_string函数
#include <numeric> // 如果使用C++17标准的std::gcd函数
using namespace std;

//class Solution {
//private:
//    int gcd(int a, int b) {
//        return b ? gcd(b, a % b) : a;
//    }
//
//public:
//    int maxPoints(vector<vector<int>>& points) {
//        int n = points.size();
//        if (n <= 2) return n;
//
//        int ret = 0;
//        for (int i = 0; i < n; ++i) {
//            int maxCount = 0;
//            unordered_map<int, int> slopes; // 存储斜率和出现的次数
//            int vertical = 0; // 垂直线上的点的数量
//
//            for (int j = i + 1; j < n; ++j) {
//                int xDiff = points[j][0] - points[i][0];
//                int yDiff = points[j][1] - points[i][1];
//
//                if (xDiff == 0) {
//                    vertical++; // 同一垂直线上的点
//                }
//                else {
//                    int slope = yDiff / gcd(abs(xDiff), abs(yDiff)); // 斜率
//                    int key = (xDiff < 0) ? -slope : slope; // 斜率的正负
//                    slopes[key]++;
//                }
//            }
//
//            // 遍历斜率map，找到最大数量的点
//            for (auto& slope : slopes) {
//                maxCount = max(maxCount, slope.second + 1);
//            }
//            maxCount += vertical; // 加上垂直线上的点
//
//            ret = max(ret, maxCount); // 更新最多的点数
//        }
//        return ret;
//    }
//};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> h;
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                string key = calc(x1, y1, x2, y2);
                h[key]++;
                cnt = max(cnt, h[key]);
            }
            ans = max(ans, cnt + 1);
        }
        return ans;
    }

    string calc(int x1, int y1, int x2, int y2) {
        int dx = abs(x1 - x2), dy = abs(y1 - y2);
        int k = gcd(dx, dy);
        string key = to_string(dy / k) + "_" + to_string(dx / k);
        if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)) {
            return "-" + key;
        }
        return key;
    }
};



int main() {
    Solution solution;
    vector<vector<int>> points = { {1,1}, {2,2}, {3,3}, {4,4} }; // 示例点集

    int result = solution.maxPoints(points);
    cout << "The maximum number of points on the same straight line is: " << result << endl;

    return 0;
}