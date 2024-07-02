#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;

        int n = ratings.size();
        vector<int> candies(n, 1); // 初始化每个孩子至少获得1颗糖果

        // 从左到右遍历，保证评分更高的孩子获得更多的糖果
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历，调整糖果数量以满足评分更高的孩子获得更多的糖果
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
            }
        }

        // 计算并返回总糖果数
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};


//class Solution {
//public:
//    int candy(vector<int>& ratings) {
//        int n = ratings.size();
//        vector<int> left(n);
//        for (int i = 0; i < n; i++) {
//            if (i > 0 && ratings[i] > ratings[i - 1]) {
//                left[i] = left[i - 1] + 1;
//            }
//            else {
//                left[i] = 1;
//            }
//        }
//        int right = 0, ret = 0;
//        for (int i = n - 1; i >= 0; i--) {
//            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
//                right++;
//            }
//            else {
//                right = 1;
//            }
//            ret += max(left[i], right);
//        }
//        return ret;
//    }
//};



int main() {
    // 创建Solution对象
    Solution solution;

    // 测试用例
    //vector<int> ratings = { 1, 0, 2, 1, 3, 2, 3, 4, 1 };
    vector<int> ratings = { 1, 0, 2 };
    // 调用candy函数并输出结果
    int result = solution.candy(ratings);
    cout << "Total candies needed: " << result << endl;

    return 0;
}