#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stockPrices; // 使用栈存储价格和跨度

public:
    // 构造函数
    StockSpanner() {
        // 初始化栈
    }

    // 给定今天的股价 price，返回该股票当日价格的跨度
    int next(int price) {
        int span = 1; // 初始化跨度为1，表示至少有1天（今天）
        // 遍历栈，直到遇到一个更高的价格
        while (!stockPrices.empty() && stockPrices.top().first <= price) {
            // 更新跨度为当前跨度加1减去栈顶的跨度
            span += stockPrices.top().second;
            // 弹出栈顶的价格和跨度
            stockPrices.pop();
        }
        // 将今天的价格和计算出的跨度压入栈中
        stockPrices.push({ price, span });
        return span; // 返回计算出的跨度
    }
};

// 示例函数，用于演示 StockSpanner 类的 next 方法
int main() {
    StockSpanner* obj = new StockSpanner(); // 创建 StockSpanner 对象
    // 给定一个示例股票价格数组
    vector<int> prices = { 100, 80, 60, 70, 60, 75, 85 };
    // 遍历价格数组，调用 next 方法并打印结果
    for (int price : prices) {
        cout << "The span for the price " << price << " is: " << obj->next(price) << endl;
    }

    delete obj; // 释放 StockSpanner 对象
    return 0;
}