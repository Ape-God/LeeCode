#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // ���ѣ����ڴ洢��С�İ벿����ֵ
    priority_queue<int, vector<int>, greater<int>> minHeap; // ��С�ѣ����ڴ洢�ϴ�İ벿����ֵ

public:
    MedianFinder() {}

    void addNum(int num) {
        // ������ֵ��������
        maxHeap.push(num);
        // �����ѵĸ�����ǰ��С�벿�ֵ����ֵ���ƶ�����С��
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // ���������ѵĴ�С�����1����ȷ����λ���ļ���
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            // ��������ѵĴ�С��ȣ���λ���������Ѷ���ֵ��ƽ��ֵ
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            // ������ѵĴ�С����С�Ѵ�1����λ�������ѵĶѶ���ֵ
            return maxHeap.top();
        }
    }
};

// ʾ��������������ʾ MedianFinder ��Ĺ���
int main() {
    MedianFinder* obj = new MedianFinder();
    obj->addNum(1);
    obj->addNum(2);
    cout << "The median is: " << obj->findMedian() << endl; // Ӧ����� 1.5

    obj->addNum(3);
    cout << "The median is: " << obj->findMedian() << endl; // Ӧ����� 2

    delete obj;
    return 0;
}