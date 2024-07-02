#include <iostream>
#include<vector>
using namespace std;

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// �ҵ������е�
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, * fast = head, * prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr; // �Ͽ�����
    return slow;
}

// ��ת����
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

// ��������
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

        if (!temp1) { // ���first�����һ���ڵ㣬����tail
            tail = second;
        }

        first = temp1;
        second = temp2;
    }

    if (tail) tail->next = nullptr; // �Ͽ�����

    return head;
}

// �������ڴ�ӡ����
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

    // �ͷ������ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ�����������ڴ棩
    delete head;

    return 0;
}