#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        // ����λ�õ������ͷ�ڵ�
        ListNode* odd = new ListNode(0);
        // ż��λ�õ������ͷ�ڵ�
        ListNode* even = new ListNode(0);
        // ��������ĵ�ǰ�ڵ�
        ListNode* odd_curr = odd;
        // ż������ĵ�ǰ�ڵ�
        ListNode* even_curr = even;

        int index = 1;
        while (head) {
            if (index % 2 == 1) {
                odd_curr->next = head;
                odd_curr = odd_curr->next;
            }
            else {
                even_curr->next = head;
                even_curr = even_curr->next;
            }
            head = head->next;
            index++;
        }

        // ����������ż������
        odd_curr->next = even->next;
        even_curr->next = nullptr; // ż������β������Ϊnullptr

        // �����������ͷ�ڵ㣬��ԭ���������ͷ�ڵ�
        return odd->next;
    }
};

// ��ӡ����ĸ�������
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // ����һ��ʾ������: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    head = solution.oddEvenList(head);

    cout << "Odd-even sorted list: ";
    printList(head);

    // �ͷ������ڴ�
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}