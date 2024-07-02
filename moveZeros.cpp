#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int nonZeroCount = 0; // ��¼����Ԫ�ص�����
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            // �����ǰԪ���Ƿ���ģ������ƶ���ǰ��
            nums[nonZeroCount++] = nums[i];
        }
    }
    // ��ʣ���λ����0���
    for (int i = nonZeroCount; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

class Solution {
public:
    // �����������ڽ������е����ƶ���ĩβ��ͬʱ���ַ���Ԫ�ص�˳��
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(); // ��ȡ����ĳ���
        int left = 0, right = 0; // ��ʼ������ָ��

        // ʹ�� while ѭ����ֱ����ָ���������������
        while (right < n) {
            // �����ǰԪ���Ƿ���Ԫ��
            if (nums[right]) {
                // ������ָ�����ָ����ָ���Ԫ�أ�������Ԫ���ƶ������
                swap(nums[left], nums[right]);
                // ��ָ�����ƣ�ָ����һ���������Ԫ��
                left++;
            }
            // ���۵�ǰԪ�����㻹�Ƿ��㣬��ָ�붼�����ƶ�
            right++;
        }
    }
};



int main() {
    vector<int> nums = { 0, 1, 0, 3, 12 };
    Solution solution;
    solution.moveZeroes(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}