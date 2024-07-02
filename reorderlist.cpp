#include <iostream>
#include<vector>
using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 找到链表中点
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, * fast = head, * prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr; // 断开链表
    return slow;
}

// 反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr, * curr = head, * next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// 重排链表
ListNode* reorderList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* mid = findMiddle(head);
    ListNode* second = reverseList(mid);

    ListNode* first = head, * tail = nullptr;

    while (second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        if (!temp1) { // 如果first是最后一个节点，更新tail
            tail = second;
        }

        first = temp1;
        second = temp2;
    }

    if (tail) tail->next = nullptr; // 断开链表

    return head;
}

// 函数用于打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}


class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> vec;
        ListNode* node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};



int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    Solution solution;

    solution.reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    // 释放链表内存（在实际应用中应该添加代码来释放整个链表的内存）
    delete head;

    return 0;
}