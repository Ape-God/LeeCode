#include <iostream>
#include <vector>
#include <queue>

// ����ڵ�ṹ��
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

// �����½ڵ�İ�������
Node* createNode(int data) {
    return new Node(data);
}

// ������ȫ�������ĺ���
Node* constructCompleteTree(int* arr, int start, int end) {
    if (start > end) {
        return nullptr; // ���start����end���򷵻ؿսڵ�
    }
    // �������ڵ�
    Node* root = createNode(arr[start]);
    // �ݹ鹹��������
    int leftChild = 2 * start + 1;
    if (leftChild <= end) {
        root->left = constructCompleteTree(arr, leftChild, end);
    }
    // �ݹ鹹��������
    int rightChild = 2 * start + 2;
    if (rightChild <= end) {
        root->right = constructCompleteTree(arr, rightChild, end);
    }
    return root;
}

// �����������ӡ������
void printPreorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; // ��������һ����ȫ�������������ʾ
    int size = sizeof(arr) / sizeof(arr[0]);
    Node* root = constructCompleteTree(arr, 0, size - 1);

    std::cout << "��������������-��-�ң�:" << std::endl;
    printPreorder(root);
    std::cout << std::endl;

    // �ͷ����ڵ��ڴ棨��ʵ��Ӧ���к���Ҫ�������ڴ�й©��
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