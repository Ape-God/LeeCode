#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 从左到右遍历顶部行
            for (int i = left; i <= right; ++i) {
                result.push_back(matrix[top][i]);
            }
            top++;

            // 从上到下遍历右侧列
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {
                // 从右到左遍历底部行
                for (int i = right; i >= left; --i) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                // 从下到上遍历左侧列
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};

//class Solution {
//private:
//    static constexpr int directions[4][2] = { 
//        {0, 1}, 
//        {1, 0}, 
//        {0, -1}, 
//        {-1, 0} 
//    };
//public:
//    vector<int> spiralOrder(vector<vector<int>>& matrix) {
//        if (matrix.size() == 0 || matrix[0].size() == 0) {
//            return {};
//        }
//
//        int rows = matrix.size(), columns = matrix[0].size();
//        vector<vector<bool>> visited(rows, vector<bool>(columns));
//        int total = rows * columns;
//        vector<int> order(total);
//
//        int row = 0, column = 0;
//        int directionIndex = 0;
//        for (int i = 0; i < total; i++) {
//            order[i] = matrix[row][column];
//            visited[row][column] = true;
//            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
//            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
//                directionIndex = (directionIndex + 1) % 4;
//            }
//            row += directions[directionIndex][0];
//            column += directions[directionIndex][1];
//        }
//        return order;
//    }
//};



int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12},
        {17, 28, 69, 76}
    };

    vector<int> spiralOrder = solution.spiralOrder(matrix);
    for (int num : spiralOrder) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}