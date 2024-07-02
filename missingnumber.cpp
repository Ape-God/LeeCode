#include <vector>
#include<iostream>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size(); // 数组 nums 包含 n 个数
    // 计算理论总和
    int theoreticalSum = n * (n + 1) / 2;
    // 计算实际总和
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    // 找出缺失的数
    return theoreticalSum - actualSum;
}

// 示例
int main() {
    vector<int> nums = { 3, 0, 1 }; // 缺失的数是 2
    int missing = missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}