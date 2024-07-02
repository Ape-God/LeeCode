#include <iostream>
#include <vector>
#include <algorithm> // ���� max
using namespace std;

bool kidsWithCandies(vector<int>& candies, int extraCandies) {
    int maxCandies = 0; // �洢����ǹ���
    for (int candy : candies) {
        maxCandies = max(maxCandies, candy);
    }

    for (int i = 0; i < candies.size(); ++i) {
        // ���ÿ�������Ƿ��ڷ��� extraCandies ��ӵ�������ǹ�
        if (candies[i] + extraCandies > maxCandies) {
            return true;
        }
    }
    return false;
}

// ���Ժ���
void testKidsWithCandies(vector<int>& candies, int extraCandies) {
    bool result = kidsWithCandies(candies, extraCandies);
    cout << "Can some child have the most candies after receiving " << extraCandies
        << " extra candies? " << (result ? "Yes" : "No") << endl;
}


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandies = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (int i = 0; i < n; ++i) {
            ret.push_back(candies[i] + extraCandies >= maxCandies);
        }
        return ret;
    }
};


int main() {
    vector<int> candies1 = { 2, 3, 5, 1, 3 };
    int extraCandies1 = 3;
    Solution solution;

    vector<bool> result = solution.kidsWithCandies(candies1, extraCandies1);
    cout << "Can some child have the most candies after receiving " << extraCandies1
        << " extra candies? " << endl;
    for (const auto & it : result) {
        cout << it << " ";
    }
    cout << endl;
    
    testKidsWithCandies(candies1, extraCandies1);

    vector<int> candies2 = { 4, 2, 1, 1, 2 };
    int extraCandies2 = 1;
    testKidsWithCandies(candies2, extraCandies2);

    return 0;
}