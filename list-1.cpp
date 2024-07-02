//#include<iostream>
//#include<cstdlib>
//
//using namespace std;
//
//struct Node {
//	int data;
//	Node* next;
//};
//
//Node* head = nullptr;
//
//void append(int data) {
//	Node* new_node = (Node*)malloc(sizeof(Node));
//	new_node->data = data;
//	new_node->next = nullptr;
//
//	if (!head) {
//		head = new_node;
//	}
//	else {
//		Node* current = head;
//		while (current->next) {
//			current = current->next;
//		}
//		current->next = new_node;
//	}
//}
//
//void freeList(Node* node) {
//	while (node) {
//		Node* temp = node;
//		node = node->next;
//		free(temp);
//	}
//}
//
//int main()
//{
//	head = nullptr;
//	append(1);
//	append(2);
//	append(3);
//	append(4);
//
//	Node* current = head;
//	while (current) {
//		cout << current->data << " ";
//		current = current->next;
//	}
//	cout << endl;
//	freeList(head);
//
//	return 0;
//}



#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int data):data(data),next(nullptr){}
};

class LinkedList {
private:
	Node * head;
public:
	LinkedList() :head(nullptr) {}
	~LinkedList() {
		clear();
	}

	void append(int data) {
		if (!head) {
			head = new Node(data);
		}
		else {
			Node* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = new Node(data);
		}
	}

	void printList() {
		Node *current = head;
		while (current) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void clear() {
		Node* current = head;
		while (current) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	}
};


int main()
{
	LinkedList list;
	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);

	cout << "linked list:" << endl;
	list.printList();

	return 0;
}