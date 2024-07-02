#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;

        ListNode* slow = head; // 慢指针
        ListNode* fast = head; // 快指针

        while (fast && fast->next) {
            slow = slow->next;          // 慢指针向前移动一个节点
            fast = fast->next->next;   // 快指针向前移动两个节点

            if (slow == fast) {
                // 如果快慢指针相遇，则存在环
                return true;
            }
        }

        // 如果快指针到达链表末尾，说明没有环
        return false;
    }
};

int main() {
    Solution solution;
    // 创建一个有环的链表: 1 -> 2 -> 3 -> 4 -> 3 ...
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next; // 形成环

    bool hasCycle = solution.hasCycle(head);
    std::cout << "The list has a cycle: " << (hasCycle ? "Yes" : "No") << std::endl;

    // 释放链表内存
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}