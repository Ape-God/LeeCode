#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    std::vector<std::vector<std::string>> res;

    // 遍历字符串数组，对每个字符串进行排序并作为哈希表的键
    for (const auto& str : strs) {
        std::string sorted_str = str;
        std::sort(sorted_str.begin(), sorted_str.end());
        map[sorted_str].push_back(str);
    }

    // 将哈希表中的所有列表添加到结果中
    for (const auto& pair : map) {
        res.push_back(pair.second);
    }

    return res;
}

int main() {
    std::vector<std::string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    std::vector<std::vector<std::string>> anagrams = groupAnagrams(strs);

    // 打印结果
    for (const auto& group : anagrams) {
        std::cout << "[";
        for (size_t i = 0; i < group.size(); ++i) {
            std::cout << group[i];
            if (i < group.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}