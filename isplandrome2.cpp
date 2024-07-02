#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// ���������ҵ�������м�ڵ�
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, * fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// �������ڷ�ת����
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr, * curr = head, * next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// ���������ж������Ƿ�Ϊ����
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // �ҵ��е�
    ListNode* mid = findMiddle(head);
    // ��ת��벿������
    ListNode* reversedHead = reverse(mid);

    // �Ƚ�ǰ�벿�ֺͷ�ת��ĺ�벿��
    ListNode* p1 = head;
    ListNode* p2 = reversedHead;
    bool isPal = true;
    while (isPal && p2) {
        if (p1->val != p2->val) {
            isPal = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    // �����Ҫ������������ָ�����ĺ�벿��

    return isPal;
}


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != nullptr) {
            vals.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)vals.size() - 1; i < j; ++i, --j) {
            if (vals[i] != vals[j]) {
                return false;
            }
        }
        return true;
    }
};




int main() {
    // ����һ��ʾ������: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution solution;

    bool result = solution.isPalindrome(head) ? true : false;
    cout << "Is the list a palindrome? " << (result ? "Yes" : "No") << endl;

    // �ͷ������ڴ�
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}