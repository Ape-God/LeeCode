#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    // �������������ҵ����������е����ֵ
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // �洢�������ֵ������
        deque<int> dq; // ʹ��˫�˶��д洢����Ԫ�ص�����

        for (int i = 0; i < nums.size(); ++i) {
            // ά��˫�˶��У�ȷ������ʼ���ǵ�ǰ���ڵ����ֵ
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // �����ڴ�С����kʱ���Ƴ�����ǰ�˵�Ԫ�ص�����
            if (i >= k && dq.front() == i - k) {
                dq.pop_front();
            }

            // ά�����������ÿ�����ڵ����ֵ
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result; // ���ػ��������е����ֵ
    }
};

// ʾ��������������ʾ Solution ��� maxSlidingWindow ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    // ���� maxSlidingWindow ������������
    vector<int> max_values = solution.maxSlidingWindow(nums, k);
    cout << "Maximum values in the sliding window of size " << k << ": ";
    for (int max_val : max_values) {
        cout << max_val << " ";
    }
    cout << endl;

    return 0;
}