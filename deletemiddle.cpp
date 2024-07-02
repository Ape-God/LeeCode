#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    ListNode* deleteMiddle(ListNode* head) {
//        if (!head || !head->next) return nullptr; // �������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӷ��� nullptr
//
//        ListNode* slow = head, * fast = head, * prev = nullptr;
//
//        while (fast && fast->next) {
//            prev = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // ���������Ϊż����slow ��ָ���м�ƫ�ҵĽڵ㣬��Ҫɾ��ǰһ���ڵ�
//        if (prev) {
//            prev->next = slow->next;
//        }
//        else {
//            // ���������Ϊ������slow ��ָ���м�ڵ㣬��Ҫɾ������ڵ�
//            head = slow->next;
//        }
//
//        delete slow; // �ͷ��м�ڵ���ڴ�
//        return head;
//    }
//};

class Solution {
public:
    // ������������ɾ�������е��м�ڵ�
    ListNode* deleteMiddle(ListNode* head) {
        // �������ֻ��һ���ڵ㣬ɾ���󷵻� nullptr
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head; // ��ʼ����ָ��
        ListNode* fast = head; // ��ʼ����ָ��
        ListNode* pre = nullptr; // ��ʼ��ǰһ���ڵ��ָ�룬����ɾ������

        // ʹ�ÿ���ָ�뷨�ҵ��м�ڵ��ǰһ���ڵ�
        while (fast && fast->next) {
            fast = fast->next->next; // ��ָ��һ���ƶ������ڵ�
            pre = slow; // ���浱ǰ��ָ���ǰһ���ڵ�
            slow = slow->next; // ��ָ���ƶ�һ���ڵ�
        }

        // ɾ���м�ڵ㣬����ǰһ���ڵ�� next ָ��ָ���м�ڵ����һ���ڵ�
        pre->next = pre->next->next;

        // ����ͷ�ڵ㣬����м�ڵ���ͷ�ڵ㣬�򷵻��µ�ͷ�ڵ�
        return head;
    }
};



// ʾ�����������ڴ����������ý������
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // ����һ��ʾ������ 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Original list: ";
    printList(list);

    ListNode* newList = solution.deleteMiddle(list);
    cout << "Modified list: ";
    printList(newList);

    // �ͷ������ڴ�
    while (newList) {
        ListNode* temp = newList;
        newList = newList->next;
        delete temp;
    }

    return 0;
}