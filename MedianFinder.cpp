#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // 最大堆，用于存储较小的半部分数值
    priority_queue<int, vector<int>, greater<int>> minHeap; // 最小堆，用于存储较大的半部分数值

public:
    MedianFinder() {}

    void addNum(int num) {
        // 将新数值加入最大堆
        maxHeap.push(num);
        // 将最大堆的根（当前较小半部分的最大值）移动到最小堆
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // 保持两个堆的大小差不超过1，以确保中位数的计算
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // 如果两个堆的大小相等，中位数是两个堆顶数值的平均值
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            // 如果最大堆的大小比最小堆大1，中位数是最大堆的堆顶数值
            return maxHeap.top();
        }
    }
};

// 示例函数，用于演示 MedianFinder 类的功能
int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << "The median is: " << obj->findMedian() << endl; // 应该输出 1.5

    obj->addNum(3);
    cout << "The median is: " << obj->findMedian() << endl; // 应该输出 2

    delete obj;
    return 0;
}