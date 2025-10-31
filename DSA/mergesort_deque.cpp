// C program for the implementation of merge sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// The subarray to be sorted is in the index range [left-right]
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Calculate the midpoint
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 13, 11, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting arr using mergesort
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

/*

mergeSort(arr, 0, 5)                          [call 1]
│
├─ mid = 0 + (5-0)/2 = 2
│
├─ mergeSort(arr, 0, 2)                       [call 2]
│  │
│  ├─ mid = 0 + (2-0)/2 = 1
│  │
│  ├─ mergeSort(arr, 0, 1)                    [call 3]
│  │  │
│  │  ├─ mid = 0 + (1-0)/2 = 0
│  │  │
│  │  ├─ mergeSort(arr, 0, 0)                 [call 4]
│  │  │  left == right → return (không làm gì)
│  │  │
│  │  ├─ mergeSort(arr, 1, 1)                 [call 5]
│  │  │  left == right → return (không làm gì)
│  │  │
│  │  └─ merge(arr, 0, 0, 1)                  [MERGE 1]
│  │     Gộp [12] và [13] → [12, 13]
│  │     Mảy hiện tại: [12, 13, 11, 5, 6, 7]
│  │
│  ├─ mergeSort(arr, 2, 2)                    [call 6]
│  │  left == right → return (không làm gì)
│  │
│  └─ merge(arr, 0, 1, 2)                     [MERGE 2]
│     Gộp [12, 13] và [11] → [11, 12, 13]
│     Mảy hiện tại: [11, 12, 13, 5, 6, 7]
│
├─ mergeSort(arr, 3, 5)                       [call 7]
│  │
│  ├─ mid = 3 + (5-3)/2 = 4
│  │
│  ├─ mergeSort(arr, 3, 4)                    [call 8]
│  │  │
│  │  ├─ mid = 3 + (4-3)/2 = 3
│  │  │
│  │  ├─ mergeSort(arr, 3, 3)                 [call 9]
│  │  │  left == right → return (không làm gì)
│  │  │
│  │  ├─ mergeSort(arr, 4, 4)                 [call 10]
│  │  │  left == right → return (không làm gì)
│  │  │
│  │  └─ merge(arr, 3, 3, 4)                  [MERGE 3]
│  │     Gộp [5] và [6] → [5, 6]
│  │     Mảy hiện tại: [11, 12, 13, 5, 6, 7]
│  │
│  ├─ mergeSort(arr, 5, 5)                    [call 11]
│  │  left == right → return (không làm gì)
│  │
│  └─ merge(arr, 3, 4, 5)                     [MERGE 4]
│     Gộp [5, 6] và [7] → [5, 6, 7]
│     Mảy hiện tại: [11, 12, 13, 5, 6, 7]
│
└─ merge(arr, 0, 2, 5)                        [MERGE 5]
   Gộp [11, 12, 13] và [5, 6, 7] → [5, 6, 7, 11, 12, 13]
   Mảy cuối cùng: [5, 6, 7, 11, 12, 13] ✓
*/