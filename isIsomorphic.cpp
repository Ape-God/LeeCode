#include <iostream>
#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) return false;

    std::unordered_map<char, char> s_to_t;
    std::unordered_map<char, char> t_to_s;

    for (int i = 0; i < s.length(); ++i) {
        char sc = s[i], tc = t[i];

        // ���s�е��ַ�sc�Ѿ�ӳ��������ӳ���Ƿ��뵱ǰ��tcһ��
        if (s_to_t.find(sc) != s_to_t.end() && s_to_t[sc] != tc) {
            return false;
        }
        // ���򣬽�����s��t��ӳ���ϵ
        s_to_t[sc] = tc;

        // ���t�е��ַ�tc�Ѿ�ӳ��������ӳ���Ƿ��뵱ǰ��scһ��
        if (t_to_s.find(tc) != t_to_s.end() && t_to_s[tc] != sc) {
            return false;
        }
        // ���򣬽�����t��s��ӳ���ϵ
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