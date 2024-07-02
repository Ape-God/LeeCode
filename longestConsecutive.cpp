#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_map<int, bool> num_map;
    int max_length = 0;

    // ��¼ÿ�����ֳ��ֵĴ��������������ֻ���������Ƿ���ֹ������Դ���Ϊ1���ɣ�
    for (int num : nums) {
        num_map[num] = true;
    }

    // ������ϣ���ҳ����������
    for (const auto& pair : num_map) {
        int current_num = pair.first;
        if (num_map.find(current_num - 1) == num_map.end()) { // �����ǰ���ֵ�ǰһ�����ֲ��ڹ�ϣ����
            int length = 1; // ��ʼ������Ϊ1
            // ������չ��������
            while (num_map.find(current_num + length) != num_map.end()) {
                ++length;
            }
            // ������������еĳ���
            max_length = std::max(max_length, length);
        }
    }

    return max_length;
}

int main() {
    std::vector<int> nums = { 100, 4, 200, 1, 3, 2 };
    int result = longestConsecutive(nums);
    std::cout << "The length of the longest consecutive sequence is: " << result << std::endl;
    return 0;
}