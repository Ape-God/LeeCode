#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // ʹ��������Ϊջ���洢С����

        // �������������е�ÿ��С����
        for (auto aster : asteroids) {
            bool alive = true; // ���赱ǰС���Ǵ��

            // ����ǰС�����������ƶ��ģ���ջ��Ϊ�գ���ջ��С�����������ƶ���
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                // ���ջ��С����С�ڵ�ǰС���ǣ���ջ��С���Ǳ�ը����ջ���Ƴ�
                // alive ��־λ����Ϊ false����Ϊ��ǰС���ǽ����ݻ�
                alive = st.back() < -aster;

                // �������С���Ǵ�С��ͬ�����ǽ��໥��ը����ջ���Ƴ�
                if (st.back() == -aster) {
                    st.pop_back(); // �Ƴ�ջ��С����
                    alive = false; // ���� alive Ϊ false����Ϊ��ǰС����Ҳ��ը��
                }
                else if (st.back() <= -aster) {
                    st.pop_back(); // �Ƴ���С��ջ��С����
                }
                // �����ǰС����С��ջ��С���ǣ�������ը��������� if ����
            }

            // �����ǰС���Ǵ�û������ײ�б�ը�����������ջ��
            if (alive) {
                st.push_back(aster);
            }
        }

        // ����ʣ���С�����б�
        return st;
    }
};


// ʾ��������������ʾ Solution ��� asteroidCollision ����
int main() {
    Solution solution;
    // ����һ��ʾ��С��������
    vector<int> asteroids = { 5, 10, -5 };

    // ���� asteroidCollision ������������
    vector<int> result = solution.asteroidCollision(asteroids);
    cout << "The remaining asteroids after collisions: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}