#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    std::stack<int> inStack;  // 用于接收新元素
    std::stack<int> outStack; // 用于提供队列前端元素

    // 将 inStack 的元素移动到 outStack
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    // 构造函数
    MyQueue() {}

    // 入队操作，将元素 x 推到队列的末尾
    void push(int x) {
        inStack.push(x);
    }

    // 出队操作，从队列的开头移除并返回元素
    int pop() {
        if (outStack.empty()) {
            in2out(); // 如果 outStack 为空，则将 inStack 的元素移动过来
        }
        if (outStack.empty()) {
            throw std::runtime_error("Queue is empty"); // 如果仍然为空，抛出异常
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    // 返回队列开头的元素
    int peek() {
        if (outStack.empty()) {
            in2out(); // 如果 outStack 为空，则将 inStack 的元素移动过来
        }
        if (outStack.empty()) {
            throw std::runtime_error("Queue is empty"); // 如果仍然为空，抛出异常
        }
        return outStack.top();
    }

    // 检查队列是否为空
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

// 主函数，用于测试
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    std::cout << "Pop: " << obj->pop() << std::endl;  // 应输出 1
    std::cout << "Peek: " << obj->peek() << std::endl; // 应输出 2

    obj->push(3);
    std::cout << "Pop: " << obj->pop() << std::endl;  // 应输出 2
    std::cout << "Pop: " << obj->pop() << std::endl;  // 应输出 3

    std::cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << std::endl; // 应输出 No

    delete obj; // 释放 MyQueue 对象
    return 0;
}