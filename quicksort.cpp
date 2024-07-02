#include<iostream>
#include<algorithm>

using namespace std;


int partation(int A[], int low, int high) {
	int pivot = A[low];
	while (low < high) {
		while (low < high && A[high] >= pivot) {
			high--;
		}
		A[low] = A[high];
		while (low < high && A[low] <= pivot) {
			low++;
		}
		A[high] = A[low];
	}
	A[low] = pivot;
	return low;
}

void QuickSort(int A[], int low, int high) {
	if (low < high) {
		int pivotpos = partation(A, low, high);
		QuickSort(A, low, high - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}




//int partation(int A[], int low, int high) {
//	int pivot = A[low];
//	while (low < high) {
//		while (low < high && A[high] >= pivot) {
//			high--;
//		}
//		A[low] = A[high];
//		while (low < high && A[low] <= pivot) {
//			low++;
//		}
//		A[high] = A[low];
//	}
//	A[low] = pivot;
//	return low;
//}
//
//void QuickSort(int A[], int low, int high) {
//	if (low < high) {
//		int pivotpos = partation(A, low, high);
//		QuickSort(A, low, pivotpos - 1);
//		QuickSort(A, pivotpos + 1, high);
//	}
//}





int main() {
	int A[10] = {5,3,4,6,7,2,5,8,3,30};
	QuickSort(A, 0, 9);
	for (const auto &it : A) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}