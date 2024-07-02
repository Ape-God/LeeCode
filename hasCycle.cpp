#include <iostream>

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;

        ListNode* slow = head; // ��ָ��
        ListNode* fast = head; // ��ָ��

        while (fast && fast->next) {
            slow = slow->next;          // ��ָ����ǰ�ƶ�һ���ڵ�
            fast = fast->next->next;   // ��ָ����ǰ�ƶ������ڵ�

            if (slow == fast) {
                // �������ָ������������ڻ�
                return true;
            }
        }

        // �����ָ�뵽������ĩβ��˵��û�л�
        return false;
    }
};

int main() {
    Solution solution;
    // ����һ���л�������: 1 -> 2 -> 3 -> 4 -> 3 ...
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next; // �γɻ�

    bool hasCycle = solution.hasCycle(head);
    std::cout << "The list has a cycle: " << (hasCycle ? "Yes" : "No") << std::endl;

    // �ͷ������ڴ�
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}