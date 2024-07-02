#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//    bool dfs(std::string& s1, std::string& s2, std::string& s3, int p1, int p2, int p3) {
//        if (p3 == s3.length()) return true;
//
//        if (p1 < s1.length() && s1[p1] == s3[p3]) {
//            if (dfs(s1, s2, s3, p1 + 1, p2, p3 + 1)) return true;
//        }
//
//        if (p2 < s2.length() && s2[p2] == s3[p3]) {
//            return dfs(s1, s2, s3, p1, p2 + 1, p3 + 1);
//        }
//
//        return false;
//    }
//
//
//    bool isInterleave(std::string s1, std::string s2, std::string s3) {
//        if (s1.length() + s2.length() != s3.length()) return false;
//
//        return dfs(s1, s2, s3, 0, 0, 0);
//    }
//
//};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int>(s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};



int main() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    Solution solution;
    bool result = solution.isInterleave(s1, s2, s3);

    std::cout << "Is " << s3 << " an interleaving of " << s1 << " and " << s2 << "? " << (result ? "Yes" : "No") << std::endl;
    return 0;
}