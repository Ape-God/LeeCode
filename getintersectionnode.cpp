#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> visited;
        ListNode* temp = headA;

        // 遍历第一个链表，将所有节点存储在 visited 集合中
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }

        temp = headB;

        // 遍历第二个链表，检查节点是否在 visited 集合中
        while (temp != nullptr) {
            if (visited.count(temp)) {
                // 如果节点在 visited 中，找到相交起始节点
                return temp;
            }
            temp = temp->next;
        }

        // 如果没有找到相交节点，返回 nullptr
        return nullptr;
    }
};

// 主函数，用于测试
int main() {
    Solution solution;

    // 创建两个相交链表的示例
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);

    ListNode* headB = new ListNode(5);
    headB->next = headA->next->next; // 假设链表 B 从 A 的第三个节点开始相交

    cout << "Intersecting node value: " << solution.getIntersectionNode(headA, headB)->val << endl;

    // 释放链表内存
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB;

    return 0;
}