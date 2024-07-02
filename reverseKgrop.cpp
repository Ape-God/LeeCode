#include <iostream>
#include <utility> // ���� std::pair �� std::make_pair

using namespace std;
// ��������ڵ�


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ������ֳ�k��һ�飬����תÿһ��Ľڵ�
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ����һ���ƽڵ㣬���ڴ�������ķ�ת
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // ��ʼ��start��endָ�룬startָ��ǰ��ĵ�һ���ڵ㣬endָ�����һ���ڵ�
        ListNode* start = dummy, * end = dummy;

        while (true) { // ����ѭ����ֱ��endΪnullptr
            // �ƶ�endָ��k���ڵ㣬���endΪnullptr��˵������k���ڵ㣬ֱ���˳�ѭ��
            for (int i = 0; i < k && end; ++i) {
                end = end->next;
            }
            if (!end) { // ���endΪnullptr��˵������������˳�ѭ��
                break;
            }
            // ���浱ǰ�����ʼ�ڵ�ͽ����ڵ����һ���ڵ�
            ListNode* startNext = start->next;
            ListNode* endNext = end->next;

            // ����ǰ������һ���ڵ��next����Ϊnullptr���ж�������ڵ������
            end->next = nullptr;
            // ��ת��ǰ��Ľڵ�
            start->next = reverse(start->next);
            // ����ת������һ���ڵ�ָ��endNext������һ��Ŀ�ʼ
            startNext->next = endNext;
            // ����start��endָ�룬ָ����һ��Ŀ�ʼ�͵�ǰλ��
            start = end = startNext;
        }
        // �����ƽڵ����һ���ڵ㣬����ת�������ͷ�ڵ�
        return dummy->next;
    }

    // ��ת����ĸ�������
    ListNode* reverse(ListNode* head) {
        ListNode* cur = head, * pre = nullptr;
        // ����������ת�ڵ��nextָ��
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre; // ����ǰ�ڵ��nextָ��ǰһ���ڵ�
            pre = cur; // preָ����ǰ�ƶ�
            cur = next; // curָ����ǰ�ƶ�
        }
        // ���ط�ת�������ͷ�ڵ�
        return pre;
    }
};





// �������ڴ�ӡ����
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    Solution solution;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    ListNode* newHead = solution.reverseKGroup(head, 2);

    std::cout << "Reversed list: ";
    printList(newHead);

    // �ͷ������ڴ棨��ʵ��Ӧ����Ӧ����Ӵ������ͷ�����������ڴ棩
    delete newHead; // ����ͷ��ʼ�ͷ���������

    return 0;
}