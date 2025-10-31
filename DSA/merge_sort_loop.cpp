#include <iostream>
using namespace std;

// Hàm tìm min của 2 số
int min(int a, int b)
{
    return (a < b) ? a : b;
}

void printSubArr(int arr[], int left, int right)
{
    cout << "   Sub Arr : [ ";
    for (int i = left; i <= right; i++)
        cout << arr[i] << " ";
    cout << " ] \n";
}

void printArray(int arr[], int n)
{
    cout << " [ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << " ] \n";
}

void merge(int arr[], int left, int mid, int right, int temp[])
{
    int i = left;    // Index của mảng con trái
    int j = mid + 1; // Index của mảng con phải
    int k = left;    // Index của mảng tạm

    cout << "   start merge sub array ===> ENTER\n";

    // Merge 2 mảng con vào mảng tạm
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy các phần tử còn lại của mảng con trái
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy các phần tử còn lại của mảng con phải
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy từ mảng tạm về mảng gốc
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    // printSubArr(temp, left, right);
}

void mergeSort(int arr[], int n)
{
    // allocate for temp array
    int *temp = new int[n];

    cout << "Test |" << __func__ << "|\n";

    cout << "Start merge Sort ===> ENTER\n";

    // Bắt đầu với kích thước mảng con = 1
    // Tăng dần lên 2, 4, 8, 16, ...
    for (int currSize = 1; currSize < n; currSize *= 2)
    {
        // Chọn điểm bắt đầu của mảng con trái
        cout << "\nCurrSize : " << currSize << endl;
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize)
        {
            // Tìm điểm giữa và điểm kết thúc
            int mid = leftStart + currSize - 1;
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            cout << "\n   Left Start : " << leftStart << endl;
            cout << "   mid        : " << mid << endl;
            cout << "   rightEnd   : " << rightEnd << endl;
            // printSubArr(arr, leftStart, rightEnd);

            // Merge 2 mảng con arr[leftStart...mid] và arr[mid+1...rightEnd]
            if (mid < rightEnd)
            {
                merge(arr, leftStart, mid, rightEnd, temp);
            }
        }
    }

    // Giải phóng bộ nhớ
    delete[] temp;
    cout << "Done merge Sort ===> END\n";
}

int main()
{
#ifndef INPUT
    freopen("output.log", "w", stdout);
#endif

    // int arr[] = {38, 27, 43, 3, 9, 82, 10, 67, 15, 94, 22, 51, 8, 76, 33, 19, 88, 45, 12, 61};
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sizeArr = sizeof(arr) / sizeof(arr[0]);

    cout << "Test |" << __func__ << "|\n";

    cout << "Init Array : ";
    printArray(arr, sizeArr);

    mergeSort(arr, sizeArr);

    cout << "Sorted Array : ";
    printArray(arr, sizeArr);

    return 0;
}
