#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> visited;
        ListNode* temp = headA;

        // ������һ�����������нڵ�洢�� visited ������
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }

        temp = headB;

        // �����ڶ����������ڵ��Ƿ��� visited ������
        while (temp != nullptr) {
            if (visited.count(temp)) {
                // ����ڵ��� visited �У��ҵ��ཻ��ʼ�ڵ�
                return temp;
            }
            temp = temp->next;
        }

        // ���û���ҵ��ཻ�ڵ㣬���� nullptr
        return nullptr;
    }
};

// �����������ڲ���
int main() {
    Solution solution;

    // ���������ཻ�����ʾ��
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);

    ListNode* headB = new ListNode(5);
    headB->next = headA->next->next; // �������� B �� A �ĵ������ڵ㿪ʼ�ཻ

    cout << "Intersecting node value: " << solution.getIntersectionNode(headA, headB)->val << endl;

    // �ͷ������ڴ�
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB;

    return 0;
}