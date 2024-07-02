#include <iostream>
#include <vector>
#include <queue>

// 定义节点结构体
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// 创建新节点的帮助函数
Node* createNode(int data) {
    return new Node(data);
}

// 构造完全二叉树的函数
Node* constructCompleteTree(int* arr, int start, int end) {
    if (start > end) {
        return nullptr; // 如果start大于end，则返回空节点
    }
    // 创建根节点
    Node* root = createNode(arr[start]);
    // 递归构造左子树
    int leftChild = 2 * start + 1;
    if (leftChild <= end) {
        root->left = constructCompleteTree(arr, leftChild, end);
    }
    // 递归构造右子树
    int rightChild = 2 * start + 2;
    if (rightChild <= end) {
        root->right = constructCompleteTree(arr, rightChild, end);
    }
    return root;
}

// 先序遍历并打印二叉树
void printPreorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; // 假设这是一个完全二叉树的数组表示
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = constructCompleteTree(arr, 0, size - 1);

    std::cout << "先序遍历结果（根-左-右）:" << std::endl;
    printPreorder(root);
    std::cout << std::endl;

    // 释放树节点内存（在实际应用中很重要，避免内存泄漏）
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
        delete current;
    }

    return 0;
}