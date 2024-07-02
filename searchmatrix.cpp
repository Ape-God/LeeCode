#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    // 函数用于在一个二维矩阵中搜索一个目标值
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if (matrix.empty() || matrix[0].empty()) return false;
//        // 检查矩阵是否为空或空行
//
//        int rows = matrix.size();  // 获取矩阵的行数
//        int cols = matrix[0].size();  // 获取矩阵的列数
//
//        // 从右上角开始搜索，初始化行和列的索引
//        int row = 0;
//        int col = cols - 1;
//
//        // 使用 while 循环进行搜索，直到行索引超出下边界或列索引超出上边界
//        while (row < rows && col >= 0) {
//            if (matrix[row][col] == target) {
//                return true;  // 如果找到目标值，返回 true
//            }
//            else if (matrix[row][col] > target) {
//                col--;  // 如果当前元素大于目标值，列索引减1，向左移动
//            }
//            else {
//                row++;  // 如果当前元素小于目标值，行索引加1，向下移动
//            }
//        }
//
//        return false;  // 如果没有找到目标值，返回 false
//    }
//};

class Solution {
public:
    // 函数使用二分查找在一个按行排序的矩阵中搜索目标值
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        // 使用 upper_bound 查找应该开始搜索的行
        // 这里使用了一个自定义的比较函数，确保找到大于或等于 target 的第一个元素
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a) {
            return b < a[0];
            });

        // 如果 row 是 matrix 的第一个元素，说明 target 比矩阵中所有元素都大，返回 false
        if (row == matrix.begin()) {
            return false;
        }

        // 退回到前一行，因为 upper_bound 可能已经超出了 target 所在的范围
        --row;

        // 在找到的行中使用 binary_search 进行二分查找
        return binary_search(row->begin(), row->end(), target);
    }
};



// class Solution {
// public:
//     // 函数用于在一个二维矩阵中搜索一个目标值
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // 遍历矩阵的每一行
//         for(auto & row : matrix){
//             // 遍历行中的每个元素
//             for(int element : row){
//                 // 如果找到目标值，返回 true
//                 if(element == target){
//                     return true;
//                 }
//             }
//         }
//         // 如果遍历完整个矩阵都没有找到目标值，返回 false
//         return false;
//     }
// };


class Solution {
public:
    // 函数使用二分查找在一个按行排序的矩阵中搜索目标值
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 遍历矩阵的每一行
        for (auto& row : matrix) {
            // 使用 lower_bound 进行二分查找，找到第一个不小于 target 的元素
            auto it = lower_bound(row.begin(), row.end(), target);
            // 如果迭代器未达到行末尾，并且该位置的元素等于 target，则返回 true
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        // 如果在任何行中都没有找到目标值，返回 false
        return false;
    }
};




int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    bool found = solution.searchMatrix(matrix, target);
    if (found) {
        std::cout << "Target " << target << " found in the matrix." << std::endl;
    }
    else {
        std::cout << "Target " << target << " not found in the matrix." << std::endl;
    }

    return 0;
}