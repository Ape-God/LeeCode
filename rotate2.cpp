#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 函数用于旋转正方形矩阵180度
    void rotate(vector<vector<int>>& matrix) {
        // 获取矩阵的边长
        int n = matrix.size();

        /*
        以下是被注释掉的旋转矩阵的方法，使用四个循环实现矩阵的转置和翻转
        // 遍历矩阵的上三角部分（包括对角线）
        for(int i = 0; i < n / 2; ++i){
            // 对于每一行，遍历到该行的中间点
            for(int j = 0; j < (n + 1) / 2; ++j){
                // 临时变量用于交换值
                int temp = matrix[i][j];
                // 交换当前位置与镜像位置的元素
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                // 交换上述交换后的元素与另一对角线上的元素
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
        */

        // 使用更简洁的方法旋转矩阵
        // 遍历矩阵的上半部分，交换对角线上的元素
        for (int i = 0; i < n; ++i) {
            // 对于每一行，交换该行的元素与其对称行的对应元素
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 遍历矩阵的列，交换每一列的上下对称元素
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};


int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 打印原始矩阵
    std::cout << "Original matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // 旋转矩阵
    solution.rotate(matrix);

    // 打印旋转后的矩阵
    std::cout << "Rotated matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}