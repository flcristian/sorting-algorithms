#include <iostream>

using namespace std;

class Sorter {
public:
	void mergeSort(int array[], int left, int right) {
		if (left < right) {
			int mid = (left + right) / 2;
			mergeSort(array, left, mid);
			mergeSort(array, mid + 1, right);
			merge(array, left, right, mid);
		}
	}
	void bubbleSort(int array[], int length) {
		bool flag = false;
		while (!flag) {
			flag = true;
			for (int i = 0; i < length - 1; i++) {
				if (array[i] > array[i + 1]) {
					swap(array[i], array[i + 1]);
					flag = false;
				}
			}
		}
	}
	void sentinelBubbleSort(int array[], int length) {
		bool flag = true;
		int i = 0;
		while (flag && i < length) {
			flag = false;
			for (int j = length - 1; j > i; j--) {
				if (array[j] < array[j - 1]) {
					swap(array[j], array[j - 1]);
					flag = true;
				}
			}
			i++;
		}
	}
	void selectionSort(int array[], int length) {
		for (int i = 0; i < length - 1; i++) {
			for (int j = i + 1; j < length; j++) {
				if (array[i] > array[j]) {
					swap(array[i], array[j]);
				}
			}
		}
	}
	void quickSort(int array[], int left, int right) {
		if (left < right) {
			int k = partition(array, left, right);
			quickSort(array, left, k - 1);
			quickSort(array, k + 1, right);
		}
	}
private:
	void swap(int& x, int& y) {
		int aux = x;
		x = y;
		y = aux;
	}
	void merge(int array[], int left, int right, int mid) {
		int i = left, j = mid + 1, k = 0, temp[1000];

		while (i <= mid && j <= right) {
			if (array[i] < array[j]) {
				temp[k] = array[i];
				i++;
				k++;
			}
			else {
				temp[k] = array[j];
				j++;
				k++;
			}
		}

		while (i <= mid) {
			temp[k] = array[i];
			i++;
			k++;
		}

		while (j <= right) {
			temp[k] = array[j];
			j++;
			k++;
		}

		for (int i = left; i <= right; i++) {
			array[i] = temp[i - left];
		}
	}
	int partition(int array[], int left, int right) {
		int pivot = array[right];
		int k = left;
		for (int i = left; i < right; ++i) {
			if (array[i] < pivot) {
				swap(array[i], array[k]);
				++k;
			}
		}
		swap(array[k], array[right]);
		return k;
	}
};