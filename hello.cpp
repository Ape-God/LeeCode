//#include <iostream>
//#include <unordered_set> // ���� unordered_set ͷ�ļ�
//using namespace std;
//
//struct ListNode {
//    int val;
//    ListNode* next;
//    ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//    ListNode* detectCycle(ListNode* head) {
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//            if (fast == slow) {
//                slow = head;
//                while (fast != slow) {
//                    fast = fast->next;
//                    slow = slow->next;
//                }
//                return slow;
//            }
//        }
//        return NULL;
//    }
//};
//
//
//int main() {
//    ListNode* head = new ListNode(3);
//    head->next = new ListNode(2);
//    head->next->next = new ListNode(0);
//    head->next->next->next = new ListNode(-4);
//    head->next->next->next->next = head->next; // ��������-4ָ��2
//
//    Solution solution;
//
//    ListNode* cycleStart = solution.detectCycle(head);
//    if (cycleStart) {
//        cout << "������ڵ�ֵΪ: " << cycleStart->val << endl;
//    }
//    else {
//        cout << "�����޻�" << endl;
//    }
//
//    return 0;
//}



#include <iostream>
#include <unordered_set>
using namespace std;

// ��������ڵ�ṹ��
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// ����������Ƿ��л��������ػ�����ڽڵ�

ListNode* detectCycle(ListNode* head) {
	unordered_set<ListNode*> seen;
	while (head != nullptr) {
		if (seen.count(head)) {
			return head;
		}
		seen.insert(head);
		head = head->next;
	}
	return nullptr;
}



// ���ڴ������л�������ĸ�������
ListNode* createCycleListNode(int* values, int size, int cycleIndex) {
	if (values == nullptr || size == 0) {
		return nullptr;
	}
	ListNode* head = new ListNode(values[0]);
	ListNode* tail = head, * cycleNode = nullptr;

	for (int i = 0; i < size; ++i) {
		ListNode* Node = new ListNode(values[i]);
		tail->next = Node;
		tail = Node;
		if (i == cycleIndex) {
			cycleNode = Node;
		}
	}
	if (cycleNode) {
		tail->next = cycleNode;
	}
	return head;

}

// ���Ժ���
void test(ListNode* head) {
	ListNode* cycleNode = detectCycle(head);
	if (cycleNode) {
		std::cout << "Cycle detected at node with value: " << cycleNode->val << std::endl;
	}
	else {
		std::cout << "No cycle detected." << std::endl;
	}
}

// ������
int main() {
	// ʾ��������һ���������а�����
	int values[] = { 3, 2, 0, -4 };
	int cycleIndex = 2; // ������������0��ʼ������������軷�����ڵ������ڵ��
	int size = sizeof(values) / sizeof(values[0]);
	ListNode* head = createCycleListNode(values, size, cycleIndex);
	test(head);

	// ��������
	delete head->next->next->next;
	delete head->next->next;
	delete head->next;
	delete head;

	return 0;
}