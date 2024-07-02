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
//        if (!head || !head->next) return nullptr; // 如果链表为空或只有一个节点，直接返回 nullptr
//
//        ListNode* slow = head, * fast = head, * prev = nullptr;
//
//        while (fast && fast->next) {
//            prev = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // 如果链表长度为偶数，slow 将指向中间偏右的节点，需要删除前一个节点
//        if (prev) {
//            prev->next = slow->next;
//        }
//        else {
//            // 如果链表长度为奇数，slow 将指向中间节点，需要删除这个节点
//            head = slow->next;
//        }
//
//        delete slow; // 释放中间节点的内存
//        return head;
//    }
//};

class Solution {
public:
    // 主函数，用于删除链表中的中间节点
    ListNode* deleteMiddle(ListNode* head) {
        // 如果链表只有一个节点，删除后返回 nullptr
        if (head->next == nullptr) {
            return nullptr;
        }

        ListNode* slow = head; // 初始化慢指针
        ListNode* fast = head; // 初始化快指针
        ListNode* pre = nullptr; // 初始化前一个节点的指针，用于删除操作

        // 使用快慢指针法找到中间节点的前一个节点
        while (fast && fast->next) {
            fast = fast->next->next; // 快指针一次移动两个节点
            pre = slow; // 保存当前慢指针的前一个节点
            slow = slow->next; // 慢指针移动一个节点
        }

        // 删除中间节点，即将前一个节点的 next 指针指向中间节点的下一个节点
        pre->next = pre->next->next;

        // 返回头节点，如果中间节点是头节点，则返回新的头节点
        return head;
    }
};



// 示例函数，用于创建链表并调用解决方案
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // 创建一个示例链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Original list: ";
    printList(list);

    ListNode* newList = solution.deleteMiddle(list);
    cout << "Modified list: ";
    printList(newList);

    // 释放链表内存
    while (newList) {
        ListNode* temp = newList;
        newList = newList->next;
        delete temp;
    }

    return 0;
}