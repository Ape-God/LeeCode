#include <iostream>

 //定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* removeNthFromEnd(ListNode* head, int n) {
//        ListNode* dummy = new ListNode(0, head);
//        ListNode* first = head;
//        ListNode* second = dummy;
//        for (int i = 0; i < n; ++i) {
//            first = first->next;
//        }
//        while (first) {
//            first = first->next;
//            second = second->next;
//        }
//        second->next = second->next->next;
//        ListNode* ans = dummy->next;
//        delete dummy;
//        return ans;
//    }
//};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0); // 创建哑节点
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;

        // 快指针先移动n步
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // 快慢指针同步移动，直到快指针到达链表末尾
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 删除倒数第n个节点
        slow->next = slow->next->next;

        // 返回头结点
        ListNode* newHead = dummy->next;
        delete dummy; // 删除哑节点
        return newHead;
    }
};



int main() {
    Solution solution;
    // 创建示例链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;

    // 删除倒数第n个节点
    ListNode* newHead = solution.removeNthFromEnd(head, n);

    // 打印结果链表
    std::cout << "New list after removing the node: ";
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