//#include <memory>
//#include <iostream>
//
//class Test {
//public:
//    Test() { std::cout << "Test created." << std::endl; }
//    ~Test() { std::cout << "Test destroyed." << std::endl; }
//};
//
//int main() {
//    std::unique_ptr<Test> ptr(new Test()); // 创建并拥有一个 Test 对象
//    // 自动释放内存，无需显式 delete
//    return 0;
//}


#include <memory>
#include <iostream>

class Test {
public:
    Test() { std::cout << "Test created." << std::endl; }
    ~Test() { std::cout << "Test destroyed." << std::endl; }
};

int main() {
    std::shared_ptr<Test> ptr1(new Test()); // 创建并共享一个 Test 对象
    {
        std::shared_ptr<Test> ptr2 = ptr1; // ptr1 和 ptr2 共享对象
        // ptr2 离开作用域，但对象尚未销毁，因为 ptr1 仍然引用它
    }
    // ptr1 离开作用域，对象被销毁
    return 0;
}