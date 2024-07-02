#include <vector>
#include<iostream>
#include <numeric>
using namespace std;

//class Solution {
//public:
//    // �͵���ת����nums����k��
//    void rotate(vector<int>& nums, int k) {
//        int n = nums.size(); // ��ȡ����ĳ���
//        // �˴����뱻ע�͵��ˣ�ʵ�������д����Ǳ�Ҫ�ģ����ڴ���k�������鳤�ȵ����
//        // k = k % n;
//
//        // ���kΪ0��˵������Ҫ��ת��ֱ�ӷ���
//        if (k == 0) {
//            return;
//        }
//
//        // ����һ����ʱ�������洢��ת�������
//        vector<int> rotated(n);
//        // ��ԭ�����Ԫ�ظ��Ƶ���ʱ�������Ӧλ��
//        for (int i = 0; i < n; ++i) {
//            rotated[(i + k) % n] = nums[i]; // ʹ��ģ������������λ��
//        }
//
//        // ����ʱ�����Ԫ�ظ��ƻ�ԭ���飬�����ת
//        for (int i = 0; i < n; ++i) {
//            nums[i] = rotated[i];
//        }
//    }
//};


class Solution {
public:
    // �͵���ת����nums��Ԫ�أ�ʹ��������תk��
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(); // ��ȡ����ĳ���
        // ȡk�����鳤��n��ģ���Դ���k����n�����
        k = k % n;

        // ����k��n�����Լ�����Լ�����ת����
        // ��Ϊ���k��n�ı�����������ת�󲻻ᷢ���仯
        int count = gcd(k, n);

        // �������飬ÿ�δ�����Ϊcount��������
        for (int start = 0; start < count; ++start) {
            // ��ʼ����ǰ�����͸���������Ԫ��ֵ
            int current = start;
            int prev = nums[start];

            // ʹ��do-whileѭ��ʵ����ʽ����
            do {
                // ������һ��Ԫ�ص�������ʹ��ģn����ȷ�����������鷶Χ��
                int next = (current + k) % n;
                // ������ǰԪ�غ���һ��Ԫ�ص�ֵ
                // ʹ�ñ�׼���е�swap�������н���
                swap(nums[next], prev);
                // ���µ�ǰ����Ϊ��һ������
                current = next;
            }
            // ����ѭ��ֱ������Ԫ�ػص�ԭʼ��ʼλ�ã����һ����ת
            while (start != current);
        }
    }

    // gcd����ԭ�ͣ�ʵ�ʶ����������������
    // int gcd(int a, int b) {
};




int main() {
    // ����Solution����
    Solution solution;

    // ����һ���������鲢��ʼ��
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3; // ��ת����

    // ���ԭʼ����
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // ����rotate����������ת
    solution.rotate(nums, k);

    // �����ת�������
    cout << "Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}