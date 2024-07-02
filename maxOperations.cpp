#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // �����������ڼ�����������
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> numCounts; // ������ϣ���¼ÿ�����ֳ��ֵĴ���
        int operations = 0; // ��ʼ��������

        // �������飬��¼ÿ�����ֵĳ��ִ���
        for (int num : nums) {
            numCounts[num]++; // ���Ӷ�Ӧ���ֵļ���
        }

        // ������ϣ��������Գɶ��Ƴ��Ĳ�����
        for (auto& pair : numCounts) {
            int complement = k - pair.first; // ���㲹��
            if (complement == pair.first) { // ��������뵱ǰ������ͬ���ɶԳ���
                operations += pair.second / 2; // ÿ�Բ������Ƴ���������
            }
            else if (numCounts.find(complement) != numCounts.end()) { // ������������ڹ�ϣ����
                operations += min(pair.second, numCounts[complement]); // ���㵱ǰ���ֺͲ����Ľ�Сֵ
            }
        }

        return operations; // ������������
    }
};


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, count = 0;
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                count++;
                left++;
                right--;
            }
            else if (nums[left] + nums[right] < k) {
                left++;
            }
            else {
                right--;
            }
        }
        return count;
    }
};



// ʾ��������������ʾ Solution ��� maxOperations ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 1, 2, 3, 4, 3, 2, 3, 1 };
    int k = 5;
    // ���� maxOperations ������������
    cout << "The maximum number of operations is: " << solution.maxOperations(nums, k) << endl;

    return 0;
}