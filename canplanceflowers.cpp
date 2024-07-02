#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0; // ��¼�ܹ���ֲ�Ļ�������
        for (int i = 0; i < flowerbed.size(); ++i) {
            // ��鵱ǰλ���Ƿ�Ϊ�գ�0������������λ�ã�����еĻ���Ҳ�ǿյ�
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
                // ���������ֲ������ǰλ������Ϊ1�������ӻ�������
                flowerbed[i] = 1;
                count++;
                // ����Ѿ���ֲ���㹻�Ļ��䣬��ǰ����true
                if (count >= n) {
                    return true;
                }
            }
        }
        // ���û���㹻��λ����ֲ���䣬����false
        return count >= n;
    }
};

// ���Ժ���
void testSolution(Solution& solution, vector<int>& flowerbed, int n) {
    bool result = solution.canPlaceFlowers(flowerbed, n);
    cout << "Can place " << n << " flowers? " << (result ? "Yes" : "No") << endl;
}

int main() {
    Solution solution;
    vector<int> flowerbed1 = { 1, 0, 0, 0, 1, 0, 0 };
    int n1 = 2;
    testSolution(solution, flowerbed1, n1);

    vector<int> flowerbed2 = { 1, 0, 0, 0, 1, 0, 0 };
    int n2 = 3;
    testSolution(solution, flowerbed2, n2);

    return 0;
}