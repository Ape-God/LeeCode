#include <iostream>

 //��������ڵ�
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
        ListNode* dummy = new ListNode(0); // �����ƽڵ�
        dummy->next = head;
        ListNode* fast = head;
        ListNode* slow = dummy;

        // ��ָ�����ƶ�n��
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        // ����ָ��ͬ���ƶ���ֱ����ָ�뵽������ĩβ
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // ɾ��������n���ڵ�
        slow->next = slow->next->next;

        // ����ͷ���
        ListNode* newHead = dummy->next;
        delete dummy; // ɾ���ƽڵ�
        return newHead;
    }
};



int main() {
    Solution solution;
    // ����ʾ������: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    int n = 2;

    // ɾ��������n���ڵ�
    ListNode* newHead = solution.removeNthFromEnd(head, n);

    // ��ӡ�������
    std::cout << "New list after removing the node: ";
    for (ListNode* p = newHead; p; p = p->next) {
        std::cout << p->val << " ";
    }
    std::cout << "null" << std::endl;

    // �ͷ������ڴ�
    while (newHead) {
        ListNode* tmp = newHead;
        newHead = newHead->next;
        delete tmp;
    }

    return 0;
}