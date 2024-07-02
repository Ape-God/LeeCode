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
//        int minPrice = prices[0]; // ��ʼ����С�۸�Ϊ����ĵ�һ��Ԫ��
//        int maxProfit = 0; // ��������ʼ��Ϊ0
//
//        for (int i = 1; i < prices.size(); ++i) {
//            // �����ǰ�۸�����Ǽ�¼����С�۸�ҪС��������С�۸�
//            if (prices[i] < minPrice) {
//                minPrice = prices[i];
//            }
//            else {
//                // ���㵱ǰ�۸�����С�۸��ֵ�������������
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
        // ����prices���飬Ѱ��������������Ĳ�ֵ
        for (int i = 1; i < prices.size(); ++i) {
            // �����ǰ�۸������һ��ļ۸��ۼ�����
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