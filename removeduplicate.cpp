//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        if (nums.size() < 3) {
//            return nums.size();
//        }
//
//        int slow = 2; // slow指针，用于跟踪可以放置新元素的位置
//        for (int fast = 2; fast < nums.size(); ++fast) {
//            // 如果当前元素不等于slow前两个位置的元素，将其放入slow位置
//            if (nums[fast] != nums[slow - 2]) {
//                nums[slow++] = nums[fast];
//            }
//        }
//        return slow; // 返回新的长度
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//
//    int newLength = solution.removeDuplicates(nums);
//    cout << "The length after removing duplicates is: " << newLength << endl;
//
//    // 打印数组以验证结果
//    for (int i = 0; i < newLength; ++i) {
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }

        int slow = 2; // slow指针，用于跟踪可以放置新元素的位置
        for (int fast = 2; fast < nums.size(); ++fast) {
            // 如果当前元素不等于slow前两个位置的元素，将其放入slow位置
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow; // 返回新的长度
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    int newLength = solution.removeDuplicates(nums);
    cout << "The length after removing duplicates is: " << newLength << endl;

    // 打印数组以验证结果
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}