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




/*��ʼ��:

curRow ��ʼ��Ϊ 0����ʾ�Ӷ�����ʼ��
goingDown ��ʼ��Ϊ false����ʾ��ʼ���������¡�
�����ַ��� :

ͨ��ѭ�������ַ��� s �е�ÿ���ַ� c��
����ַ� :

rows[curRow] += c; ����ǰ�ַ�׷�ӵ� rows ����ĵ�ǰ�� curRow��
���߽� :

��� curRow �ﵽ����Ķ�����curRow == 0����ײ���curRow == numRows - 1��������Ҫ�ı䷽������ͨ����ת����ֵ goingDown ��ʵ�ֵġ�
���µ�ǰ�� :

curRow += goingDown ? 1 : -1; ���ݵ�ǰ���ƶ�������� curRow����� goingDown Ϊ true�������ƶ�����curRow ���� 1����� goingDown Ϊ false�������ƶ�����curRow ���� 1��
ʵ�� "Z" ����:

�� curRow �� 0 ��ʼ�����ƶ�ʱ������������������ַ���ֱ���ﵽ���һ��(numRows - 1)��
�������һ�к�curRow ��ʼ�����ƶ���������������ַ���ֱ���ص���һ�С�
�������ģ���� "Z" ���ε��м����к����У��γ��� "Z" ���ε�һ���Խ��ߡ�
������� :

��� numRows ֻ��һ����numRows == 1������ rows ��ֻ��һ��Ԫ�أ������ַ�������ӵ����Ԫ���У�����ԭʼ˳��
��� numRows Ϊ 2 ����ߣ����ַ��������㹻���ַ������� "Z" ���εĹ�����ӵ� rows �С�
������� :

���ͨ������ rows ����ÿһ��ƴ*/