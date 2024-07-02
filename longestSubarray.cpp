#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    // �����������ڼ����ȫ1������ĳ���
//    int longestSubarray(vector<int>& nums) {
//        int maxLength = 0; // ��ʼ��������鳤��
//        int currentLength = 0; // ��ǰ�����鳤��
//        int zeroCount = 0; // ������0������
//
//        for (int num : nums) {
//            // �����ǰ������1�����ӵ�ǰ�����鳤��
//            if (num == 1) {
//                currentLength++;
//            }
//            else {
//                // �����ǰ������0�����õ�ǰ�����鳤��Ϊ1
//                // ������������0������
//                maxLength = max(maxLength, currentLength);
//                currentLength = 1;
//                zeroCount++;
//            }
//        }
//        // ��󣬼���Ƿ���Ҫ��������ȣ��������ĩβû��0��
//        maxLength = max(maxLength, currentLength);
//
//        // �������������һ��0����������� - 1
//        // ��Ϊ��Ҫɾ��һ��Ԫ��
//        if (zeroCount > 0) {
//            return maxLength - 1;
//        }
//        // ���û������0�����������
//        return maxLength;
//    }
//};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0, res = 0, n = nums.size();
        // ʹ�� while ѭ��ֱ�� r ��������������
        while (r < n) {
            // �����ǰԪ���� 0�����Ӽ���
            if (nums[r] == 0) {
                cnt++;
            }
            // ����������һ�� 0 ʱ���ƶ� l ָ��
            // ֱ�����������ֻ��һ�� 0
            while (cnt > 1) {
                if (nums[l] == 0) {
                    cnt--; // ��� l ָ���Ԫ���� 0�����ټ���
                }
                l++; // �ƶ� l ָ��
            }
            // ���½�� res��Ϊ��ǰ���ڵĳ��ȣ�r - l��
            res = max(res, r - l);
            // �ƶ� r ָ�룬���������һ��Ԫ��
            r++;
        }
        // �����ȫ 1 ������ĳ���
        return res;
    }
};




// ʾ��������������ʾ Solution ��� longestSubarray ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 1, 1, 0, 1, 1, 0, 1 };
    // ���� longestSubarray ������������
    cout << "The length of the longest subarray with all elements being 1 after removing one element is: "
        << solution.longestSubarray(nums) << endl;

    return 0;
}