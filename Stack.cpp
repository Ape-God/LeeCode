#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> myStack;

    // ��ջ�����Ԫ��
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // ����ջ��Ԫ��
    std::cout << "Top element is: " << myStack.top() << std::endl;

    // �Ƴ�ջ��Ԫ��
    myStack.pop();
    std::cout << "Top element after one pop is: " << myStack.top() << std::endl;

    // ���ջ�Ƿ�Ϊ��
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // ��ȡջ�Ĵ�С
    std::cout << "Size of the stack: " << myStack.size() << std::endl;

    return 0;
}