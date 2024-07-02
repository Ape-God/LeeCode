#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 主函数，用于计算最大操作数
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numCounts; // 创建哈希表记录每个数字出现的次数
        int operations = 0; // 初始化操作数

        // 遍历数组，记录每个数字的出现次数
        for (int num : nums) {
            numCounts[num]++; // 增加对应数字的计数
        }

        // 遍历哈希表，计算可以成对移除的操作数
        for (auto& pair : numCounts) {
            int complement = k - pair.first; // 计算补数
            if (complement == pair.first) { // 如果补数与当前数字相同，成对出现
                operations += pair.second / 2; // 每对操作会移除两个数字
            }
            else if (numCounts.find(complement) != numCounts.end()) { // 如果补数存在于哈希表中
                operations += min(pair.second, numCounts[complement]); // 计算当前数字和补数的较小值
            }
        }

        return operations; // 返回最大操作数
    }
};


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, count = 0;
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                count++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] < k) {
                left++;
            }
            else {
                right--;
            }
        }
        return count;
    }
};



// 示例函数，用于演示 Solution 类的 maxOperations 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 1, 2, 3, 4, 3, 2, 3, 1 };
    int k = 5;
    // 调用 maxOperations 方法并输出结果
    cout << "The maximum number of operations is: " << solution.maxOperations(nums, k) << endl;

    return 0;
}