#include <iostream>
#include <queue>
#include <utility> // ���� swap
using namespace std;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;

public:
    /** Initialize your data structure here. */
    MyStack() {
    }

    /** Push element x onto stack. */
    void push(int x) {
        // ��Ԫ����ӵ� queue2
        queue2.push(x);
        // ��� queue1 ��Ϊ�գ��� queue1 �е�Ԫ���ƶ��� queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        // ���� queue1 �� queue2��ʹ queue1 ��Ϊ�洢��Ԫ�صĶ���
        swap(queue1, queue2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // ��� queue1 Ϊ�գ�˵��ջΪ��
        if (queue1.empty()) {
            throw runtime_error("Stack is empty");
        }
        // �� queue1 ��ǰ���Ƴ�������Ԫ��
        int topElement = queue1.front();
        queue1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        // ��� queue1 Ϊ�գ�˵��ջΪ��
        if (queue1.empty()) {
            throw runtime_error("Stack is empty");
        }
        // ���� queue1 ��ǰ��Ԫ��
        return queue1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        // ����������ж�Ϊ�գ���ջΪ��
        return queue1.empty() && queue2.empty();
    }
};

// �����������ڲ���
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << "Top: " << obj->top() << endl;    // Ӧ��� 2
    cout << "Pop: " << obj->pop() << endl;     // Ӧ��� 2
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Ӧ��� No
    obj->push(3);
    cout << "Top after pushing 3: " << obj->top() << endl; // Ӧ��� 3

    delete obj; // �ͷ� MyStack ����
    return 0;
}