#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* createNode(int a[],int n) {
	if (n == 0) {
		return 0;
	}
	ListNode *head = new ListNode(a[0]);
	ListNode* cur = head;
	for (int i = 1; i < n; ++i) {
		cur->next = new ListNode(a[i]);
		cur = cur->next;
	}
	return head;
}

void printList(ListNode *head) {
	ListNode* cur = head;
	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << "  " << endl;
}

ListNode* reverseList(ListNode* head) {
	ListNode* pre = nullptr;
	ListNode* cur = head;
	while (cur) {
		ListNode* suc = cur->next;
		cur->next = pre;
		pre = cur;
		cur = suc;
	}
	return pre;
}

ListNode * deleteDuplicate(ListNode* head) {
	ListNode* cur = head;
	ListNode* pre = nullptr;
	set<int> record;
	while (cur) {
		if (record.find(cur->val) == record.end()) {
			record.insert(cur->val);
			pre = cur;
			cur = cur->next;
		}
		else {
			ListNode* delNode = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete delNode;
		}
	}
	return head;
}


int main()
{
	int a[10] = { 1,2,3,1,2,3,4,3,2,1 };
	ListNode* head = createNode(a, 10);
	printList(head);
	ListNode * head2 = reverseList(head);
	printList(head2);
	ListNode * head3 = deleteDuplicate(head2);
	printList(head3);
	return 0;
}




