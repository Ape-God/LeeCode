#include <iostream>
#include <vector>
using namespace std;

// ֱ�Ӳ���������
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // ��ȡ����Ĵ�С

    // �ӵڶ���Ԫ�ؿ�ʼ�������飨������1��ʼ��
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // ��ǰҪ�����Ԫ��
        int j = i - 1;

        // ������key��Ԫ�������ƶ�
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // ��key���뵽��ȷ��λ��
        arr[j + 1] = key;
    }
}

// ��ӡ����ĺ���
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ʾ������
int main() {
    vector<int> arr = { 9, 5, 1, 4, 3 }; // Ҫ���������

    cout << "Original array:\n";
    printArray(arr);

    // ���ò���������
    insertionSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}