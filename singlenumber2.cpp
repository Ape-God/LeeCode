#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int result = 0;
//        for (int i = 0; i < 32; ++i) {  // ����int���ͣ����32λ
//            int count = 0;
//            // ��һ�α����������iλΪ1�ĸ���
//            for (const int num : nums) {
//                if ((num >> i) & 1) {
//                    count++;
//                }
//            }
//            // �����������3�ı���������iλ�ӵ������
//            if (count % 3 != 0) {
//                result |= (1 << i);
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto  [num, occ] : freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};




int main() {
    Solution solution;
    vector<int> nums = { 30000, 500, 100, 30000, 100, 30000, 100 }; // ʾ������

    int single = solution.singleNumber(nums);
    cout << "The number that appears only once is: " << single << endl;

    return 0;
}