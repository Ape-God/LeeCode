#include <vector>
#include<iostream>

using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size(); // ���� nums ���� n ����
    // ���������ܺ�
    int theoreticalSum = n * (n + 1) / 2;
    // ����ʵ���ܺ�
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    // �ҳ�ȱʧ����
    return theoreticalSum - actualSum;
}

// ʾ��
int main() {
    vector<int> nums = { 3, 0, 1 }; // ȱʧ������ 2
    int missing = missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}