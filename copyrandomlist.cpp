#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// ��������ڵ�

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // ��һ�α��������������ڵ㣬����������
    Node* current = head;
    while (current) {
        Node* copy = new Node(current->val);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    // �ڶ��α������������ָ��
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // �����α���������ԭʼ����͸�������
    Node* dummy = new Node(0); // �����ƽڵ㣬�����޸�ͷ�ڵ�
    Node* copyCurrent = dummy;
    current = head;
    while (current) {
        copyCurrent->next = current->next;
        copyCurrent = copyCurrent->next;
        current->next = current->next->next;
        current = current->next;
    }

    return dummy->next;
}

// ���������ͷ������ڴ�
void deleteList(Node* node) {
    while (node) {
        Node* tmp = node;
        node = node->next;
        delete tmp;
    }
}

// �������ڴ�ӡ����
void printList(Node* head) {
    Node* current = head;
    while (current) {
        std::cout << current->val;
        if (current->next) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}




class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> h;
        for (Node* cur = head; cur; cur = cur->next) {
            h[cur] = new Node(cur->val);
        }
        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->next) h[cur]->next = h[cur->next];
            if (cur->random) h[cur]->random = h[cur->random];
        }
        return h[head];
    }
};



int main() {
    // ����ʾ������
    Node* head = new Node(1);
    head->random = nullptr;
    head->next = new Node(2);
    head->next->random = head; // ָ��ͷ�ڵ�
    head->next->next = new Node(3);
    head->next->next->random = head->next;

    std::cout << "Original list: ";
    printList(head);

    Solution solution;

    Node* copiedHead = solution.copyRandomList(head);

    std::cout << "Copied list: ";
    printList(copiedHead);

    // �ͷ������ڴ�
    deleteList(head);
    deleteList(copiedHead);

    return 0;
}