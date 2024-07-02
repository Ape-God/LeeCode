#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    // ����������һ����ά����������һ��Ŀ��ֵ
//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        if (matrix.empty() || matrix[0].empty()) return false;
//        // �������Ƿ�Ϊ�ջ����
//
//        int rows = matrix.size();  // ��ȡ���������
//        int cols = matrix[0].size();  // ��ȡ���������
//
//        // �����Ͻǿ�ʼ��������ʼ���к��е�����
//        int row = 0;
//        int col = cols - 1;
//
//        // ʹ�� while ѭ������������ֱ�������������±߽�������������ϱ߽�
//        while (row < rows && col >= 0) {
//            if (matrix[row][col] == target) {
//                return true;  // ����ҵ�Ŀ��ֵ������ true
//            }
//            else if (matrix[row][col] > target) {
//                col--;  // �����ǰԪ�ش���Ŀ��ֵ����������1�������ƶ�
//            }
//            else {
//                row++;  // �����ǰԪ��С��Ŀ��ֵ����������1�������ƶ�
//            }
//        }
//
//        return false;  // ���û���ҵ�Ŀ��ֵ������ false
//    }
//};

class Solution {
public:
    // ����ʹ�ö��ֲ�����һ����������ľ���������Ŀ��ֵ
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        // ʹ�� upper_bound ����Ӧ�ÿ�ʼ��������
        // ����ʹ����һ���Զ���ıȽϺ�����ȷ���ҵ����ڻ���� target �ĵ�һ��Ԫ��
        auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int>& a) {
            return b < a[0];
            });

        // ��� row �� matrix �ĵ�һ��Ԫ�أ�˵�� target �Ⱦ���������Ԫ�ض��󣬷��� false
        if (row == matrix.begin()) {
            return false;
        }

        // �˻ص�ǰһ�У���Ϊ upper_bound �����Ѿ������� target ���ڵķ�Χ
        --row;

        // ���ҵ�������ʹ�� binary_search ���ж��ֲ���
        return binary_search(row->begin(), row->end(), target);
    }
};



// class Solution {
// public:
//     // ����������һ����ά����������һ��Ŀ��ֵ
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         // ���������ÿһ��
//         for(auto & row : matrix){
//             // �������е�ÿ��Ԫ��
//             for(int element : row){
//                 // ����ҵ�Ŀ��ֵ������ true
//                 if(element == target){
//                     return true;
//                 }
//             }
//         }
//         // �����������������û���ҵ�Ŀ��ֵ������ false
//         return false;
//     }
// };


class Solution {
public:
    // ����ʹ�ö��ֲ�����һ����������ľ���������Ŀ��ֵ
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // ���������ÿһ��
        for (auto& row : matrix) {
            // ʹ�� lower_bound ���ж��ֲ��ң��ҵ���һ����С�� target ��Ԫ��
            auto it = lower_bound(row.begin(), row.end(), target);
            // ���������δ�ﵽ��ĩβ�����Ҹ�λ�õ�Ԫ�ص��� target���򷵻� true
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        // ������κ����ж�û���ҵ�Ŀ��ֵ������ false
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