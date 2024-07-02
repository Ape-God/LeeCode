#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// ��������ڵ�ṹ��
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//class Solution {
//public:
//    // �ϲ�K����������
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // ʹ�����ȶ��У���С�ѣ����ϲ�����
//        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
//
//        // ��ʼ�����ȶ���
//        for (auto& list : lists) {
//            if (list) {
//                minHeap.push({ list->val, list });
//            }
//        }
//
//        // �����ƽڵ㣬���ڼ򻯺ϲ��߼�
//        ListNode dummy;
//        ListNode* tail = &dummy;
//
//        while (!minHeap.empty()) {
//            // ȡ����СԪ��
//            auto [val, node] = minHeap.top();
//            minHeap.pop();
//            tail->next = node; // ����СԪ�ص�������ںϲ������ĩβ
//            tail = tail->next; // �ƶ�tailָ��
//
//            // ���ȡ������������һ���ڵ㣬����������ȶ���
//            if (node->next) {
//                minHeap.push({ node->next->val, node->next });
//            }
//        }
//
//        // ���غϲ��������ͷ�ڵ�
//        return dummy.next;
//    }
//};


//class Solution {
//public:
//    // �ϲ�������������
//    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
//        // �������a��bΪ�գ����طǿ�����
//        if ((!a) || (!b)) return a ? a : b;
//
//        // �����ƽڵ�head��tailָ���ƽڵ㣬���ڹ���������
//        ListNode head, * tail = &head;
//        // ��ʼ��ָ��aPtr��bPtrָ������a��b��ͷ�ڵ�
//        ListNode* aPtr = a, * bPtr = b;
//
//        // ��aPtr��bPtr����Ϊ��ʱ������ѭ��
//        while (aPtr && bPtr) {
//            // �Ƚ�aPtr��bPtrָ��Ľڵ��ֵ������С�Ľڵ�ӵ�tail����
//            if (aPtr->val < bPtr->val) {
//                tail->next = aPtr; aPtr = aPtr->next;
//            }
//            else {
//                tail->next = bPtr; bPtr = bPtr->next;
//            }
//            // �ƶ�tailָ�뵽�½��ϵĽڵ�
//            tail = tail->next;
//        }
//
//        // ��δ�����������ӵ��ϲ������ĩβ
//        tail->next = (aPtr ? aPtr : bPtr);
//
//        // ���غϲ��������ͷ�ڵ�
//        return head.next;
//    }
//
//    // �ϲ�K����������ʹ��ѭ���ķ�ʽ��
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        ListNode* ans = nullptr;
//        // ���κϲ�ÿ�������������ans��
//        for (size_t i = 0; i < lists.size(); ++i) {
//            ans = mergeTwoLists(ans, lists[i]);
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    // ...��mergeTwoLists������ע�����һ�δ�����ͬ��ʡ���Խ�ʡ�ռ䣩
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
//    // �ݹ�ؽ������Ϊ���룬Ȼ��ϲ������ںϲ�K�������������η���
//    ListNode* merge(vector <ListNode*>& lists, int l, int r) {
//        // ������������ֻ��һ������ֱ�ӷ���
//        if (l == r) return lists[l];
//        // �������Խ�磬���ؿ�
//        if (l > r) return nullptr;
//
//        // �����м��������ݹ�غϲ���벿�ֺ��Ұ벿��
//        int mid = (l + r) >> 1;
//        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
//    }
//
//    // �ϲ�K�������������η���
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // ���õݹ�ϲ�������������0��lists.size() - 1
//        return merge(lists, 0, lists.size() - 1);
//    }
//};

//class Solution {
//public:
//    // ����Status�ṹ�壬���ڴ洢�ڵ��ֵ��ָ�룬�Լ�����С�������
//    struct Status {
//        int val;
//        ListNode* ptr;
//        bool operator < (const Status& rhs) const {
//            return val > rhs.val; // ����С���������ʹ�����ȶ��а���ֵ����������
//        }
//    };
//
//    // ʹ�����ȶ��У���С�ѣ����ϲ�K����������
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // ��ʼ�����ȶ���q
//        priority_queue <Status> q;
//
//        // �����������ͷ�ڵ�������ȶ���
//        for (auto node : lists) {
//            if (node) q.push({ node->val, node });
//        }
//
//        // �����ƽڵ�head��tailָ���ƽڵ㣬���ڹ���������
//        ListNode head, * tail = &head;
//
//        // �����ȶ��в�Ϊ��ʱ��ѭ������
//        while (!q.empty()) {
//            // ȡ�����ж�����Ԫ��
//            auto f = q.top(); q.pop();
//            // ��ȡ���Ľڵ�ӵ�tail����
//            tail->next = f.ptr;
//            // �ƶ�tailָ�뵽�½��ϵĽڵ�
//            tail = tail->next;
//
//            // ���ȡ���Ľڵ���нڵ㣬����������ȶ���
//            if (f.ptr->next) q.push({ f.ptr->next->val, f.ptr->next });
//        }
//
//        // ���غϲ��������ͷ�ڵ�
//        return head.next;
//    }
//};


class Solution {
public:
    // ����һ���ȽϽṹ��Cmp���������ȶ����е�Ԫ�رȽ�
    struct Cmp {
        // ����()�����������ȽϹ������a��ֵ����b��ֵ���򷵻�true
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    // �ϲ�K������ĺ���
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // ����һ�����ȶ���heap��Ԫ������ΪListNode*��ʹ��Cmp��Ϊ�ȽϺ���
        priority_queue<ListNode*, vector<ListNode*>, Cmp> heap;
        // ������������
        for (int i = 0; i < lists.size(); ++i) {
            // �����ǰ����Ϊ�գ�����ͷ�ڵ�ѹ�����ȶ���
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        // ����һ���ƽڵ�dummy��Ϊ�ϲ��������ͷ�ڵ㣬cur���ڱ����ϲ��������
        ListNode* dummy = new ListNode(0), * cur = dummy;
        // �����ȶ��в�Ϊ��ʱ
        while (!heap.empty()) {
            // ȡ�������ж����Ľڵ㣬����ǰ��С�Ľڵ�
            ListNode* top = heap.top();
            // �������ڵ�����ȶ����е���
            heap.pop();
            // ��ȡ���Ľڵ����ӵ�cur���棬cur����ƶ�
            cur = cur->next = top;
            // ���ȡ���Ľڵ�����һ���ڵ㣬����һ���ڵ�ѹ�����ȶ���
            if (top->next) {
                heap.push(top->next);
            }
        }
        // ���غϲ��������ͷ�ڵ����һ���ڵ㣬���ƽڵ����һ���ڵ�
        return dummy->next;
    }
};





// ʾ������
int main() {
    Solution solution;
    vector<ListNode*> lists = {
        new ListNode(1, new ListNode(4, new ListNode(5))),
        new ListNode(1, new ListNode(3, new ListNode(4))),
        new ListNode(2, new ListNode(6))
    };

    // �ϲ�����
    ListNode* mergedList = solution.mergeKLists(lists);

    // ��ӡ�ϲ��������
    for (ListNode* node = mergedList; node; node = node->next) {
        cout << node->val << " ";
    }

    // �ͷ�����ռ�õ��ڴ�
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