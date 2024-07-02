#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if (!head) return nullptr;
//
//        // 创建两个哑节点，分别用于存储小于x和大于等于x的节点
//        ListNode* dummy1 = new ListNode(0);
//        ListNode* dummy2 = new ListNode(0);
//        ListNode* smaller = dummy1; // 小于x的节点链表的尾指针
//        ListNode* greater = dummy2; // 大于等于x的节点链表的尾指针
//
//        while (head) {
//            if (head->val < x) {
//                smaller->next = head; // 将当前节点添加到小于x的链表
//                smaller = smaller->next;
//            }
//            else {
//                greater->next = head; // 将当前节点添加到大于等于x的链表
//                greater = greater->next;
//            }
//            head = head->next;
//        }
//
//        // 连接两个链表
//        smaller->next = dummy2->next;
//        greater->next = nullptr;
//
//        // 返回新链表的头节点
//        ListNode* newHead = dummy1->next;
//        delete dummy1; // 删除哑节点
//        delete dummy2; // 删除哑节点
//        return newHead;
//    }
//};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};




int main() {
    Solution solution;
    // 创建示例链表: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    int x = 3;

    // 分隔链表
    ListNode* newHead = solution.partition(head, x);

    // 打印结果链表
    std::cout << "List after partitioning: ";
    for (ListNode* p = newHead; p; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << "null" << std::endl;

    // 释放链表内存
    while (newHead) {
        ListNode* tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}