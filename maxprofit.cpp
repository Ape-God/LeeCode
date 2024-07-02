//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        if (prices.empty()) return 0;
//
//        int minPrice = prices[0]; // 初始化最小价格为数组的第一个元素
//        int maxProfit = 0; // 最大利润初始化为0
//
//        for (int i = 1; i < prices.size(); ++i) {
//            // 如果当前价格比我们记录的最小价格还要小，更新最小价格
//            if (prices[i] < minPrice) {
//                minPrice = prices[i];
//            }
//            else {
//                // 计算当前价格与最小价格差值，更新最大利润
//                maxProfit = max(maxProfit, prices[i] - minPrice);
//            }
//        }
//
//        return maxProfit;
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> prices = { 7, 1, 5, 3, 6, 4 };
//
//    int result = solution.maxProfit(prices);
//    cout << "The maximum profit is: " << result << endl;
//
//    return 0;
//}



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        // 遍历prices数组，寻找所有上升区间的差值
        for (int i = 1; i < prices.size(); ++i) {
            // 如果当前价格高于上一天的价格，累加利润
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 };

    int result = solution.maxProfit(prices);
    cout << "The maximum profit is: " << result << endl;

    return 0;
}