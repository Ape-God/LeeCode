#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stockPrices; // ʹ��ջ�洢�۸�Ϳ��

public:
    // ���캯��
    StockSpanner() {
        // ��ʼ��ջ
    }

    // ��������Ĺɼ� price�����ظù�Ʊ���ռ۸�Ŀ��
    int next(int price) {
        int span = 1; // ��ʼ�����Ϊ1����ʾ������1�죨���죩
        // ����ջ��ֱ������һ�����ߵļ۸�
        while (!stockPrices.empty() && stockPrices.top().first <= price) {
            // ���¿��Ϊ��ǰ��ȼ�1��ȥջ���Ŀ��
            span += stockPrices.top().second;
            // ����ջ���ļ۸�Ϳ��
            stockPrices.pop();
        }
        // ������ļ۸�ͼ�����Ŀ��ѹ��ջ��
        stockPrices.push({ price, span });
        return span; // ���ؼ�����Ŀ��
    }
};

// ʾ��������������ʾ StockSpanner ��� next ����
int main() {
    StockSpanner* obj = new StockSpanner(); // ���� StockSpanner ����
    // ����һ��ʾ����Ʊ�۸�����
    vector<int> prices = { 100, 80, 60, 70, 60, 75, 85 };
    // �����۸����飬���� next ��������ӡ���
    for (int price : prices) {
        cout << "The span for the price " << price << " is: " << obj->next(price) << endl;
    }

    delete obj; // �ͷ� StockSpanner ����
    return 0;
}