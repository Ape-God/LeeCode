#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 使用归并排序算法对链表进行排序
    ListNode* sortList(ListNode* head) {
        // 如果链表为空或只有一个节点，直接返回头节点
        if (!head || !head->next) return head;

        // 使用快慢指针找到链表的中点
        ListNode* slow = head, * fast = head, * prev = nullptr;
        while (fast && fast->next) {
            prev = slow; // prev始终指向fast的前一个节点
            slow = slow->next; // slow一次走一步
            fast = fast->next->next; // fast一次走两步
        }
        // 断开链表，prev指向前半部分的最后一个节点，slow指向后半部分的第一个节点
        prev->next = nullptr;

        // 递归调用sortList分别对前后两半链表进行排序
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // 合并两个已排序的链表
        return merge(left, right);
    }

private:
    // 合并两个有序链表的辅助函数
    ListNode* merge(ListNode* l1, ListNode* l2) {
        // 如果l1为空，直接返回l2；反之亦然
        if (!l1) return l2;
        if (!l2) return l1;

        // 创建一个哑节点，用于简化合并逻辑
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // 循环合并两个链表，直到一个链表为空
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1; // 当前l1的值较小，将其连接到哑节点后面
                l1 = l1->next; // 移动l1指针
            }
            else {
                tail->next = l2; // 当前l2的值较小或相等，将其连接到哑节点后面
                l2 = l2->next; // 移动l2指针
            }
            tail = tail->next; // 移动哑节点的tail指针
        }

        // 连接剩余的链表部分
        tail->next = l1 ? l1 : l2; // 将非空链表接在哑节点后面
        return dummy.next; // 返回哑节点的下一个节点，即合并后的有序链表的头节点
    }
};

// 函数用于打印链表
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

int main() {
    Solution solution;
    // 创建示例链表: 4 -> 1 -> 3 -> 2 -> null
    ListNode* head = new ListNode(4);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);

    std::cout << "Original list: ";
    printList(head);

    ListNode* sortedHead = solution.sortList(head);

    std::cout << "Sorted list:   ";
    printList(sortedHead);

    // 释放链表内存
    while (sortedHead) {
        ListNode* tmp = sortedHead;
        sortedHead = sortedHead->next;
        delete tmp;
    }

    return 0;
}