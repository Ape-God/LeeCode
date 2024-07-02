#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        if (!head || left == right) return head;
//
//        // 创建哑节点，简化边缘情况处理
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//
//        ListNode* prev = dummy; // 指向反转区间前一个节点的指针
//
//        // 移动 prev 到 left 节点的前一个位置
//        for (int i = 0; i < left - 1; ++prev, --i) {
//            if (!prev->next) return head; // 避免越界
//        }
//
//        ListNode* start = prev->next; // 反转区间的起始节点
//        ListNode* then = start->next; // 用于反转的临时节点
//
//        // 反转 left 到 right 之间的节点
//        for (int i = 0; i < right - left; ++i) {
//            start->next = then->next; // 跳过 then 节点
//            then->next = prev->next;  // 将 then 插入到 prev 后面
//            prev->next = then;        // 更新 prev 的 next 指针
//            then = start->next;       // 移动 then 到下一个待反转节点
//        }
//
//        ListNode* newHead = dummy->next; // 更新头指针
//        delete dummy; // 删除哑节点
//
//        return newHead;
//    }
//};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        ListNode* current = prev->next;
        for (int i = left; i < right; ++i) {
            ListNode* nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy->next;
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
    int left = 2, right = 4;

    ListNode* newHead = solution.reverseBetween(head, left, right);
    // 打印结果链表
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