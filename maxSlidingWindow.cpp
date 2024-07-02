#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    // 主函数，用于找到滑动窗口中的最大值
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // 存储窗口最大值的向量
        deque<int> dq; // 使用双端队列存储窗口元素的索引

        for (int i = 0; i < nums.size(); ++i) {
            // 维护双端队列，确保队首始终是当前窗口的最大值
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // 当窗口大小超过k时，移除窗口前端的元素的索引
            if (i >= k && dq.front() == i - k) {
                dq.pop_front();
            }

            // 维护结果向量，每个窗口的最大值
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result; // 返回滑动窗口中的最大值
    }
};

// 示例函数，用于演示 Solution 类的 maxSlidingWindow 方法
int main() {
    Solution solution;
    // 创建一个示例数组
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    // 调用 maxSlidingWindow 方法并输出结果
    vector<int> max_values = solution.maxSlidingWindow(nums, k);
    cout << "Maximum values in the sliding window of size " << k << ": ";
    for (int max_val : max_values) {
        cout << max_val << " ";
    }
    cout << endl;

    return 0;
}