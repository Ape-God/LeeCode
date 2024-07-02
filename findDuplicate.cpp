#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> dupset; // 创建一个哈希集合来存储已经遍历过的数
        for (int num : nums) {
            // 如果num已经在集合中，说明找到了重复的数
            if (dupset.find(num) != dupset.end()) {
                return num;
            }
            else {
                dupset.insert(num); // 否则，将num添加到集合中
            }
        }
        return -1; // 如果没有找到重复的数，返回-1（尽管题目保证一定有重复的数）
    }
};



class Solution {
public:
    // 主函数，用于找出数组中的重复整数
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1; // 获取数组长度 n
        for (int i = 0; i <= n; ++i) {
            // 当前索引指向的值作为目标索引
            int target = nums[i] - 1; // 数组值从1开始，所以需要减1
            while (nums[i] != nums[target]) {
                // 交换当前索引和目标索引的值
                swap(nums[i], nums[target]);
                // 更新目标索引为当前值对应的索引
                target = nums[i] - 1;
            }
        }
        // 循环结束后，第一个不匹配的索引即为重复的数
        for (int i = 0; i <= n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return -1; // 理论上不会执行到这里，因为题目保证存在重复数
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // 初始化二分查找的左右边界
        int l = 1, r = n - 1, ans = -1;
        // 执行二分查找
        while (l <= r) {
            int mid = (l + r) >> 1; // 计算中间值
            int cnt = 0; // 用于计数小于或等于mid的元素数量
            // 遍历数组，统计小于或等于mid的元素数量
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            // 根据统计的数量调整左右边界
            if (cnt <= mid) {
                l = mid + 1; // 如果数量小于或等于mid，则搜索右半部分
            }
            else {
                r = mid - 1; // 否则，搜索左半部分，并将当前mid作为可能的答案
                ans = mid;
            }
        }
        // 返回找到的重复数
        return ans;
    }
};



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 初始化慢指针和快指针
        int slow = 0, fast = 0;
        do {
            // 慢指针每次走一步，快指针每次走两步
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast); // 当快慢指针相遇时，循环存在

        // 重新初始化慢指针为起点
        slow = 0;
        // 再次移动慢指针和快指针，这次它们将在同一位置相遇，即循环的入口点
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // 返回循环的入口点，即重复的数
        return slow;
    }
};





// 示例函数，用于演示 Solution 类的 findDuplicate 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 1, 3, 4, 2, 2 };
    // 调用 findDuplicate 方法并输出结果
    int duplicate = solution.findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}