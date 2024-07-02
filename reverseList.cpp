#include <iostream>

// ��������ڵ�ṹ
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        ListNode *current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = pre;
            pre = current;
            current = nextNode;
         }
        return pre;
    }


    //ListNode* reverseList(ListNode* head) {
    //    if (head == nullptr || head->next == nullptr) {
    //        return head;
    //    }
    //    ListNode *cur = reverseList(head->next);
    //    head->next->next = head;
    //    head->next = nullptr;
    //    return cur;
    //}
};

// �������ڴ�ӡ����
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null" << std::endl;
}

// ������
int main() {
    // ����һ��ʾ������: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    std::cout << "Reversed Linked List: ";
    printList(reversedHead);

    // �ͷŷ�ת��������ڴ�
    while (reversedHead != nullptr) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }

    return 0;
}