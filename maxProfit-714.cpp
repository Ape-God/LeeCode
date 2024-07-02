#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڼ����������
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        long long cash = 0, hold = -prices[0]; // ��ʼ��״̬��cashΪ0��holdΪ���ļ۸�0

        for (int i = 1; i < n; ++i) {
            // ���²����й�Ʊ���ֽ𣺿�����ǰһ�첻���е��ֽ𣬻����ǽ���Ʊ�����õ���Ǯ��ȥ������
            cash = max(cash, hold + prices[i] - fee);
            // ���³��й�Ʊ���ֽ𣺿�����ǰһ����е��ֽ𣬻������ò����й�Ʊ���ֽ��ȥ����Ĺ�Ʊ�۸�
            hold = max(hold, cash - prices[i]);
        }

        return static_cast<int>(cash); // ���ز����й�Ʊ���ֽ���Ϊ�������
    }
};

// ʾ��������������ʾ Solution ��� maxProfit ����
int main() {
    Solution solution;
    // ����һ��ʾ����Ʊ�۸������������
    vector<int> prices = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;
    // ���� maxProfit ������������
    cout << "Maximum profit: " << solution.maxProfit(prices, fee) << endl;

    return 0;
}