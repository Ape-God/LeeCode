#include <iostream>
#include <utility> // 包含 std::pair 和 std::make_pair

using namespace std;
// 定义链表节点


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 将链表分成k个一组，并反转每一组的节点
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 创建一个哑节点，便于处理链表的反转
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 初始化start和end指针，start指向当前组的第一个节点，end指向最后一个节点
        ListNode* start = dummy, * end = dummy;

        while (true) { // 无限循环，直到end为nullptr
            // 移动end指针k个节点，如果end为nullptr，说明不足k个节点，直接退出循环
            for (int i = 0; i < k && end; ++i) {
                end = end->next;
            }
            if (!end) { // 如果end为nullptr，说明链表结束，退出循环
                break;
            }
            // 保存当前组的起始节点和结束节点的下一个节点
            ListNode* startNext = start->next;
            ListNode* endNext = end->next;

            // 将当前组的最后一个节点的next设置为nullptr，切断与后续节点的连接
            end->next = nullptr;
            // 反转当前组的节点
            start->next = reverse(start->next);
            // 将反转后的最后一个节点指向endNext，即下一组的开始
            startNext->next = endNext;
            // 更新start和end指针，指向下一组的开始和当前位置
            start = end = startNext;
        }
        // 返回哑节点的下一个节点，即反转后链表的头节点
        return dummy->next;
    }

    // 反转链表的辅助函数
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, * pre = nullptr;
        // 遍历链表，反转节点的next指针
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre; // 将当前节点的next指向前一个节点
            pre = cur; // pre指针向前移动
            cur = next; // cur指针向前移动
        }
        // 返回反转后链表的头节点
        return pre;
    }
};





// 函数用于打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    ListNode* newHead = solution.reverseKGroup(head, 2);

    std::cout << "Reversed list: ";
    printList(newHead);

    // 释放链表内存（在实际应用中应该添加代码来释放整个链表的内存）
    delete newHead; // 从新头开始释放整个链表

    return 0;
}