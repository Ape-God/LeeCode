#include <iostream>
#include <vector>
#include <algorithm> // ���� std::sort
using namespace std;

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty()) return 0;

    // ��������Ľ��������������
    std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
        });

    int count = 1; // ������Ҫһ֧��
    int end = points[0][1]; // ��ǰ�������Ҷ�

    for (int i = 1; i < points.size(); ++i) {
        // �����ǰ����Ŀ�ʼ������� end��˵����Ҫ�µļ�
        if (points[i][0] > end) {
            count++;
            end = points[i][1]; // �������Ҷ�
        }
        // �����ǰ����֮ǰ�ļ�����������Ҫ�µļ�
        else if (points[i][1] < end) {
            end = points[i][1]; // ���µ�ǰ�������Ҷ�
        }
    }

    return count;
}

int main() {
    std::vector<std::vector<int>> points = { {10, 16}, {2, 8}, {1, 6}, {7, 12} };
    int result = findMinArrowShots(points);
    std::cout << "The minimum number of arrows needed is: " << result << std::endl; // Ӧ����� 2
    return 0;
}