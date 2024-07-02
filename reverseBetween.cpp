#include <iostream>

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        if (!head || left == right) return head;
//
//        // �����ƽڵ㣬�򻯱�Ե�������
//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//
//        ListNode* prev = dummy; // ָ��ת����ǰһ���ڵ��ָ��
//
//        // �ƶ� prev �� left �ڵ��ǰһ��λ��
//        for (int i = 0; i < left - 1; ++prev, --i) {
//            if (!prev->next) return head; // ����Խ��
//        }
//
//        ListNode* start = prev->next; // ��ת�������ʼ�ڵ�
//        ListNode* then = start->next; // ���ڷ�ת����ʱ�ڵ�
//
//        // ��ת left �� right ֮��Ľڵ�
//        for (int i = 0; i < right - left; ++i) {
//            start->next = then->next; // ���� then �ڵ�
//            then->next = prev->next;  // �� then ���뵽 prev ����
//            prev->next = then;        // ���� prev �� next ָ��
//            then = start->next;       // �ƶ� then ����һ������ת�ڵ�
//        }
//
//        ListNode* newHead = dummy->next; // ����ͷָ��
//        delete dummy; // ɾ���ƽڵ�
//
//        return newHead;
//    }
//};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        ListNode* current = prev->next;
        for (int i = left; i < right; ++i) {
            ListNode* nextNode = current->next;
            current->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        return dummy->next;
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
    int left = 2, right = 4;

    ListNode* newHead = solution.reverseBetween(head, left, right);
    // ��ӡ�������
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