#include <iostream>

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode* dummyHead = new ListNode(0); // ����һ���ƽڵ���Ϊ�������ͷ���
//        ListNode* p = l1, * q = l2, * current = dummyHead;
//        int carry = 0; // ��ʼ����λΪ0
//
//        while (p != nullptr || q != nullptr) {
//            int x = (p != nullptr) ? p->val : 0;
//            int y = (q != nullptr) ? q->val : 0;
//            int sum = carry + x + y; // ��ǰλ�ĺͼ��Ͻ�λ
//            carry = sum / 10; // ���½�λ
//            current->next = new ListNode(sum % 10); // �����½ڵ�洢��ǰλ������
//            current = current->next; // �ƶ�ָ��
//
//            if (p != nullptr) p = p->next; // �ƶ�����ָ��
//            if (q != nullptr) q = q->next;
//        }
//
//        if (carry > 0) { // �������н�λ����Ҫ���һ���½ڵ�
//            current->next = new ListNode(carry);
//        }
//
//        ListNode* result = dummyHead->next; // �����ƽڵ����һ���ڵ���Ϊ��������ͷ���
//        delete dummyHead; // ɾ���ƽڵ�
//        return result;
//    }
//};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tump = dummy;
        int curry = 0;
        while (l1 || l2 || curry) {
            int sum = curry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            curry = sum / 10;
            tump->next = new ListNode(sum % 10);
            tump = tump->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};



int main() {
    Solution solution;
    // ��������ʾ������: 7 -> 1 -> 6 �� 5 -> 9 -> 2
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(6);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(2);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    // ��ӡ�������
    for (ListNode* p = result; p; p = p->next) {
        std::cout << p->val;
        if (p->next) std::cout << "->";
    }

    std::cout << " null" << std::endl;

    // �ͷŽ�������ڴ�
    while (result) {
        ListNode* tmp = result;
        result = result->next;
        delete tmp;
    }

    return 0;
}