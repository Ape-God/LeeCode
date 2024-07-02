#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 交换链表中的成对节点
    ListNode* swapPairs(ListNode* head) {
        // 如果链表为空或只有一个节点，则无需交换，直接返回头节点
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        // 交换头节点和其后继节点
        ListNode* newHead = head->next; // 将第二个节点作为新的头节点
        head->next = swapPairs(newHead->next); // 递归交换新头节点之后的节点
        newHead->next = head; // 将原头节点链接到新头节点后面
        return newHead; // 返回交换后的链表的新头节点
    }
};

class Solution {
public:
    // 函数用于交换链表中的每对相邻节点
    ListNode* swapPairs(ListNode* head) {
        // 创建一个哑节点（dummy node），其next指向头节点
        // 这样可以简化对头节点的处理
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // 初始化pre为哑节点，cur为当前处理的节点
        ListNode* pre = dummy, * cur = dummy->next;

        // 使用while循环进行交换操作，直到cur为空或cur的下一个节点为空
        while (cur && cur->next) {
            // 保存cur的下一个节点，作为交换后的前一个节点
            ListNode* next = cur->next;

            // 将pre的next指向next，即将原cur和next分离
            pre->next = next;

            // 将cur的next指向next的next，完成交换的第一步
            cur->next = next->next;

            // 将next的next指向cur，完成交换
            next->next = cur;

            // 更新pre和cur到交换后的位置
            pre = cur;
            cur = cur->next;
        }

        // 返回哑节点的下一个节点，即交换后的链表的头节点
        // 注意哑节点在最后需要被删除以释放内存
        return dummy->next;
    }
};




// 函数用于打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "null" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
    printList(head);

    Solution solution;

    ListNode* newHead = solution.swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(newHead);

    // 释放链表内存（在实际应用中应该添加代码来释放整个链表的内存）
    delete head;

    return 0;
}