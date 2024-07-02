#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 定义链表节点结构体
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    // 合并K个升序链表
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // 使用优先队列（最小堆）来合并链表
//        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
//
//        // 初始化优先队列
//        for (auto& list : lists) {
//            if (list) {
//                minHeap.push({ list->val, list });
//            }
//        }
//
//        // 创建哑节点，用于简化合并逻辑
//        ListNode dummy;
//        ListNode* tail = &dummy;
//
//        while (!minHeap.empty()) {
//            // 取出最小元素
//            auto [val, node] = minHeap.top();
//            minHeap.pop();
//            tail->next = node; // 将最小元素的链表接在合并链表的末尾
//            tail = tail->next; // 移动tail指针
//
//            // 如果取出的链表还有下一个节点，将其加入优先队列
//            if (node->next) {
//                minHeap.push({ node->next->val, node->next });
//            }
//        }
//
//        // 返回合并后链表的头节点
//        return dummy.next;
//    }
//};


//class Solution {
//public:
//    // 合并两个有序链表
//    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
//        // 如果链表a或b为空，返回非空链表
//        if ((!a) || (!b)) return a ? a : b;
//
//        // 创建哑节点head，tail指向哑节点，用于构建新链表
//        ListNode head, * tail = &head;
//        // 初始化指针aPtr和bPtr指向链表a和b的头节点
//        ListNode* aPtr = a, * bPtr = b;
//
//        // 当aPtr和bPtr都不为空时，进行循环
//        while (aPtr && bPtr) {
//            // 比较aPtr和bPtr指向的节点的值，将较小的节点接到tail后面
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr; aPtr = aPtr->next;
//            }
//            else {
//                tail->next = bPtr; bPtr = bPtr->next;
//            }
//            // 移动tail指针到新接上的节点
//            tail = tail->next;
//        }
//
//        // 将未遍历完的链表接到合并链表的末尾
//        tail->next = (aPtr ? aPtr : bPtr);
//
//        // 返回合并后链表的头节点
//        return head.next;
//    }
//
//    // 合并K个有序链表（使用循环的方式）
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        ListNode* ans = nullptr;
//        // 依次合并每个链表到结果链表ans中
//        for (size_t i = 0; i < lists.size(); ++i) {
//            ans = mergeTwoLists(ans, lists[i]);
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    // ...（mergeTwoLists函数的注释与第一段代码相同，省略以节省空间）
//    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
//        if ((!a) || (!b)) return a ? a : b;
//        ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
//        while (aPtr && bPtr) {
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr; aPtr = aPtr->next;
//            }
//            else {
//                tail->next = bPtr; bPtr = bPtr->next;
//            }
//            tail = tail->next;
//        }
//        tail->next = (aPtr ? aPtr : bPtr);
//        return head.next;
//    }
//
//
//    // 递归地将链表分为两半，然后合并，用于合并K个有序链表（分治法）
//    ListNode* merge(vector <ListNode*>& lists, int l, int r) {
//        // 基本情况：如果只有一个链表，直接返回
//        if (l == r) return lists[l];
//        // 如果索引越界，返回空
//        if (l > r) return nullptr;
//
//        // 计算中间索引，递归地合并左半部分和右半部分
//        int mid = (l + r) >> 1;
//        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//    // 合并K个有序链表（分治法）
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // 调用递归合并函数，从索引0到lists.size() - 1
//        return merge(lists, 0, lists.size() - 1);
//    }
//};

//class Solution {
//public:
//    // 定义Status结构体，用于存储节点的值和指针，以及重载小于运算符
//    struct Status {
//        int val;
//        ListNode* ptr;
//        bool operator < (const Status& rhs) const {
//            return val > rhs.val; // 重载小于运算符，使得优先队列按照值的逆序排序
//        }
//    };
//
//    // 使用优先队列（最小堆）来合并K个有序链表
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // 初始化优先队列q
//        priority_queue <Status> q;
//
//        // 将所有链表的头节点加入优先队列
//        for (auto node : lists) {
//            if (node) q.push({ node->val, node });
//        }
//
//        // 创建哑节点head，tail指向哑节点，用于构建新链表
//        ListNode head, * tail = &head;
//
//        // 当优先队列不为空时，循环处理
//        while (!q.empty()) {
//            // 取出队列顶部的元素
//            auto f = q.top(); q.pop();
//            // 将取出的节点接到tail后面
//            tail->next = f.ptr;
//            // 移动tail指针到新接上的节点
//            tail = tail->next;
//
//            // 如果取出的节点后还有节点，将其加入优先队列
//            if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });
//        }
//
//        // 返回合并后链表的头节点
//        return head.next;
//    }
//};


class Solution {
public:
    // 定义一个比较结构体Cmp，用于优先队列中的元素比较
    struct Cmp {
        // 重载()运算符，定义比较规则：如果a的值大于b的值，则返回true
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    // 合并K个链表的函数
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 定义一个优先队列heap，元素类型为ListNode*，使用Cmp作为比较函数
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        // 遍历所有链表
        for (int i = 0; i < lists.size(); ++i) {
            // 如果当前链表不为空，则将其头节点压入优先队列
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        // 创建一个哑节点dummy作为合并后链表的头节点，cur用于遍历合并后的链表
        ListNode* dummy = new ListNode(0), * cur = dummy;
        // 当优先队列不为空时
        while (!heap.empty()) {
            // 取出队列中顶部的节点，即当前最小的节点
            ListNode* top = heap.top();
            // 将顶部节点从优先队列中弹出
            heap.pop();
            // 将取出的节点链接到cur后面，cur向后移动
            cur = cur->next = top;
            // 如果取出的节点有下一个节点，则将下一个节点压入优先队列
            if (top->next) {
                heap.push(top->next);
            }
        }
        // 返回合并后链表的头节点的下一个节点，即哑节点的下一个节点
        return dummy->next;
    }
};





// 示例调用
int main() {
    Solution solution;
    vector<ListNode*> lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6))
    };

    // 合并链表
    ListNode* mergedList = solution.mergeKLists(lists);

    // 打印合并后的链表
    for (ListNode* node = mergedList; node; node = node->next) {
        cout << node->val << " ";
    }

    // 释放链表占用的内存
    for (auto list : lists) {
        while (list) {
            ListNode* temp = list;
            list = list->next;
            delete temp;
        }
    }
    delete mergedList;

    return 0;
}