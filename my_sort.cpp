//
// Created by Teng on 2023/10/3.
//

#include "my_sort.h"
#include "memory"
#include "string.h"

using namespace std;

void insertSort(int *nums, int size) {
    for (int i = 1; i < size; i++) {
        if (nums[i] < nums[i - 1]) {
            int val = nums[i];
            int pos = i - 1;
            for (; pos >= 0 && nums[pos] > val; pos--)
                nums[pos + 1] = nums[pos];
            // 在pos位置val将大于nums[pos]，所以插入到pos+1的位置上
            nums[pos + 1] = val;
        }
    }
}

void bubbleSort(int *nums, int size) {
    int is_exchange = false;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                is_exchange = true;
            }
        }
        if (!is_exchange) return;
    }
}

void swap(int *dst, int *src) {
    int tmp = *dst;
    *dst = *src;
    *src = tmp;
}

int partition(int *nums, int low, int high) {
    int mid = (high - low) / 2 + low;
    int pivotkey = nums[mid];
    swap(&nums[mid], &nums[low]);

    int pivot_pos = low;
    for (int i = low + 1; i <= high; i ++){
        if (nums[i] < pivotkey){
            swap(nums[pivot_pos + 1], nums[i]);
            pivot_pos ++;
        }
    }
    swap(&nums[pivot_pos], &nums[low]);

    return pivot_pos;
}

void mySort(int *nums, int low, int high) {
    if (low >= high) return;

    int mid = partition(nums, low, high);
    mySort(nums, low, mid - 1);
    mySort(nums, mid + 1, high);
}

void quickSort(int *nums, int size) {
    mySort(nums, 0, size - 1);
}

void __merge(int *nums, int left, int mid, int right) {
    int size = right - left + 1;
    auto aux = new int[size];
    for (int i = 0; i < size; i ++) {
        aux[i] = nums[left + i];
    }

    int l = left, r = mid + 1, curr = left;
    while (l <= mid && r <= right) {
        if (aux[l - left] < aux[r - left]) {
            nums[curr ++] = aux[l - left];
            l ++;
        } else {
            nums[curr ++] = aux[r - left];
            r ++;
        }
    }

    while (l <= mid) {
        nums[curr ++] = aux[l - left];
        l ++;
    }
    while (r <= right) {
        nums[curr ++] = aux[r - left];
        r ++;
    }

    delete[] aux;
}

void __mergeSort(int *nums, int left, int right) {
    if (left >= right) return ;

    int mid = (right - left) / 2 + left;
    __mergeSort(nums, left, mid);
    __mergeSort(nums, mid + 1, right);
    __merge(nums, left, mid, right);
}

void mergeSort(int *nums, int size) {
    __mergeSort(nums, 0, size - 1);
}