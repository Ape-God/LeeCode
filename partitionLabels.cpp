#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // �����������ڻ����ַ���Ϊ�������ظ���ĸ��Ƭ��
    vector<int> partitionLabels(string s) {
        // ��ʼ��һ������ last ���洢ÿ����ĸ���һ�γ��ֵ�λ��
        int last[26] = { 0 };
        // ��ȡ�ַ����ĳ���
        int length = s.size();

        // �����ַ�������¼ÿ����ĸ���һ�γ��ֵ�λ��
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i; // ���ַ�ת��Ϊ 0-25 ������
        }

        // ��ʼ�����ڴ洢Ƭ�γ��ȵ�����
        vector<int> partition;
        // ��ʼ����������ʼ��ͽ�����
        int start = 0, end = 0;

        // �����ַ���
        for (int i = 0; i < length; i++) {
            // ���� end Ϊ��ǰ��������ĸ���һ�γ��ֵ�λ��
            end = max(end, last[s[i] - 'a']);
            // �����ǰ���� i ���� end��˵���ҵ���һ��Ƭ�εĽ���
            if (i == end) {
                // ����ǰƬ�εĳ�����ӵ� partition ��
                partition.push_back(end - start + 1);
                // ������һ��Ƭ�ε���ʼ��
                start = end + 1;
            }
        }

        // ���ذ���ÿ��Ƭ�γ��ȵ�����
        return partition;
    }
};

//����һ������Ϊ26������last�����ڼ�¼ÿ����ĸ����'a'��'z'�����ַ���s�����һ�γ��ֵ�λ�á�
//ͨ��һ�α�������ʼ��last���顣
//ʹ��һ��vector<int>���洢ÿ������Ƭ�εĳ��ȡ�
//ʹ����������start��end��ά����ǰ���ǵ�Ƭ�ε���ʼ�ͽ���λ�á�
//ͨ���ڶ��α�����ʹ��max��������endΪ��ǰƬ������Զ����ĸ�����һ�γ���λ�á�
//��������Ƭ�εĽ���λ��ʱ������Ƭ�γ��Ȳ�������ӵ���������У�������startΪ��һ��Ƭ�ε���ʼλ�á�
//��󷵻ذ�������Ƭ�γ��ȵ�������



// ʾ��������������ʾ Solution ��� partitionLabels ����
int main() {
    Solution solution;
    // ����һ��ʾ���ַ���
    string s = "ababc";
    // ���� partitionLabels ������������
    vector<int> result = solution.partitionLabels(s);
    cout << "The lengths of each partition are: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}