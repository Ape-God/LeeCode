#include<iostream>
#include<vector>

using namespace std;


//class Solution {
//public:
//    int removeElement(vector<int>& nums, int val)
//    {
//        vector<int>::iterator it = nums.begin();
//        while (it != nums.end())
//        {
//            if (*it == val)
//            {
//                it = nums.erase(it);
//            }
//            else
//            {
//                ++it;
//            }
//        }
//        return nums.size();
//    }
//};

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};



int main()
{
    vector<int> a = {1,4,3,6,7,3,4,5,7,2,7,3,8,9,2};
    Solution solution;
    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    int nums = solution.removeElement(a, 7);
    cout << nums << endl;
    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}