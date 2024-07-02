#include <iostream>
#include<unordered_set>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        if (!head || !head->next) {
//            return nullptr; // �������Ϊ�ջ�ֻ��һ���ڵ㣬���޻�
//        }
//
//        ListNode* slow = head; // ��ָ�룬ÿ���ƶ�һ��
//        ListNode* fast = head; // ��ָ�룬ÿ���ƶ�����
//
//        // �ÿ���ָ���⻷
//        while (fast && fast->next) {
//            slow = slow->next;    // ��ָ��ǰ��һ��
//            fast = fast->next->next; // ��ָ��ǰ������
//            if (slow == fast) { // ��⵽��
//                break;
//            }
//        }
//
//        // ���fastָ�뵽��β����û������������nullptr
//        if (!fast || !fast->next) {
//            return nullptr;
//        }
//
//        // ���³�ʼ����ָ��Ϊͷ�ڵ�
//        slow = head;
//
//        // �ٴ�ʹ�ÿ���ָ�룬�������ָ�붼ÿ��ǰ��һ��
//        // �������ٴ�����ʱ�������㼴Ϊ������ʼ�ڵ�
//        while (slow != fast) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//
//        return slow; // ���ػ�����ʼ�ڵ�
//    }
//};


//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        unordered_set<ListNode*> visited;
//        while (head != nullptr) {
//            if (visited.count(head)) {
//                return head;
//            }
//            visited.insert(head);
//            head = head->next;
//        }
//        return nullptr;
//    }
//};


class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};



// ���Ժ���
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << (curr->next ? " -> " : "");
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // ����һ��ʾ������: 1 -> 2 -> 3 -> 4 -> 5�����л��ӽڵ� 3 ��ʼ
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // �γɻ�


    ListNode* cycleStart = solution.detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "Cycle detected. Start node value: " << cycleStart->val << endl;
    }
    else {
        cout << "No cycle detected." << endl;
    }

    // �ͷ������ڴ�
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}