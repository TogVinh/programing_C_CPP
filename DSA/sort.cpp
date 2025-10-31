#include <iostream>
#include <chrono>
#include <random>
#include <cstring>

using namespace std;

void printSorted(int arr[], int size, string name)
{
    cout << "<- " << name << " sort --\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n------------------ END ->\n";
}

void printDebug(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << " -> END\n";
}

// Selection sort implementation using array
void selectionSort(int arr[], int size)
{
    int* cpy = new int[size];
    memcpy(cpy, arr, size * sizeof(int));
    
    for (int idx = 0; idx < size; idx++)
    {
        int min_pos = idx;
        for (int j = idx + 1; j < size; j++)
        {
            if (cpy[j] < cpy[min_pos])
            {
                min_pos = j;
            }
        }
        swap(cpy[min_pos], cpy[idx]);
    }
    
    delete[] cpy;
}

void bubbleSort(int arr[], int size)
{
    int* cpy = new int[size];
    memcpy(cpy, arr, size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (cpy[j] > cpy[j + 1])
            {
                swap(cpy[j], cpy[j + 1]);
            }
        }
    }
    
    delete[] cpy;
}

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    // Copy data to temp arrays
    for (int idx = 0; idx < n1; idx++)
        leftArr[idx] = arr[left + idx];
    for (int idx = 0; idx < n2; idx++)
        rightArr[idx] = arr[mid + 1 + idx];

    int i = 0, j = 0, k = left;
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

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
    
    delete[] leftArr;
    delete[] rightArr;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void callMergeSort(int arr[], int size)
{
    int* cpy = new int[size];
    memcpy(cpy, arr, size * sizeof(int));
    mergeSort(cpy, 0, size - 1);
    
    delete[] cpy;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low -1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // trả về chỉ số pivot
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void callQuickSort(int arr[], int size)
{
    int *cpy = new int[size];
    memcpy(cpy, arr, size*sizeof(int));

    quickSort(cpy, 0, size -1);

    delete[] cpy;
}

int main()
{
#ifndef INPUT
    freopen("input.log", "r", stdin);
    freopen("output.log", "w", stdout);
#endif

    int size;
    cout << "Reading size...\n";
    cin >> size;
    
    cout << "Size read: " << size << "\n";

    // Validate input size
    if (size <= 0)
    {
        cout << "Invalid array size" << endl;
        return 1;
    }

    // Seed random number generator
    srand(time(0));

    cout << "Creating array...\n";
    
    // Create and populate array
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 10000 + 1;

    cout << "Array created with " << size << " elements\n";

    // Bubble sort
    auto start_b = chrono::high_resolution_clock::now();
    cout << "Starting bubble sort...\n";
    bubbleSort(arr, size);
    cout << "Bubble sort completed\n";
    auto end_b = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration_b = end_b - start_b;
    cout << "Bubble sort took: " << duration_b.count() << " ms\n";

    // Merge Sort
    auto start_m = chrono::high_resolution_clock::now();
    cout << "Starting merge sort...\n";
    callMergeSort(arr, size);
    cout << "Merge sort completed\n";
    auto end_m = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration_m = end_m - start_m;
    cout << "Merge sort took: " << duration_m.count() << " ms\n";

    // Selection sort (commented out for large arrays due to O(n^2) complexity)
    // auto start_s = chrono::high_resolution_clock::now();
    // cout << "Starting selection sort...\n";
    // selectionSort(arr, size);
    // cout << "Selection sort completed\n";
    // auto end_s = chrono::high_resolution_clock::now();
    // chrono::duration<double, milli> duration_s = end_s - start_s;
    // cout << "Selection sort took: " << duration_s.count() << " ms\n";

    delete[] arr;
    return 0;
}
