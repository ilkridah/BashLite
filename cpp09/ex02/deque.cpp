#include "PmergeMe.hpp"

void insertionSort_deque(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void mergeSort_deque(std::deque<int>& arr, int left, int right) 
{
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    if (right - left <= 10) {
        insertionSort_deque(arr, left, right);
    } else 
    {
        mergeSort_deque(arr, left, mid);
        mergeSort_deque(arr, mid + 1, right);

        std::vector<int> temp(right - left + 1);

        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (int i = 0; i < k; i++) {
            arr[left + i] = temp[i];
        }
    }
}