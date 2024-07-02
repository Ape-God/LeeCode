#include <iostream>
#include <vector>
using namespace std;


// 二分查找函数，返回元素在数组中的索引，如果不存在则返回-1
// 

int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        else if (target > nums[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
        return -1;
    }
}

//int binarySearch(const vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int mid = left + (right - left) / 2;
//        if (target == nums[mid]) {
//            return mid;
//        }
//        else if (target > nums[mid]) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//    return -1;
//}

int main() {
    std::vector<int> nums = { -3, 10, 11, 21, 34, 54, 60, 78 };
    int target = 21;

    int result = binarySearch(nums, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}