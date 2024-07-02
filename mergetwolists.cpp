#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            }
            else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1 != nullptr) {
            current->next = l2;
        }
        if (l2 != nullptr) {
            current->next = l1;
        }
        return dummy.next;
    }
};




// 函数用于打印链表
void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val << " -> ";
        node = node->next;
    }
    std::cout << "null" << std::endl;
}

// 主函数
int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged Linked List: ";
    printList(mergedList);

    // 释放合并后链表的内存
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}