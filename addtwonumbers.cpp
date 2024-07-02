#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* dummyHead = new ListNode(0); // 创建一个哑节点作为新链表的头结点
//        ListNode* p = l1, * q = l2, * current = dummyHead;
//        int carry = 0; // 初始化进位为0
//
//        while (p != nullptr || q != nullptr) {
//            int x = (p != nullptr) ? p->val : 0;
//            int y = (q != nullptr) ? q->val : 0;
//            int sum = carry + x + y; // 当前位的和加上进位
//            carry = sum / 10; // 更新进位
//            current->next = new ListNode(sum % 10); // 创建新节点存储当前位的数字
//            current = current->next; // 移动指针
//
//            if (p != nullptr) p = p->next; // 移动链表指针
//            if (q != nullptr) q = q->next;
//        }
//
//        if (carry > 0) { // 如果最后还有进位，需要添加一个新节点
//            current->next = new ListNode(carry);
//        }
//
//        ListNode* result = dummyHead->next; // 返回哑节点的下一个节点作为结果链表的头结点
//        delete dummyHead; // 删除哑节点
//        return result;
//    }
//};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tump = dummy;
        int curry = 0;
        while (l1 || l2 || curry) {
            int sum = curry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            curry = sum / 10;
            tump->next = new ListNode(sum % 10);
            tump = tump->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};



int main() {
    Solution solution;
    // 创建两个示例链表: 7 -> 1 -> 6 和 5 -> 9 -> 2
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(2);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    // 打印结果链表
    for (ListNode* p = result; p; p = p->next) {
        std::cout << p->val;
        if (p->next) std::cout << "->";
    }

    std::cout << " null" << std::endl;

    // 释放结果链表内存
    while (result) {
        ListNode* tmp = result;
        result = result->next;
        delete tmp;
    }

    return 0;
}