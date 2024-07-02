#include <vector>
#include <algorithm> // ����max����
#include <iostream>
using namespace std;

class Solution {
public:
    // ������ߺ���
    int largestAltitude(vector<int>& gain) {
        int highestAltitude = 0; // ���ڼ�¼��ߺ���
        int currentAltitude = 0; // ��ǰ���Σ���ʼΪ0

        // �������θ߶Ȳ�����
        for (int i = 0; i < gain.size(); ++i) {
            // ���µ�ǰ���θ߶�
            currentAltitude += gain[i];
            // ������ߺ��θ߶�
            highestAltitude = max(highestAltitude, currentAltitude);
        }

        // ���ؼ��������ߺ��θ߶�
        return highestAltitude;
    }
};

// ʾ������
int main() {
    Solution solution;
    vector<int> gain = { -5, 1, 5, 0, -7 }; // ʾ������

    int highestAltitude = solution.largestAltitude(gain); // ���ú���������ߺ���
    cout << "The highest altitude is: " << highestAltitude << endl; // �����ߺ���

    return 0;
}