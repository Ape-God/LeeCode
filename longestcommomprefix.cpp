#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // �������Ϊ�գ����ؿ��ַ���

        string prefix = strs[0]; // ������ĵ�һ���ַ�����Ϊ��ʼǰ׺
        for (const string& str : strs) {
            while (str.find(prefix) != 0) { // ֻҪprefix����str��ǰ׺
                prefix = prefix.substr(0, prefix.length() - 1); // ����prefix
                if (prefix.empty()) return ""; // ���ǰ׺Ϊ�գ�û�й���ǰ׺
            }
        }
        return prefix; // �����ҵ��������ǰ׺
    }
};

int main() {
    Solution solution;
    vector<string> strs = { "flower","flow","flight" };

    string result = solution.longestCommonPrefix(strs);
    if (!result.empty()) {
        cout << "The longest common prefix is: " << result << endl;
    }
    else {
        cout << "There is no common prefix." << endl;
    }

    return 0;
}