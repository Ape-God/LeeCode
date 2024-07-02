#include <vector>
#include <numeric> // ����accumulate����
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Ѱ������������±�
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0); // ������������Ԫ�ص��ܺ�
        int leftSum = 0; // ��ʼ�����Ԫ�صĺ�Ϊ0

        // ��������
        for (size_t i = 0; i < nums.size(); ++i) {
            // ������ĺ͵����Ҳ�ĺͣ��ܺͼ�ȥ��ǰԪ�غ����ĺͣ�
            if (leftSum == (totalSum - nums[i] - leftSum)) {
                return i; // ���ص�ǰ������Ϊ�����±�
            }
            // �������ĺ�
            leftSum += nums[i];
        }

        // ���û���ҵ������±꣬����-1
        return -1;
    }
};

// ʾ������
int main() {
    Solution solution;
    vector<int> nums = { 1, 7, 3, 6, 5, 6 }; // ʾ������

    int pivot = solution.pivotIndex(nums); // ���ú���Ѱ�������±�
    cout << "The pivot index is: " << (pivot != -1 ? to_string(pivot) : "None") << endl; // ��������±�

    return 0;
}