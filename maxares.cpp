#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // �������������ҳ�һ����״ͼ�е����������
    int maxArea(vector<int>& height) {
        int max_area = 0; // ��ʼ��������Ϊ0
        int left = 0, right = height.size() - 1; // ��ʼ������ָ��

        // ʹ�� while ѭ��������ָ��С����ָ��ʱ����
        while (left < right) {
            // ���㵱ǰ���ε�������䳤Ϊ��ָ������ָ��֮��ľ���
            // ��Ϊ����ָ��ָ�����״ͼ�еĽ�Сֵ
            int curr_area = min(height[left], height[right]) * abs(right - left);
            // ����������
            max_area = max(max_area, curr_area);

            // �ƶ������Ǹ����ӵ�ָ�룬��С������Χ
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        // ���ؼ���������������
        return max_area;
    }
};

// ʾ������
#include <iostream>

int main() {
    Solution solution;
    std::vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int max_area = solution.maxArea(height);
    std::cout << "Maximum water area: " << max_area << std::endl;
    return 0;
}