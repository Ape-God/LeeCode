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
//    std::unique_ptr<Test> ptr(new Test()); // ������ӵ��һ�� Test ����
//    // �Զ��ͷ��ڴ棬������ʽ delete
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
    std::shared_ptr<Test> ptr1(new Test()); // ����������һ�� Test ����
    {
        std::shared_ptr<Test> ptr2 = ptr1; // ptr1 �� ptr2 �������
        // ptr2 �뿪�����򣬵�������δ���٣���Ϊ ptr1 ��Ȼ������
    }
    // ptr1 �뿪�����򣬶�������
    return 0;
}