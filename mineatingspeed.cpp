#include <iostream>
#include <vector>
#include <algorithm> // ���� std::max ����

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        // ��ʼ���ұ߽�Ϊ�����㽶��
        for (int pile : piles) {
            right = max(right, pile);
        }
        // ʹ�ö��ֲ�����С�ٶ� k
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // �����ǰ�ٶȿ����� h Сʱ�ڳ��������㽶
            if (canEatAll(piles, h, mid)) {
                right = mid - 1; // ���Ը�С���ٶ�
            }
            else {
                left = mid + 1; // ��Ҫ������ٶ�
            }
        }
        return left; // �����ҵ�����С�ٶ�
    }

private:
    // �ж��ٶ�Ϊ k ʱ�������Ƿ����� h Сʱ�ڳ��������㽶
    bool canEatAll(const vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k; // ����Ե�����㽶��Ҫ��Сʱ��
            if (hours > h) {
                return false; // ����ʱ�����ƣ����� false
            }
        }
        return true; // ������ h Сʱ�ڳ��������㽶������ true
    }
};

// ʾ������
int main() {
    Solution solution;
    vector<int> piles = { 3, 6, 7, 11 };
    int h = 8;
    cout << "Minimum eating speed required: " << solution.minEatingSpeed(piles, h) << endl;
    return 0;
}