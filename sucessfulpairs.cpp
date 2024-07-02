#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (auto& i : spells) {
            long long t = (success + i - 1) / i - 1;
            res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
        }
        return res;
    }
};


// 测试函数
void testSolution(Solution& solution, vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> result = solution.successfulPairs(spells, potions, success);
    cout << "Successful pairs count: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> spells1 = { 10, 20, 30, 40, 50 };
    vector<int> potions1 = { 1, 2, 3, 4, 5 };
    long long success1 = 32;
    testSolution(solution, spells1, potions1, success1);

    // 可以添加更多的测试用例
    return 0;
}