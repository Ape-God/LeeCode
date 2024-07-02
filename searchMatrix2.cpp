#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    // 主函数，用于搜索二维矩阵中的一个目标值
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if (matrix.empty()) return false; // 如果矩阵为空，返回false
//
//        int rows = matrix.size();      // 获取矩阵的行数
//        int cols = matrix[0].size();   // 获取矩阵的列数
//
//        // 从右上角开始搜索
//        int row = 0, col = cols - 1;
//
//        while (row < rows && col >= 0) {
//            if (matrix[row][col] == target) {
//                // 如果找到目标值，返回true
//                return true;
//            }
//            else if (matrix[row][col] > target) {
//                // 如果当前元素大于目标值，向左移动
//                col--;
//            }
//            else {
//                // 如果当前元素小于目标值，向下移动
//                row++;
//            }
//        }
//
//        // 如果没有找到目标值，返回false
//        return false;
//    }
//};


//class Solution {
//public:
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        for (const auto& row : matrix) {
//            for (int element : row) {
//                if (element == target) {
//                    return true;
//                }
//            }
//        }
//        return false;
//    }
//};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};






// 示例函数，用于演示 Solution 类的 searchMatrix 方法
int main() {
    Solution solution;
    // 创建一个示例矩阵
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    // 调用 searchMatrix 方法并输出结果
    bool found = solution.searchMatrix(matrix, target);
    if (found) {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}