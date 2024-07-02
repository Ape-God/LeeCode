#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // �������������ҳ�ÿ��Ԫ�������������Ԫ�صĳ˻����Լ������Ҳ�����Ԫ�صĳ˻�
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); // ��ȡ��������Ĵ�С
        vector<int> answer(n, 1); // ��ʼ�������飬����Ԫ������Ϊ1

        // �����������Ԫ�صĳ˻�
        for (int i = 1; i < n; ++i) {
            // answer[i] Ϊ��ǰԪ��֮ǰ����Ԫ�صĳ˻�
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int rightProduct = 1; // ��ʼ���Ҳ�Ԫ�س˻�Ϊ1

        // �����Ҳ�����Ԫ�صĳ˻��������´�����
        for (int i = n - 1; i >= 0; --i) {
            // ����ǰ���Ҳ�˻��ۼӵ� answer[i] ��
            answer[i] *= rightProduct;
            // �����Ҳ�˻�
            rightProduct *= nums[i];
        }

        // ���ش�����
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = { 1, 2, 3, 4 };
    std::vector<int> product = solution.productExceptSelf(nums);

    std::cout << "Product of each element and its neighbors: ";
    for (int num : product) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}