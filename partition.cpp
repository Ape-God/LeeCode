#include <iostream>

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* partition(ListNode* head, int x) {
//        if (!head) return nullptr;
//
//        // ���������ƽڵ㣬�ֱ����ڴ洢С��x�ʹ��ڵ���x�Ľڵ�
//        ListNode* dummy1 = new ListNode(0);
//        ListNode* dummy2 = new ListNode(0);
//        ListNode* smaller = dummy1; // С��x�Ľڵ������βָ��
//        ListNode* greater = dummy2; // ���ڵ���x�Ľڵ������βָ��
//
//        while (head) {
//            if (head->val < x) {
//                smaller->next = head; // ����ǰ�ڵ���ӵ�С��x������
//                smaller = smaller->next;
//            }
//            else {
//                greater->next = head; // ����ǰ�ڵ���ӵ����ڵ���x������
//                greater = greater->next;
//            }
//            head = head->next;
//        }
//
//        // ������������
//        smaller->next = dummy2->next;
//        greater->next = nullptr;
//
//        // �����������ͷ�ڵ�
//        ListNode* newHead = dummy1->next;
//        delete dummy1; // ɾ���ƽڵ�
//        delete dummy2; // ɾ���ƽڵ�
//        return newHead;
//    }
//};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};




int main() {
    Solution solution;
    // ����ʾ������: 1 -> 4 -> 3 -> 2 -> 5 -> 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    int x = 3;

    // �ָ�����
    ListNode* newHead = solution.partition(head, x);

    // ��ӡ�������
    std::cout << "List after partitioning: ";
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