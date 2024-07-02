//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        if (nums.size() < 3) {
//            return nums.size();
//        }
//
//        int slow = 2; // slowָ�룬���ڸ��ٿ��Է�����Ԫ�ص�λ��
//        for (int fast = 2; fast < nums.size(); ++fast) {
//            // �����ǰԪ�ز�����slowǰ����λ�õ�Ԫ�أ��������slowλ��
//            if (nums[fast] != nums[slow - 2]) {
//                nums[slow++] = nums[fast];
//            }
//        }
//        return slow; // �����µĳ���
//    }
//};
//
//int main() {
//    Solution solution;
//    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
//
//    int newLength = solution.removeDuplicates(nums);
//    cout << "The length after removing duplicates is: " << newLength << endl;
//
//    // ��ӡ��������֤���
//    for (int i = 0; i < newLength; ++i) {
//        cout << nums[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }

        int slow = 2; // slowָ�룬���ڸ��ٿ��Է�����Ԫ�ص�λ��
        for (int fast = 2; fast < nums.size(); ++fast) {
            // �����ǰԪ�ز�����slowǰ����λ�õ�Ԫ�أ��������slowλ��
            if (nums[fast] != nums[slow - 2]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow; // �����µĳ���
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    int newLength = solution.removeDuplicates(nums);
    cout << "The length after removing duplicates is: " << newLength << endl;

    // ��ӡ��������֤���
    for (int i = 0; i < newLength; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}