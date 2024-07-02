#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; // �������Ϊ�գ�����0

        int maxProfit = 0;
        int minPrice = prices[0]; // ��ʼ����С�۸�Ϊ����ĵ�һ��Ԫ��

        // �����۸�����
        for (int i = 1; i < prices.size(); ++i) {
            // �����ǰ�۸�ȼ�¼����С�۸�ߣ�����Ƿ�����������
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            else {
                // �����ǰ�۸���ͣ�������С�۸�
                minPrice = prices[i];
            }
        }

        return maxProfit; // �����������
    }
};

int main() {
    Solution solution;
    vector<int> prices = { 7, 1, 5, 3, 6, 4 }; // ʾ���۸�����

    int result = solution.maxProfit(prices);
    cout << "The maximum profit from the stock transaction is: " << result << endl;

    return 0;
}