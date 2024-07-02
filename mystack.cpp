#include <iostream>
#include <queue>
#include <utility> // 用于 swap
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
        // 将元素添加到 queue2
        queue2.push(x);
        // 如果 queue1 不为空，将 queue1 中的元素移动到 queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        // 交换 queue1 和 queue2，使 queue1 成为存储新元素的队列
        swap(queue1, queue2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        // 如果 queue1 为空，说明栈为空
        if (queue1.empty()) {
            throw runtime_error("Stack is empty");
        }
        // 从 queue1 的前端移除并返回元素
        int topElement = queue1.front();
        queue1.pop();
        return topElement;
    }

    /** Get the top element. */
    int top() {
        // 如果 queue1 为空，说明栈为空
        if (queue1.empty()) {
            throw runtime_error("Stack is empty");
        }
        // 返回 queue1 的前端元素
        return queue1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        // 如果两个队列都为空，则栈为空
        return queue1.empty() && queue2.empty();
    }
};

// 主函数，用于测试
int main() {
    MyStack* obj = new MyStack();
    obj->push(1);
    obj->push(2);
    cout << "Top: " << obj->top() << endl;    // 应输出 2
    cout << "Pop: " << obj->pop() << endl;     // 应输出 2
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // 应输出 No
    obj->push(3);
    cout << "Top after pushing 3: " << obj->top() << endl; // 应输出 3

    delete obj; // 释放 MyStack 对象
    return 0;
}