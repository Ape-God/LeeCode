#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 主函数，用于划分字符串为包含不重复字母的片段
    vector<int> partitionLabels(string s) {
        // 初始化一个数组 last 来存储每个字母最后一次出现的位置
        int last[26] = { 0 };
        // 获取字符串的长度
        int length = s.size();

        // 遍历字符串，记录每个字母最后一次出现的位置
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i; // 将字符转换为 0-25 的索引
        }

        // 初始化用于存储片段长度的向量
        vector<int> partition;
        // 初始化遍历的起始点和结束点
        int start = 0, end = 0;

        // 遍历字符串
        for (int i = 0; i < length; i++) {
            // 更新 end 为当前遍历的字母最后一次出现的位置
            end = max(end, last[s[i] - 'a']);
            // 如果当前索引 i 等于 end，说明找到了一个片段的结束
            if (i == end) {
                // 将当前片段的长度添加到 partition 中
                partition.push_back(end - start + 1);
                // 更新下一个片段的起始点
                start = end + 1;
            }
        }

        // 返回包含每个片段长度的向量
        return partition;
    }
};

//创建一个长度为26的数组last，用于记录每个字母（从'a'到'z'）在字符串s中最后一次出现的位置。
//通过一次遍历，初始化last数组。
//使用一个vector<int>来存储每个划分片段的长度。
//使用两个变量start和end来维护当前考虑的片段的起始和结束位置。
//通过第二次遍历，使用max函数更新end为当前片段中最远的字母的最后一次出现位置。
//当遍历到片段的结束位置时，计算片段长度并将其添加到结果向量中，并更新start为下一个片段的起始位置。
//最后返回包含所有片段长度的向量。



// 示例函数，用于演示 Solution 类的 partitionLabels 方法
int main() {
    Solution solution;
    // 创建一个示例字符串
    string s = "ababc";
    // 调用 partitionLabels 方法并输出结果
    vector<int> result = solution.partitionLabels(s);
    cout << "The lengths of each partition are: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}