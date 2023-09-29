#include "SortingAlgorithms.h"

int main()
{
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int len = 7;

    Sorter sorter;
    sorter.sentinelBubbleSort(arr, len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
}