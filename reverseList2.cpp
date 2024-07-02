#include <iostream>

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};

class Solution {
public:
    /*ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* first = dummy;
        for (int i = 0; i < m - 1; ++i) {
            first = first->next;
        }
        ListNode* second = first->next;
        ListNode* prev = nullptr;
        for (int i = 0; i < n - m + 1; ++i) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }
        first->next->next = second;
        first->next = prev;

        ListNode* newHead = dummy->next;

        delete dummy;
        return newHead;
    }*/
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* pre = dummy;

        for (int i = 0; i < left-1; ++i) {
            pre = pre->next;
        }

        ListNode* current = pre->next;
        for (int i = left; i < right; ++i) {
            ListNode* nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = pre->next;
            pre->next = nextNode;
        }
        return dummy->next;
    }

};






// 函数用于打印链表
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null" << std::endl;
}

// 主函数
int main() {
    ListNode* list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedList = solution.reverseBetween(list, 2, 4);

    std::cout << "Reversed Linked List: ";
    printList(reversedList);

    // 释放链表的内存
    while (reversedList != nullptr) {
        ListNode* temp = reversedList;
        reversedList = reversedList->next;
        delete temp;
    }

    return 0;
}