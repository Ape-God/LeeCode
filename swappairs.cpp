#include <iostream>

using namespace std;

// ��������ڵ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // ���������еĳɶԽڵ�
    ListNode* swapPairs(ListNode* head) {
        // �������Ϊ�ջ�ֻ��һ���ڵ㣬�����轻����ֱ�ӷ���ͷ�ڵ�
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // ����ͷ�ڵ�����̽ڵ�
        ListNode* newHead = head->next; // ���ڶ����ڵ���Ϊ�µ�ͷ�ڵ�
        head->next = swapPairs(newHead->next); // �ݹ齻����ͷ�ڵ�֮��Ľڵ�
        newHead->next = head; // ��ԭͷ�ڵ����ӵ���ͷ�ڵ����
        return newHead; // ���ؽ�������������ͷ�ڵ�
    }
};

class Solution {
public:
    // �������ڽ��������е�ÿ�����ڽڵ�
    ListNode* swapPairs(ListNode* head) {
        // ����һ���ƽڵ㣨dummy node������nextָ��ͷ�ڵ�
        // �������Լ򻯶�ͷ�ڵ�Ĵ���
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // ��ʼ��preΪ�ƽڵ㣬curΪ��ǰ����Ľڵ�
        ListNode* pre = dummy, * cur = dummy->next;

        // ʹ��whileѭ�����н���������ֱ��curΪ�ջ�cur����һ���ڵ�Ϊ��
        while (cur && cur->next) {
            // ����cur����һ���ڵ㣬��Ϊ�������ǰһ���ڵ�
            ListNode* next = cur->next;

            // ��pre��nextָ��next������ԭcur��next����
            pre->next = next;

            // ��cur��nextָ��next��next����ɽ����ĵ�һ��
            cur->next = next->next;

            // ��next��nextָ��cur����ɽ���
            next->next = cur;

            // ����pre��cur���������λ��
            pre = cur;
            cur = cur->next;
        }

        // �����ƽڵ����һ���ڵ㣬��������������ͷ�ڵ�
        // ע���ƽڵ��������Ҫ��ɾ�����ͷ��ڴ�
        return dummy->next;
    }
};




// �������ڴ�ӡ����
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    Solution solution;

    ListNode* newHead = solution.swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(newHead);

    // �ͷ������ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ�����������ڴ棩
    delete head;

    return 0;
}