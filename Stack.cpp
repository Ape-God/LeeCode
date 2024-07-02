#include <stack>
#include <iostream>

using namespace std;

int main() {
    stack<int> myStack;

    // 向栈中添加元素
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 访问栈顶元素
    std::cout << "Top element is: " << myStack.top() << std::endl;

    // 移除栈顶元素
    myStack.pop();
    std::cout << "Top element after one pop is: " << myStack.top() << std::endl;

    // 检查栈是否为空
    std::cout << "Is the stack empty? " << (myStack.empty() ? "Yes" : "No") << std::endl;

    // 获取栈的大小
    std::cout << "Size of the stack: " << myStack.size() << std::endl;

    return 0;
}