#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 定义链表节点

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

    // 第一次遍历：创建副本节点，并交错连接
    Node* current = head;
    while (current) {
        Node* copy = new Node(current->val);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    // 第二次遍历：处理随机指针
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    // 第三次遍历：分离原始链表和副本链表
    Node* dummy = new Node(0); // 创建哑节点，避免修改头节点
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

// 函数用于释放链表内存
void deleteList(Node* node) {
    while (node) {
        Node* tmp = node;
        node = node->next;
        delete tmp;
    }
}

// 函数用于打印链表
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
    // 创建示例链表
    Node* head = new Node(1);
    head->random = nullptr;
    head->next = new Node(2);
    head->next->random = head; // 指向头节点
    head->next->next = new Node(3);
    head->next->next->random = head->next;

    std::cout << "Original list: ";
    printList(head);

    Solution solution;

    Node* copiedHead = solution.copyRandomList(head);

    std::cout << "Copied list: ";
    printList(copiedHead);

    // 释放链表内存
    deleteList(head);
    deleteList(copiedHead);

    return 0;
}