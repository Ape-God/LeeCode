#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    // ������������������ά�����е�һ��Ŀ��ֵ
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if (matrix.empty()) return false; // �������Ϊ�գ�����false
//
//        int rows = matrix.size();      // ��ȡ���������
//        int cols = matrix[0].size();   // ��ȡ���������
//
//        // �����Ͻǿ�ʼ����
//        int row = 0, col = cols - 1;
//
//        while (row < rows && col >= 0) {
//            if (matrix[row][col] == target) {
//                // ����ҵ�Ŀ��ֵ������true
//                return true;
//            }
//            else if (matrix[row][col] > target) {
//                // �����ǰԪ�ش���Ŀ��ֵ�������ƶ�
//                col--;
//            }
//            else {
//                // �����ǰԪ��С��Ŀ��ֵ�������ƶ�
//                row++;
//            }
//        }
//
//        // ���û���ҵ�Ŀ��ֵ������false
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






// ʾ��������������ʾ Solution ��� searchMatrix ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    // ���� searchMatrix ������������
    bool found = solution.searchMatrix(matrix, target);
    if (found) {
        cout << "Target " << target << " found in the matrix." << endl;
    }
    else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}