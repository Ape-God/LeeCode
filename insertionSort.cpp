#include <iostream>
#include <vector>
using namespace std;

// 直接插入排序函数
void insertionSort(vector<int>& arr) {
    int n = arr.size(); // 获取数组的大小

    // 从第二个元素开始遍历数组（索引从1开始）
    for (int i = 1; i < n; ++i) {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;

        // 将大于key的元素向右移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // 将key插入到正确的位置
        arr[j + 1] = key;
    }
}

// 打印数组的函数
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 示例调用
int main() {
    vector<int> arr = { 9, 5, 1, 4, 3 }; // 要排序的数组

    cout << "Original array:\n";
    printArray(arr);

    // 调用插入排序函数
    insertionSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}