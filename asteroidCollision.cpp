#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // 使用向量作为栈来存储小行星

        // 遍历输入数组中的每个小行星
        for (auto aster : asteroids) {
            bool alive = true; // 假设当前小行星存活

            // 当当前小行星是向左移动的，且栈不为空，且栈顶小行星是向右移动的
            while (alive && aster < 0 && !st.empty() && st.back() > 0) {
                // 如果栈顶小行星小于当前小行星，则栈顶小行星爆炸，从栈中移除
                // alive 标志位更新为 false，因为当前小行星将被摧毁
                alive = st.back() < -aster;

                // 如果两个小行星大小相同，它们将相互爆炸，从栈中移除
                if (st.back() == -aster) {
                    st.pop_back(); // 移除栈顶小行星
                    alive = false; // 更新 alive 为 false，因为当前小行星也爆炸了
                }
                else if (st.back() <= -aster) {
                    st.pop_back(); // 移除较小的栈顶小行星
                }
                // 如果当前小行星小于栈顶小行星，它将爆炸，不会进入 if 条件
            }

            // 如果当前小行星存活（没有在碰撞中爆炸），则将其加入栈中
            if (alive) {
                st.push_back(aster);
            }
        }

        // 返回剩余的小行星列表
        return st;
    }
};


// 示例函数，用于演示 Solution 类的 asteroidCollision 方法
int main() {
    Solution solution;
    // 创建一个示例小行星数组
    vector<int> asteroids = { 5, 10, -5 };

    // 调用 asteroidCollision 方法并输出结果
    vector<int> result = solution.asteroidCollision(asteroids);
    cout << "The remaining asteroids after collisions: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}