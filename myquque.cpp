#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    std::stack<int> inStack;  // ���ڽ�����Ԫ��
    std::stack<int> outStack; // �����ṩ����ǰ��Ԫ��

    // �� inStack ��Ԫ���ƶ��� outStack
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    // ���캯��
    MyQueue() {}

    // ��Ӳ�������Ԫ�� x �Ƶ����е�ĩβ
    void push(int x) {
        inStack.push(x);
    }

    // ���Ӳ������Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
    int pop() {
        if (outStack.empty()) {
            in2out(); // ��� outStack Ϊ�գ��� inStack ��Ԫ���ƶ�����
        }
        if (outStack.empty()) {
            throw std::runtime_error("Queue is empty"); // �����ȻΪ�գ��׳��쳣
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    // ���ض��п�ͷ��Ԫ��
    int peek() {
        if (outStack.empty()) {
            in2out(); // ��� outStack Ϊ�գ��� inStack ��Ԫ���ƶ�����
        }
        if (outStack.empty()) {
            throw std::runtime_error("Queue is empty"); // �����ȻΪ�գ��׳��쳣
        }
        return outStack.top();
    }

    // �������Ƿ�Ϊ��
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

// �����������ڲ���
int main() {
    MyQueue* obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    std::cout << "Pop: " << obj->pop() << std::endl;  // Ӧ��� 1
    std::cout << "Peek: " << obj->peek() << std::endl; // Ӧ��� 2

    obj->push(3);
    std::cout << "Pop: " << obj->pop() << std::endl;  // Ӧ��� 2
    std::cout << "Pop: " << obj->pop() << std::endl;  // Ӧ��� 3

    std::cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << std::endl; // Ӧ��� No

    delete obj; // �ͷ� MyQueue ����
    return 0;
}