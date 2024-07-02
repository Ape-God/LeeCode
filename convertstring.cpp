#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= numRows) {
            return s;
        }

        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (const auto& row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "LEETCODEISHIRING";
    int numRows = 3;
    string result = solution.convert(s, numRows);
    cout << "Transformed string: " << result << endl;
    return 0;
}




/*初始化:

curRow 初始化为 0，表示从顶部开始。
goingDown 初始化为 false，表示初始方向是向下。
遍历字符串 :

通过循环遍历字符串 s 中的每个字符 c。
添加字符 :

rows[curRow] += c; 将当前字符追加到 rows 数组的当前行 curRow。
检查边界 :

如果 curRow 达到数组的顶部（curRow == 0）或底部（curRow == numRows - 1），则需要改变方向。这是通过翻转布尔值 goingDown 来实现的。
更新当前行 :

curRow += goingDown ? 1 : -1; 根据当前的移动方向更新 curRow。如果 goingDown 为 true（向下移动），curRow 增加 1；如果 goingDown 为 false（向上移动），curRow 减少 1。
实现 "Z" 字形:

当 curRow 从 0 开始向下移动时，它会逐行向下添加字符，直到达到最后一行(numRows - 1)。
到达最后一行后，curRow 开始向上移动，逐行向上添加字符，直到回到第一行。
这个过程模拟了 "Z" 字形的中间下行和上行，形成了 "Z" 字形的一条对角线。
特殊情况 :

如果 numRows 只有一个（numRows == 1），则 rows 将只有一个元素，所有字符都将添加到这个元素中，保持原始顺序。
如果 numRows 为 2 或更高，且字符串长度足够，字符将按照 "Z" 字形的规则添加到 rows 中。
构建结果 :

最后，通过遍历 rows 并将每一行拼*/