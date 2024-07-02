#include <vector>
#include <iostream>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0; // ���ָ�룬������ͷ����ʼ
        int right = numbers.size() - 1; // �Ҳ�ָ�룬������β����ʼ

        while (left < right) { // ѭ��ֱ������ָ������
            int sum = numbers[left] + numbers[right]; // ���㵱ǰ����ָ��ָ���Ԫ��֮��

            if (sum == target) {
                return { left + 1, right + 1 }; // �����ΪĿ��ֵ��������Խ�
            }
            else if (sum < target) {
                left++; // �����С��Ŀ��ֵ���ƶ����ָ������
            }
            else {
                right--; // ����ʹ���Ŀ��ֵ���ƶ��Ҳ�ָ������
            }
        }

        return {}; // ���û���ҵ��⣬���ؿ����飨��Ȼ��Ŀ������������ģ������ҵ��⣩
    }
};

int main() {
    Solution solution;
    std::vector<int> numbers = { 2, 7, 11, 15 };
    int target = 9;

    std::vector<int> result = solution.twoSum(numbers, target);
    if (!result.empty()) {
        std::cout << "Two Sum found: " << result[0] << " and " << result[1] << std::endl;
    }
    else {
        std::cout << "No two sum found." << std::endl;
    }

    return 0;
}