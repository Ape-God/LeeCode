#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }

        --k;
        string ans;
        vector<int> valid(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            int order = k / factorial[n - i] + 1;
            for (int j = 1; j <= n; ++j) {
                order -= valid[j];
                if (!order) {
                    ans += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};

// 主函数，用于测试
int main() {
    Solution solution;
    int n = 3;
    int k = 4; // 对应于 "231"
    string permutation = solution.getPermutation(n, k);
    cout << "The " << k << "th permutation of " << n << " elements is: " << permutation << endl;

    return 0;
}