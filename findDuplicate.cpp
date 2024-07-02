#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> dupset; // ����һ����ϣ�������洢�Ѿ�����������
        for (int num : nums) {
            // ���num�Ѿ��ڼ����У�˵���ҵ����ظ�����
            if (dupset.find(num) != dupset.end()) {
                return num;
            }
            else {
                dupset.insert(num); // ���򣬽�num��ӵ�������
            }
        }
        return -1; // ���û���ҵ��ظ�����������-1��������Ŀ��֤һ�����ظ�������
    }
};



class Solution {
public:
    // �������������ҳ������е��ظ�����
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1; // ��ȡ���鳤�� n
        for (int i = 0; i <= n; ++i) {
            // ��ǰ����ָ���ֵ��ΪĿ������
            int target = nums[i] - 1; // ����ֵ��1��ʼ��������Ҫ��1
            while (nums[i] != nums[target]) {
                // ������ǰ������Ŀ��������ֵ
                swap(nums[i], nums[target]);
                // ����Ŀ������Ϊ��ǰֵ��Ӧ������
                target = nums[i] - 1;
            }
        }
        // ѭ�������󣬵�һ����ƥ���������Ϊ�ظ�����
        for (int i = 0; i <= n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return -1; // �����ϲ���ִ�е������Ϊ��Ŀ��֤�����ظ���
    }
};


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        // ��ʼ�����ֲ��ҵ����ұ߽�
        int l = 1, r = n - 1, ans = -1;
        // ִ�ж��ֲ���
        while (l <= r) {
            int mid = (l + r) >> 1; // �����м�ֵ
            int cnt = 0; // ���ڼ���С�ڻ����mid��Ԫ������
            // �������飬ͳ��С�ڻ����mid��Ԫ������
            for (int i = 0; i < n; ++i) {
                cnt += nums[i] <= mid;
            }
            // ����ͳ�Ƶ������������ұ߽�
            if (cnt <= mid) {
                l = mid + 1; // �������С�ڻ����mid���������Ұ벿��
            }
            else {
                r = mid - 1; // ����������벿�֣�������ǰmid��Ϊ���ܵĴ�
                ans = mid;
            }
        }
        // �����ҵ����ظ���
        return ans;
    }
};



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // ��ʼ����ָ��Ϳ�ָ��
        int slow = 0, fast = 0;
        do {
            // ��ָ��ÿ����һ������ָ��ÿ��������
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast); // ������ָ������ʱ��ѭ������

        // ���³�ʼ����ָ��Ϊ���
        slow = 0;
        // �ٴ��ƶ���ָ��Ϳ�ָ�룬������ǽ���ͬһλ����������ѭ������ڵ�
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // ����ѭ������ڵ㣬���ظ�����
        return slow;
    }
};





// ʾ��������������ʾ Solution ��� findDuplicate ����
int main() {
    Solution solution;
    // ����һ��ʾ������
    vector<int> nums = { 1, 3, 4, 2, 2 };
    // ���� findDuplicate ������������
    int duplicate = solution.findDuplicate(nums);
    cout << "The duplicate number is: " << duplicate << endl;

    return 0;
}