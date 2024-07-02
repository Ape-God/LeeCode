#include <iostream>
#include <vector>
#include <algorithm> // ���� std::sort ����

class Solution {
public:
    // ���� h ָ���ķ���
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

// �����������ڵ��� hIndex ��������ӡ���
int main() {
    Solution solution;
    // ʾ����������ʾ���ĵ����ô���
    std::vector<int> citations = { 3, 0, 6, 1, 5 };
    // ���� hIndex ��������ӡ���
    int hIndex = solution.hIndex(citations);
    std::cout << "The h-index is: " << hIndex << std::endl;
    return 0;
}