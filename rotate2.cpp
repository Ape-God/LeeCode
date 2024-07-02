#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // ����������ת�����ξ���180��
    void rotate(vector<vector<int>>& matrix) {
        // ��ȡ����ı߳�
        int n = matrix.size();

        /*
        �����Ǳ�ע�͵�����ת����ķ�����ʹ���ĸ�ѭ��ʵ�־����ת�úͷ�ת
        // ��������������ǲ��֣������Խ��ߣ�
        for(int i = 0; i < n / 2; ++i){
            // ����ÿһ�У����������е��м��
            for(int j = 0; j < (n + 1) / 2; ++j){
                // ��ʱ�������ڽ���ֵ
                int temp = matrix[i][j];
                // ������ǰλ���뾵��λ�õ�Ԫ��
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                // ���������������Ԫ������һ�Խ����ϵ�Ԫ��
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
        */

        // ʹ�ø����ķ�����ת����
        // ����������ϰ벿�֣������Խ����ϵ�Ԫ��
        for (int i = 0; i < n; ++i) {
            // ����ÿһ�У��������е�Ԫ������Գ��еĶ�ӦԪ��
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // ����������У�����ÿһ�е����¶Գ�Ԫ��
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

    // ��ӡԭʼ����
    std::cout << "Original matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // ��ת����
    solution.rotate(matrix);

    // ��ӡ��ת��ľ���
    std::cout << "Rotated matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}