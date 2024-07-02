#include <iostream>

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // ʹ�ù鲢�����㷨�������������
    ListNode* sortList(ListNode* head) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӷ���ͷ�ڵ�
        if (!head || !head->next) return head;

        // ʹ�ÿ���ָ���ҵ�������е�
        ListNode* slow = head, * fast = head, * prev = nullptr;
        while (fast && fast->next) {
            prev = slow; // prevʼ��ָ��fast��ǰһ���ڵ�
            slow = slow->next; // slowһ����һ��
            fast = fast->next->next; // fastһ��������
        }
        // �Ͽ�����prevָ��ǰ�벿�ֵ����һ���ڵ㣬slowָ���벿�ֵĵ�һ���ڵ�
        prev->next = nullptr;

        // �ݹ����sortList�ֱ��ǰ�����������������
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // �ϲ����������������
        return merge(left, right);
    }

private:
    // �ϲ�������������ĸ�������
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // ���l1Ϊ�գ�ֱ�ӷ���l2����֮��Ȼ
        if (!l1) return l2;
        if (!l2) return l1;

        // ����һ���ƽڵ㣬���ڼ򻯺ϲ��߼�
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // ѭ���ϲ���������ֱ��һ������Ϊ��
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1; // ��ǰl1��ֵ��С���������ӵ��ƽڵ����
                l1 = l1->next; // �ƶ�l1ָ��
            }
            else {
                tail->next = l2; // ��ǰl2��ֵ��С����ȣ��������ӵ��ƽڵ����
                l2 = l2->next; // �ƶ�l2ָ��
            }
            tail = tail->next; // �ƶ��ƽڵ��tailָ��
        }

        // ����ʣ���������
        tail->next = l1 ? l1 : l2; // ���ǿ���������ƽڵ����
        return dummy.next; // �����ƽڵ����һ���ڵ㣬���ϲ�������������ͷ�ڵ�
    }
};

// �������ڴ�ӡ����
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    Solution solution;
    // ����ʾ������: 4 -> 1 -> 3 -> 2 -> null
    ListNode* head = new ListNode(4);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);

    std::cout << "Original list: ";
    printList(head);

    ListNode* sortedHead = solution.sortList(head);

    std::cout << "Sorted list:   ";
    printList(sortedHead);

    // �ͷ������ڴ�
    while (sortedHead) {
        ListNode* tmp = sortedHead;
        sortedHead = sortedHead->next;
        delete tmp;
    }

    return 0;
}