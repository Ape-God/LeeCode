#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // �����������ڶ���ɫ��������
    void sortColors(vector<int>& nums) {
        int n = nums.size(); // ��ȡ���鳤��
        int red = 0, white = 0, blue = n - 1; // ��ʼ������ָ��

        // ��������ֱ���м�ָ�벻Խ��
        while (white <= blue) {
            // �����ǰԪ���Ǻ�ɫ��������redָ����ָ��Ԫ�ؽ������ƶ�red��whiteָ��
            if (nums[white] == 0) {
                swap(nums[red], nums[white]);
                red++;
                white++;
            }
            // �����ǰԪ���ǰ�ɫ��ֻ�ƶ�whiteָ��
            else if (nums[white] == 1) {
                white++;
            }
            // �����ǰԪ������ɫ��������blueָ����ָ��Ԫ�ؽ������ƶ�blueָ��
            else {
                swap(nums[blue], nums[white]);
                blue--;
            }
        }
    }
};

// ʾ��������������ʾ Solution ��� sortColors ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 2, 0, 2, 1, 1, 0 };
    // ���� sortColors ������������
    solution.sortColors(nums);
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << (num == 0 ? "red" : (num == 1 ? "white" : "blue")) << " ";
    }
    cout << endl;

    return 0;
}