#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; // ָ��������Чβ����ָ��
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[j] = nums[i]; // ��������val��Ԫ���ƶ���ǰ��
                ++j; // �ƶ�ָ��
            }
        }
        return j; // ������val��ͬ��Ԫ�ص�����
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;

    int newLength = solution.removeElement(nums, val);
    cout << "The number of elements after removal: " << newLength << endl;
    // ��ӡ�����ǰ newLength ��Ԫ��
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}