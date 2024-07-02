//#include <iostream>
//#include <unordered_set> // 包含 unordered_set 头文件
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
//    head->next->next->next->next = head->next; // 创建环，-4指向2
//
//    Solution solution;
//
//    ListNode* cycleStart = solution.detectCycle(head);
//    if (cycleStart) {
//        cout << "环的入口点值为: " << cycleStart->val << endl;
//    }
//    else {
//        cout << "链表无环" << endl;
//    }
//
//    return 0;
//}



#include <iostream>
#include <unordered_set>
using namespace std;

// 定义链表节点结构体
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

// 检测链表中是否有环，并返回环的入口节点

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



// 用于创建带有环的链表的辅助函数
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

// 测试函数
void test(ListNode* head) {
	ListNode* cycleNode = detectCycle(head);
	if (cycleNode) {
		std::cout << "Cycle detected at node with value: " << cycleNode->val << std::endl;
	}
	else {
		std::cout << "No cycle detected." << std::endl;
	}
}

// 主函数
int main() {
	// 示例：创建一个链表，其中包含环
	int values[] = { 3, 2, 0, -4 };
	int cycleIndex = 2; // 环的索引，从0开始计数，这里假设环连接在第三个节点后
	int size = sizeof(values) / sizeof(values[0]);
	ListNode* head = createCycleListNode(values, size, cycleIndex);
	test(head);

	// 清理链表
	delete head->next->next->next;
	delete head->next->next;
	delete head->next;
	delete head;

	return 0;
}