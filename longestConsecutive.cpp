#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_map<int, bool> num_map;
    int max_length = 0;

    // 记录每个数字出现的次数（在这里，我们只关心数字是否出现过，所以次数为1即可）
    for (int num : nums) {
        num_map[num] = true;
    }

    // 遍历哈希表，找出最长连续序列
    for (const auto& pair : num_map) {
        int current_num = pair.first;
        if (num_map.find(current_num - 1) == num_map.end()) { // 如果当前数字的前一个数字不在哈希表中
            int length = 1; // 初始化长度为1
            // 尝试扩展连续序列
            while (num_map.find(current_num + length) != num_map.end()) {
                ++length;
            }
            // 更新最长连续序列的长度
            max_length = std::max(max_length, length);
        }
    }

    return max_length;
}

int main() {
    std::vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    int result = longestConsecutive(nums);
    std::cout << "The length of the longest consecutive sequence is: " << result << std::endl;
    return 0;
}