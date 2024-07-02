#include<iostream>
#include<vector>
using namespace std;

vector<int> a(10, 1);
vector<int>b(10, 4);

void print() {
	vector<int>::iterator it;
	for (it = a.begin(); it < a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	cout << a.size() << endl;
	print();
	a.resize(15);
	print();
	cout << a.empty() << endl;
	a.push_back(2);
	print();
	a.pop_back();
	print();
	a.insert(a.begin() + 3, 3);
	print();
	a.insert(a.begin() + 4, 5, 6);
	print();
	a.erase(a.begin() + 3);
	print();
	reverse(a.begin(),a.end());
	print();
	a.swap(b);
	print();
	cout << a.front() << " " << a.back() << endl;
	cout << a.capacity() << " " << a.empty() << endl;
	a.clear();
	cout << a.capacity() << " " << a.empty() << endl;
	return 0;
}