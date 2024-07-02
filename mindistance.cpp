#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        // ��ʼ�� dp ��ĵ�һ�к͵�һ��
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }

        // ��� dp ��
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // �����ǰ�ַ���ͬ�����������
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // �����ǰ�ַ���ͬ���������п��ܵĲ���
                    dp[i][j] = std::min({
                        dp[i - 1][j] + 1,    // ɾ������
                        dp[i][j - 1] + 1,    // �������
                        dp[i - 1][j - 1] + 1 // �滻����
                        });
                }
            }
        }

        // ���ؽ� word1 ת���� word2 ��������ٲ�����
        return dp[len1][len2];
    }
};

int main() {
    Solution solution;
    std::string word1 = "intention";
    std::string word2 = "execution";

    int distance = solution.minDistance(word1, word2);
    std::cout << "The minimum edit distance between \"" << word1 << "\" and \"" << word2 << "\" is: " << distance << std::endl;

    return 0;
}