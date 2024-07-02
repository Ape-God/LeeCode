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
//            return nullptr; // 如果链表为空或只有一个节点，则无环
//        }
//
//        ListNode* slow = head; // 慢指针，每次移动一步
//        ListNode* fast = head; // 快指针，每次移动两步
//
//        // 用快慢指针检测环
//        while (fast && fast->next) {
//            slow = slow->next;    // 慢指针前移一步
//            fast = fast->next->next; // 快指针前移两步
//            if (slow == fast) { // 检测到环
//                break;
//            }
//        }
//
//        // 如果fast指针到达尾部或没有链表环，返回nullptr
//        if (!fast || !fast->next) {
//            return nullptr;
//        }
//
//        // 重新初始化慢指针为头节点
//        slow = head;
//
//        // 再次使用快慢指针，这次两个指针都每次前移一步
//        // 当它们再次相遇时，相遇点即为环的起始节点
//        while (slow != fast) {
//            slow = slow->next;
//            fast = fast->next;
//        }
//
//        return slow; // 返回环的起始节点
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



// 测试函数
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

    // 创建一个示例链表: 1 -> 2 -> 3 -> 4 -> 5，其中环从节点 3 开始
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // 形成环


    ListNode* cycleStart = solution.detectCycle(head);
    if (cycleStart != nullptr) {
        cout << "Cycle detected. Start node value: " << cycleStart->val << endl;
    }
    else {
        cout << "No cycle detected." << endl;
    }

    // 释放链表内存
    while (head != nullptr) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}