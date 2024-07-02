#include <vector>
#include <iostream>
#include <deque>
using namespace std;

class Solution {
public:
    // �������������ҳ������г���Ϊ k ����������1������������ִ���
    int longestOnes(vector<int>& nums, int k) {
        int maxCount = 0; // ��ʼ�������1�ĸ���Ϊ0
        deque<int> zeroIndices; // ʹ��˫�˶��д洢0������

        int left = 0; // ��ʼ����߽�
        for (int right = 0; right < nums.size(); ++right) {
            // �����ǰԪ����0����¼������
            if (nums[right] == 0) {
                zeroIndices.push_back(right);
            }

            // �������е�0�ĸ�������k����Ҫ�ƶ���߽�
            while (zeroIndices.size() > k) {
                // �ƶ���߽絽��һ��1���Ҳ�
                left = zeroIndices.front() + 1;
                // �Ƴ���������0����Ϊ�����Ѿ��������
                zeroIndices.pop_front();
            }

            // ���������1�ĸ��������㵱ǰ���ڵĳ���
            maxCount = max(maxCount, right - left + 1);
        }

        // ���������1�ĸ���
        return maxCount;
    }
};

class Solution {
public:
    // �������������ҳ�������� k �� 0 ��������ĳ���
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0, n = nums.size(), res = 0;
        // l �� r ������ָ�룬cnt �Ǵ����� 0 ��������n �����鳤�ȣ�res �ǽ��
        while (r < n) {
            // �����ָ����ָ��Ԫ���� 0����������һ
            if (nums[r++] == 0) {
                cnt++;
            }
            // �������� 0 ���������� k ʱ���ƶ���ָ��
            // ֱ�������� 0 ������������ k
            while (cnt > k) {
                if (nums[l++] == 0) {
                    cnt--; // �����ָ����ָ��Ԫ���� 0����������һ
                }
            }
            // ���½�� res��Ϊ����ָ��֮��ľ���
            res = max(res, r - l);
        }
        return res; // �����������ĳ���
    }
};




// ���Ժ���
void testSolution(Solution& solution, vector<int>& nums, int k) {
    int result = solution.longestOnes(nums, k);
    cout << "The length of the longest ones is: " << result << endl;
}

int main() {
    Solution solution;
    vector<int> nums1 = { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 };
    int k1 = 2;
    testSolution(solution, nums1, k1);

    vector<int> nums2 = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    int k2 = 3;
    testSolution(solution, nums2, k2);

    return 0;
}