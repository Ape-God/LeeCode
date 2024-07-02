#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//ListNode* reverseList(ListNode* head) {
//    ListNode* prev = nullptr;
//    ListNode* curr = head;
//    ListNode* next = nullptr;
//
//    while (curr != nullptr) {
//        next = curr->next; // 保存当前节点的下一个节点
//        curr->next = prev; // 反转当前节点的指针
//        prev = curr;       // 移动 prev 到当前节点
//        curr = next;       // 移动 curr 到下一个节点
//    }
//
//    return prev; // prev 指向反转后链表的头节点
//}


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* res = reverseList(head->next);
        ListNode* nextNode = head->next;
        nextNode->next = head;
        head->next = nullptr;
        return res;
    }
};


// 打印链表的辅助函数
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 创建一个示例链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    cout << "Original list: ";
    printList(head);

    Solution solution;
    // 反转链表
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    // 释放链表内存（在实际使用中需要释放所有节点的内存）
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}