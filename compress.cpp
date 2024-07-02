#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <algorithm> // ���� std::reverse

using namespace std;

class Solution {
public:
    // ������������ѹ���ַ����е��ַ�����Ӽ���
    int compress(vector<char>& chars) {
        int n = chars.size(); // ��ȡ�ַ�����ĳ���
        int write = 0, left = 0; // ��ʼ��д��λ�ú����е���ʼλ��
        for (int read = 0; read < n; ++read) { // �����ַ�����
            // ��������ַ���ĩβ��ǰ�ַ�����һ���ַ���ͬ
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                // ����ǰ�ַ����Ƶ� write λ��
                chars[write++] = chars[read];
                // ���㵱ǰ�ַ��������ֵĴ���
                int num = read - left + 1;
                // ����������ִ�������1������Ҫ��Ӽ���
                if (num > 1) {
                    // ��¼������Ҫ��ʼ��λ��
                    int anchor = write;
                    // ���������ִ���ת��Ϊ�ַ�����ӵ�������
                    while (num > 0) {
                        chars[write++] = num % 10 + '0'; // ת����ǰ���λ���ֲ���ӵ��ַ�����
                        num /= 10; // �Ƴ��Ѵ�������λ
                    }
                    // ��ת�����ַ���ʹ��ӵ͵���
                    reverse(&chars[anchor], &chars[write]);
                }
                // �������е���ʼλ��
                left = read + 1;
            }
        }
        // ����ѹ������ַ�������
        return write;
    }
};


// ���Ժ���
void testSolution(Solution& solution, vector<char>& chars) {
    int newSize = solution.compress(chars);
    cout << "Compressed size: " << newSize << ", Array: [";
    for (int i = 0; i < newSize; ++i) {
        cout << chars[i];
        if (i < newSize - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    vector<char> chars1 = { 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c' };
    testSolution(solution, chars1);

    vector<char> chars2 = { 'a' };
    testSolution(solution, chars2);

    return 0;
}