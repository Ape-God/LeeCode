#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, char> s_to_t;
    std::unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.length(); ++i) {
        char sc = s[i], tc = t[i];

        // 如果s中的字符sc已经映射过，检查映射是否与当前的tc一致
        if (s_to_t.find(sc) != s_to_t.end() && s_to_t[sc] != tc) {
            return false;
        }
        // 否则，建立从s到t的映射关系
        s_to_t[sc] = tc;

        // 如果t中的字符tc已经映射过，检查映射是否与当前的sc一致
        if (t_to_s.find(tc) != t_to_s.end() && t_to_s[tc] != sc) {
            return false;
        }
        // 否则，建立从t到s的映射关系
        t_to_s[tc] = sc;
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";
    bool result = isIsomorphic(s, t);
    std::cout << "Are \"" << s << "\" and \"" << t << "\" isomorphic? " << (result ? "Yes" : "No") << std::endl;
    return 0;
}