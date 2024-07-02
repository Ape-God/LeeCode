#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
//    int trap(vector<int>& height) {
//        int n = height.size();
//        if (n == 0) return 0;
//
//        vector<int> leftMax(n), rightMax(n);
//
//        // �������ҵ�ÿ��λ���������߶�
//        leftMax[0] = height[0];
//        for (int i = 1; i < n; ++i) {
//            leftMax[i] = max(leftMax[i - 1], height[i]);
//        }
//
//        // ���ҵ����ҵ�ÿ��λ���Ҳ�����߶�
//        rightMax[n - 1] = height[n - 1];
//        for (int i = n - 2; i >= 0; --i) {
//            rightMax[i] = max(rightMax[i + 1], height[i]);
//        }
//
//        // ������Խ�ס����ˮ��
//        int water = 0;
//        for (int i = 0; i < n; ++i) {
//            // ˮ���ǵ�ǰλ���������߶ȵĽ�Сֵ�뵱ǰ�߶ȵĲ�
//            water += min(leftMax[i], rightMax[i]) - height[i];
//        }
//
//        return water;
//    }
//};

class Solution {
public:
    int trap(vector<int> height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        while (left < right) {
            leftmax = max(leftmax, height[left]);
            rightmax = max(rightmax, height[right]);
            if (height[left] < height[right]) {
                ans += leftmax - height[left];
                left++;
            }
            else if (height[left] >= height[right]){
                ans += rightmax - height[right];
                right--;
            }
        }


        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };

    int result = solution.trap(height);
    cout << "The amount of trapped rain water is: " << result << endl;

    return 0;
}