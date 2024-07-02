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
//        // ʹ�õ�һ�к͵�һ������¼��Ҫ������к���
//        bool firstRowZero = false, firstColZero = false;
//        for (int i = 0; i < m; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if (matrix[i][j] == 0) {
//                    if (i == 0) firstRowZero = true;
//                    if (j == 0) firstColZero = true;
//                    // ʹ�õ�һ�к͵�һ������¼������Ϣ
//                    matrix[i][0] = 0;
//                    matrix[0][j] = 0;
//                }
//            }
//        }
//
//        // ���ݵ�һ�к͵�һ�е���Ϣ������Ӧ���к�������
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
//                    matrix[i][j] = 0;
//                }
//            }
//        }
//
//        // �����һ�л��һ����Ҫ���㣬���������д���
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
    // �������ڽ�����������0��0���������е�����Ԫ�ض���Ϊ0
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();  // ��ȡ���������
        int n = matrix[0].size();  // ��ȡ���������
        // ��ʼ�������������ֱ��¼��Ҫ��0���к���
        vector<int> row(m, 0), col(n, 0);

        // ��һ�α�������ǰ���0���к���
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // �ҵ�0����Ƕ�Ӧ�к���
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }

        // �ڶ��α��������ݱ�ǽ����0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // ����л��б���ǣ��򽫶�ӦԪ����0
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