#include <iostream>
#include <stack>
#include <limits>
using namespace std;

//class MinStack {
//private:
//    std::stack<int> stack;      // �洢����Ԫ�ص�ջ
//    std::stack<int> minStack;   // �洢��ǰ��СԪ�ص�ջ
//
//public:
//    /** initialize your data structure here. */
//    MinStack() {}
//
//    void push(int val) {
//        // ���ǽ�Ԫ��ѹ�� stack
//        stack.push(val);
//        // ��� minStack Ϊ�գ����� val С�ڵ��� minStack ��ջ��Ԫ�أ��� val ѹ�� minStack
//        if (minStack.empty() || val <= minStack.top()) {
//            minStack.push(val);
//        }
//    }
//
//    void pop() {
//        // ���� stack ��ջ��Ԫ��
//        int val = stack.top();
//        stack.pop();
//        // ���������Ԫ���ǵ�ǰ��СԪ�أ�Ҳ�� minStack �е���
//        if (val == minStack.top()) {
//            minStack.pop();
//        }
//    }
//
//    int top() {
//        // ���� stack ��ջ��Ԫ��
//        return stack.top();
//    }
//
//    int getMin() {
//        // ���� minStack ��ջ��Ԫ�أ�����ǰ��СԪ��
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
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // ���� -3
    minStack.pop();
    std::cout << "Top: " << minStack.top() << std::endl;         // ���� 0
    std::cout << "Minimum: " << minStack.getMin() << std::endl; // ���� -2
    return 0;
}