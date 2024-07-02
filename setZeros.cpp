#include <vector>
#include <iostream>
using namespace std;

//class Solution {
//public:
//    void setZeroes(std::vector<std::vector<int>>& matrix) {
//        int m = matrix.size();
//        if (m == 0) return;
//        int n = matrix[0].size();
//
//        // 使用第一行和第一列来记录需要置零的行和列
//        bool firstRowZero = false, firstColZero = false;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (matrix[i][j] == 0) {
//                    if (i == 0) firstRowZero = true;
//                    if (j == 0) firstColZero = true;
//                    // 使用第一行和第一列来记录置零信息
//                    matrix[i][0] = 0;
//                    matrix[0][j] = 0;
//                }
//            }
//        }
//
//        // 根据第一行和第一列的信息，将对应的行和列置零
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//
//        // 如果第一行或第一列需要置零，则在最后进行处理
//        if (firstRowZero) {
//            for (int j = 0; j < n; ++j) {
//                matrix[0][j] = 0;
//            }
//        }
//        if (firstColZero) {
//            for (int i = 0; i < m; ++i) {
//                matrix[i][0] = 0;
//            }
//        }
//    }
//};

class Solution {
public:
    // 函数用于将矩阵中所有0和0所在行与列的其它元素都设为0
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();  // 获取矩阵的行数
        int n = matrix[0].size();  // 获取矩阵的列数
        // 初始化两个向量，分别记录需要置0的行和列
        vector<int> row(m, 0), col(n, 0);

        // 第一次遍历，标记包含0的行和列
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 找到0，标记对应行和列
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }

        // 第二次遍历，根据标记结果置0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果行或列被标记，则将对应元素置0
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    solution.setZeroes(matrix);

    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}