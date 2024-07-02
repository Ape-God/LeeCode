#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        // ���ַ�����ĩβ��ʼ����
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        while (index >0 && s[index] < s.size()-1) {
            length++;
            index--;
        }

        //for (int i = s.size() - 1; i >= 0; --i) {
        //    // �������ǿո��ַ�ʱ����ʼ�������ʳ���
        //    if (s[i] != ' ') {
        //        length++;
        //    }
        //    // ��������ո����Ѿ������˵��ʳ��ȣ���ֹͣ����
        //    else if (length > 0) {
        //        break;
        //    }
        //}
        return length;
    }
};

int main() {
    Solution solution;
    string s = "Hello World";

    int result = solution.lengthOfLastWord(s);
    cout << "The length of the last word is: " << result << endl;

    return 0;
}