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
//        next = curr->next; // ���浱ǰ�ڵ����һ���ڵ�
//        curr->next = prev; // ��ת��ǰ�ڵ��ָ��
//        prev = curr;       // �ƶ� prev ����ǰ�ڵ�
//        curr = next;       // �ƶ� curr ����һ���ڵ�
//    }
//
//    return prev; // prev ָ��ת�������ͷ�ڵ�
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


// ��ӡ����ĸ�������
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // ����һ��ʾ������: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    cout << "Original list: ";
    printList(head);

    Solution solution;
    // ��ת����
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    // �ͷ������ڴ棨��ʵ��ʹ������Ҫ�ͷ����нڵ���ڴ棩
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}