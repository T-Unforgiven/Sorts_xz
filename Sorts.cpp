#include <iostream>
#include "Sorts.h"

int GetMax(int* ar, int size){
    int max = 0;
    for(int i = 1; i < size; i++){
        if(ar[i] > ar[max])
            max = i;
    }
    return max;
}

void SelectionSort(int* ar, int size){
    while(size > 0) {
        int index = GetMax(ar, size);
        std::swap(ar[size - 1], ar[index]);
        size--;
    }
}

void BubbleSort(int* ar, int size){
    bool sorted = false;
    for(int k = size - 1; k > 0 && !sorted; k--){
        sorted = true;
        for(int i = 0; i < k; i++)
            if(ar[i] > ar[i+1]){
                std::swap(ar[i], ar[i+1]);
                sorted = false;
            }
    }
}

void QuickSort(int* ar, int low, int high){
    int i = low;
    int j = high;
    int pivot = ar[(i + j) / 2];
    while (i <= j)
    {
        while (ar[i] < pivot)
            i++;
        while (ar[j] > pivot)
            j--;
        if (i <= j)
        {
            std::swap(ar[i], ar[j]);
            i++;
            j--;
        }
    }
    if (j > low)
        QuickSort(ar, low, j);
    if (i < high)
        QuickSort(ar, i, high);
}

void QuickSort_1(int* ar, int size){
    QuickSort(ar, 0, size -1);
}

void InsertionSort(int* ar, int size){
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0 && ar[j-1] > ar[j]; j--){
                std::swap(ar[j], ar[j-1]);
        }
    }
}

void countSort(int* ar, int n) {

    int* arr1 = new int[n];
    int x = ar[0];

    for (int i = 1; i < n; i++) {
        if (ar[i] > x)
            x = ar[i];
    }

    int* count_arr = new int[x+1];

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[ar[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[ar[i]] - 1] = ar[i];
        count_arr[ar[i]]--;
    }

    for (int i = 0; i < n; i++) {
        ar[i] = arr1[i];
    }
    delete[] arr1;
    delete[] count_arr;
}

void merge(int* array, int const left, int const mid,
           int const right)
{
    int const sizeOne = mid - left + 1;
    int const sizeTwo = right - mid;
    int *leftArray = new int[sizeOne], *rightArray = new int[sizeTwo];
    for (int i = 0; i < sizeOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0,
    indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < sizeOne
           && indexOfSubArrayTwo < sizeTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < sizeOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < sizeTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int* array, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void mergeSort_1(int* ar, int size){
    mergeSort(ar, 0, size - 1);
}

