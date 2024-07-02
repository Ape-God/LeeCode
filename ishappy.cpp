#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> seen;
		while (n != 1 && seen.count(n)) {
			seen.insert(n);
			n = nextHappyNumber(n);
		}
		return n == 1;
	}
private:
	int nextHappyNumber(int n) {
		int sum = 0;
		while (n > 0) {
			int digit = n % 10;
			sum += digit * digit;
			n = n / 10;
		}
		return sum;
	}
};

int main() {
	Solution solution;
	int number = 19;
	if (solution.isHappy(number)) {
		cout << number << " is not a happy number" << endl;
	}
	else {
		cout << number << " is a happy number" << endl;
	}
	return 0;
}