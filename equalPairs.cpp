#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // ��ȡ���� grid �Ĵ�С��������������

        // ����һ�� map�����ڴ洢ÿһ�е�Ԫ�����У���Ϊ vector��������ִ���
        map<vector<int>, int> cnt;

        // ���� grid �е�ÿһ��
        for (auto row : grid) {
            // ���� map �ļ���ҪΨһ��������������Ҫÿһ�ж����ź���ģ�
            // ��ԭ����û����������Ǳ�ڵ��߼�����
            cnt[row]++; // ��ÿһ�е�Ԫ��������Ϊ�������ִ�����Ϊֵ������ map
        }

        int res = 0; // ��ʼ�����������Ϊ 0

        // ���� grid ��ÿһ��
        for (int j = 0; j < n; ++j) {
            vector<int> arr; // ���ڴ洢��ǰ�е�Ԫ��
            // ��ȡ grid �ĵ� j ��
            for (int i = 0; i < n; ++i) {
                arr.emplace_back(grid[i][j]);
            }
            // ��鵱ǰ�е�Ԫ�������Ƿ��� map �д���
            // ������ڣ��ۼӸ����г��ֵĴ�������������� res
            if (cnt.find(arr) != cnt.end()) {
                res += cnt[arr];
            }
        }

        // ����������жԵ�����
        return res;
    }
};



// ʾ��������������ʾ Solution ��� equalPair ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<vector<int>> grid = {
        {3, 2, 1},
        {1, 2, 3},
        {2, 1, 3}
    };

    // ���� equalPair ������������
    int result = solution.equalPairs(grid);
    cout << "The number of equal row-column pairs is: " << result << endl;

    return 0;
}