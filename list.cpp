#include<iostream>
#include<list>
using namespace std;

list<int> a(10, 1);
list<int> b(10, 4);
void print() {
	list<int>::iterator it;
	for (it = a.begin(); it != a.end(); ++it) {
		cout << *it<< " ";
	}
	cout << endl;
}

int main()
{
	cout<< a.size() << endl;
	print();
	a.pop_back();
	print();
	a.resize(15);
	cout << a.size() << endl;
	print();
	a.push_front(3);
	print();
	a.pop_front();
	print();
	a.push_back(2);
	print();
	a.insert(a.begin(), 3);
	print();
	a.insert(a.begin(), 5, 6);
	print();
	a.remove(1);
	print();
	a.remove(6);
	print();
	a.erase(a.begin());
	print();
	reverse(a.begin(),a.end());
	print();
	a.swap(b);
	print();
	cout << a.front() << " " << a.back() << endl;
	cout << a.empty() << " " << endl;
	a.clear();
	cout << a.empty() << endl;
	return 0;
}