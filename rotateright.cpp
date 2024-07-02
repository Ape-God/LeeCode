#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr){}
};

//class Solution {
//public:
//    ListNode* rotateRight(ListNode* head, int k) {
//        if (head == nullptr || !head->next || k == 0) {
//            return head;
//        }
//        ListNode* tail = head;
//        int length = 1;
//        while (tail->next) {
//            tail = tail->next;
//            length++;
//        }
//        tail->next = head;
//        k = k % length;
//        if (k == 0) {
//            tail->next = nullptr;
//            return head;
//        }
//        for (int i = 0; i < length - k; i++) {
//            tail = tail->next;
//        }
//        ListNode* newHead = tail->next;
//        tail->next = nullptr;   
//        return newHead;
//    }
//};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head;
        int n = 1;
        while (cur->next) {
            cur = cur->next;
            ++n;
        }
        cur->next = head;
        for (int i = 0; i < n - k % n; ++i) {
            cur = cur->next;
        }
        head = cur->next;
        cur->next = nullptr;
        return head;
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
    // 创建一个示例链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* rotatedHead = solution.rotateRight(head, 2); // 旋转 2 个节点

    std::cout << "Rotated Linked List: ";
    printList(rotatedHead);

    // 释放链表的内存
    while (rotatedHead != nullptr) {
        ListNode* temp = rotatedHead;
        rotatedHead = rotatedHead->next;
        delete temp;
    }

    return 0;
}