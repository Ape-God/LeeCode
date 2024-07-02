#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // �������ļ۸������ߣ�˵������������������Ĺ�Ʊ
            if (prices[i] > prices[i - 1]) {
                // �����������������������
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 }; // ʾ���۸�����

    int result = solution.maxProfit(prices);
    cout << "The maximum profit from the stock transaction is: " << result << endl;

    return 0;
}