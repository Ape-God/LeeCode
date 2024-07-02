#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // 奇数位置的链表的头节点
        ListNode* odd = new ListNode(0);
        // 偶数位置的链表的头节点
        ListNode* even = new ListNode(0);
        // 奇数链表的当前节点
        ListNode* odd_curr = odd;
        // 偶数链表的当前节点
        ListNode* even_curr = even;

        int index = 1;
        while (head) {
            if (index % 2 == 1) {
                odd_curr->next = head;
                odd_curr = odd_curr->next;
            }
            else {
                even_curr->next = head;
                even_curr = even_curr->next;
            }
            head = head->next;
            index++;
        }

        // 连接奇数和偶数链表
        odd_curr->next = even->next;
        even_curr->next = nullptr; // 偶数链表尾部设置为nullptr

        // 返回新链表的头节点，即原奇数链表的头节点
        return odd->next;
    }
};

// 打印链表的辅助函数
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // 创建一个示例链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    head = solution.oddEvenList(head);

    cout << "Odd-even sorted list: ";
    printList(head);

    // 释放链表内存
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}