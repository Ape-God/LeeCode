#include <iostream>
#include <algorithm> // 用于 max
#include<vector>
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
//    int pairSum(ListNode* head) {
//        // 初始化两个指针 slow 和 fast，slow 用于找到链表的中点，fast 用于确定链表长度
//        ListNode* slow = head, * fast = head->next;
//
//        // 使用快慢指针法找到链表的中点，fast 每次移动两步，slow 每次移动一步
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // slow 现在指向链表的中间节点，fast 已经到达链表尾部或链表的倒数第二个节点
//        // 反转链表的后半部分
//        ListNode* second_half = reverseList(slow->next);
//        slow->next = nullptr; // 断开链表，使 slow 指向后半部分的头节点
//
//        // 初始化最大孪生和为0
//        int ans = 0;
//
//        // 使用两个指针 x 和 y 分别遍历链表的前半部分和后半部分
//        ListNode* x = head; // 前半部分的头节点
//        ListNode* y = second_half; // 后半部分的头节点
//
//        // 遍历链表的前半部分和后半部分，计算每对孪生节点的和，并更新最大孪生和
//        while (y != nullptr) {
//            ans = std::max(ans, x->val + y->val); // 更新最大孪生和
//            x = x->next; // 移动前半部分的指针
//            y = y->next; // 移动后半部分的指针
//        }
//
//        return ans; // 返回计算出的最大孪生和
//    }
//
//private:
//    // 辅助函数，用于反转链表
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr, * curr = head, * next = nullptr;
//
//        // 反转链表的迭代过程
//        while (curr != nullptr) {
//            next = curr->next; // 保存下一个节点
//            curr->next = prev; // 反转当前节点的指针
//            prev = curr;       // prev 向前移动
//            curr = next;       // curr 向前移动
//        }
//        return prev; // 返回反转后链表的头节点
//    }
//};


class Solution {
public:
    vector<int> res;
    int pairSum(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            res.push_back(temp->val);
            temp = temp->next;
        }
        int l = 0, r = n - 1;
        int sum = 0;
        while (l < r) {
            int k = res[l] + res[r];
            if (k > sum) {
                sum = k;
            }
            l++;
            r--;
        }
        return sum;
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

    int maxSum = solution.pairSum(list);
    cout << "Maximum twin sum: " << maxSum << endl;

    // 释放链表内存
    ListNode* temp;
    while (list != nullptr) {
        temp = list;
        list = list->next;
        delete temp;
    }

    return 0;
}