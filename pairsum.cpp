#include <iostream>
#include <algorithm> // ���� max
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
//        // ��ʼ������ָ�� slow �� fast��slow �����ҵ�������е㣬fast ����ȷ��������
//        ListNode* slow = head, * fast = head->next;
//
//        // ʹ�ÿ���ָ�뷨�ҵ�������е㣬fast ÿ���ƶ�������slow ÿ���ƶ�һ��
//        while (fast && fast->next) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        // slow ����ָ��������м�ڵ㣬fast �Ѿ���������β��������ĵ����ڶ����ڵ�
//        // ��ת����ĺ�벿��
//        ListNode* second_half = reverseList(slow->next);
//        slow->next = nullptr; // �Ͽ�����ʹ slow ָ���벿�ֵ�ͷ�ڵ�
//
//        // ��ʼ�����������Ϊ0
//        int ans = 0;
//
//        // ʹ������ָ�� x �� y �ֱ���������ǰ�벿�ֺͺ�벿��
//        ListNode* x = head; // ǰ�벿�ֵ�ͷ�ڵ�
//        ListNode* y = second_half; // ��벿�ֵ�ͷ�ڵ�
//
//        // ���������ǰ�벿�ֺͺ�벿�֣�����ÿ�������ڵ�ĺͣ����������������
//        while (y != nullptr) {
//            ans = std::max(ans, x->val + y->val); // �������������
//            x = x->next; // �ƶ�ǰ�벿�ֵ�ָ��
//            y = y->next; // �ƶ���벿�ֵ�ָ��
//        }
//
//        return ans; // ���ؼ���������������
//    }
//
//private:
//    // �������������ڷ�ת����
//    ListNode* reverseList(ListNode* head) {
//        ListNode* prev = nullptr, * curr = head, * next = nullptr;
//
//        // ��ת����ĵ�������
//        while (curr != nullptr) {
//            next = curr->next; // ������һ���ڵ�
//            curr->next = prev; // ��ת��ǰ�ڵ��ָ��
//            prev = curr;       // prev ��ǰ�ƶ�
//            curr = next;       // curr ��ǰ�ƶ�
//        }
//        return prev; // ���ط�ת�������ͷ�ڵ�
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




// ʾ�����������ڴ����������ý������
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    // ����һ��ʾ������ 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Original list: ";
    printList(list);

    int maxSum = solution.pairSum(list);
    cout << "Maximum twin sum: " << maxSum << endl;

    // �ͷ������ڴ�
    ListNode* temp;
    while (list != nullptr) {
        temp = list;
        list = list->next;
        delete temp;
    }

    return 0;
}