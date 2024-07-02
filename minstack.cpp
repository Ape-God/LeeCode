#include <iostream>
#include <stack>
#include <limits>
using namespace std;

//class MinStack {
//private:
//    std::stack<int> stack;      // 存储所有元素的栈
//    std::stack<int> minStack;   // 存储当前最小元素的栈
//
//public:
//    /** initialize your data structure here. */
//    MinStack() {}
//
//    void push(int val) {
//        // 总是将元素压入 stack
//        stack.push(val);
//        // 如果 minStack 为空，或者 val 小于等于 minStack 的栈顶元素，将 val 压入 minStack
//        if (minStack.empty() || val <= minStack.top()) {
//            minStack.push(val);
//        }
//    }
//
//    void pop() {
//        // 弹出 stack 的栈顶元素
//        int val = stack.top();
//        stack.pop();
//        // 如果弹出的元素是当前最小元素，也从 minStack 中弹出
//        if (val == minStack.top()) {
//            minStack.pop();
//        }
//    }
//
//    int top() {
//        // 返回 stack 的栈顶元素
//        return stack.top();
//    }
//
//    int getMin() {
//        // 返回 minStack 的栈顶元素，即当前最小元素
//        return minStack.top();
//    }
//};

class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }

    void pop() {
        x_stack.pop();
        min_stack.pop();
    }

    int top() {
        return x_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
};



int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // 返回 -3
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl;         // 返回 0
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // 返回 -2
    return 0;
}