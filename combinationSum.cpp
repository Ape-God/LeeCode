#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    // ���ݺ����������ҳ����п��ܵ����
//    void backtrack(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
//        if (target == 0) {
//            // �����ǰĿ��ֵΪ0��˵���ҵ���һ����Ч�����
//            result.push_back(current);
//            return;
//        }
//
//        for (int i = start; i < candidates.size(); ++i) {
//            // �����ǰ���ִ���ʣ��Ŀ��ֵ������Ҫ��������
//            if (candidates[i] > target) break;
//
//            // ѡ��ǰ���ֲ��ݹ�����
//            current.push_back(candidates[i]);
//            backtrack(i, target - candidates[i], candidates, current, result);  // �����ظ�ѡ��ͬһ������
//            current.pop_back();  // ���ݣ��Ƴ���ǰ����
//        }
//    }
//
//    // ����������ܺͺ���
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        sort(candidates.begin(), candidates.end());  // ����candidates���飬�Ա���м�֦
//        vector<int> current;  // ��ǰ���
//        vector<vector<int>> result;  // ������ϵ��б�
//        backtrack(0, target, candidates, current, result);  // ������0��ʼ�ݹ�����
//        return result;
//    }
//};


class Solution {
public:
    // �������������DFS�������������ҳ����п��ܵ����
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        // ������� idx ���� candidates �Ĵ�С��˵���Ѿ��������������֣�����
        if (idx == candidates.size()) {
            return;
        }
        // ��� target Ϊ 0��˵����ǰ����Ǻ�ΪĿ��ֵ��һ����Ч��ϣ���ӵ���� ans ��
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // ���Բ�ѡ��ǰ���� candidates[idx]����������
        dfs(candidates, target, ans, combine, idx + 1);
        // ���ʣ��Ŀ��ֵ���ڵ��ڵ�ǰ���֣�ѡ��ǰ����
        if (target - candidates[idx] >= 0) {
            // ����ǰ������ӵ������
            combine.emplace_back(candidates[idx]);
            // �ݹ���� dfs������ʣ��Ŀ��ֵΪ target - candidates[idx]
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            // ���ݣ��Ƴ�����е����һ�����֣��Ա㳢���������ܵ����
            combine.pop_back();
        }
    }

    // ����ܺͺ������������п��ܵ����
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // �洢���п��ܵ���Ͻ��
        vector<int> combine; // �洢��ǰ�����
        // ������ 0 ��ʼ������ dfs ���������������
        dfs(candidates, target, ans, combine, 0);
        return ans; // �������п��ܵ���Ͻ��
    }
};


// ʾ������
int main() {
    Solution solution;
    vector<int> candidates1 = { 2, 3, 6, 7 };
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);
    // ��ӡ���ʾ��1
    for (const auto& comb : result1) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates2 = { 2, 3, 5 };
    int target2 = 8;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);
    // ��ӡ���ʾ��2
    for (const auto& comb : result2) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    vector<int> candidates3 = { 2 };
    int target3 = 1;
    vector<vector<int>> result3 = solution.combinationSum(candidates3, target3);
    // ��ӡ���ʾ��3���ս����
    cout << "No combinations found." << endl;

    return 0;
}