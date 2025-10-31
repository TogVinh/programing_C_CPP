#include <iostream>
#include <chrono>
#include <random>
#include <cstring>
#include <iomanip>
using namespace std;

int arr[] = {2, 6, 4, 1, 11, 7, 5};  // Đổi từ 'array' thành 'arr'
int n = sizeof(arr) / sizeof(arr[0]);
int stepCount = 0; // Đếm số bước thực hiện

void printArray(int arr[], int size);
void printStack(int stack[], int top, int size);

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    cout << "\n  ┌─ PARTITION [" << low << " -> " << high << "] ─┐\n";
    cout << "  │ Pivot = arr[" << high << "] = " << arr[high] << endl;
    cout << "  │ Array before partition: ";
    printArray(arr, n);
    
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        cout << "  │   Comparing arr[" << j << "]=" << arr[j] << " with pivot=" << pivot;
        if (arr[j] <= pivot)
        {
            i++;
            cout << " → SWAP arr[" << i << "] ↔ arr[" << j << "]\n";
            swapInt(&arr[i], &arr[j]);
            cout << "  │   Result: ";
            printArray(arr, n);
        }
        else
        {
            cout << " → Skip\n";
        }
    }
    
    i++;
    cout << "  │ Final SWAP: arr[" << i << "] ↔ arr[" << high << "] (pivot position)\n";
    swapInt(&arr[i], &arr[high]);
    cout << "  │ Array after partition: ";
    printArray(arr, n);
    cout << "  └─ Pivot now at index: " << i << " ─┘\n";
    
    return i;
}

void quickSortIterative(int arr[], int l, int h)
{
    int stackSize = h - l + 1;
    int stack[stackSize * 2]; // Tăng kích thước stack để đảm bảo đủ
    memset(stack, -1, sizeof(stack)); // Khởi tạo stack = -1
    int top = -1;

    // Đẩy khoảng đầu tiên vào stack
    stack[++top] = l;
    stack[++top] = h;

    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║          ITERATIVE QUICKSORT - DEBUG MODE              ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
    cout << "\n📌 Initial state:\n";
    cout << "   Range: [" << l << " -> " << h << "]\n";
    cout << "   Stack top: " << top << "\n";
    printStack(stack, top, stackSize * 2);

    while (top >= 0)
    {
        stepCount++;
        cout << "\n" << string(60, '=') << "\n";
        cout << "🔄 ITERATION #" << stepCount << "\n";
        cout << string(60, '=') << "\n";
        
        // Lấy high và low từ stack
        h = stack[top];
        stack[top] = -1; top--;
        l = stack[top];
        stack[top] = -1; top--;

        cout << "l=" << l << ", h=" << h << " | Stack top now: " << top << "\n";
        printStack(stack, top, stackSize * 2);
        
        cout << "\n🎯 Current array state: ";
        printArray(arr, n);

        // Thực hiện partition
        int p = partition(arr, l, h);
        
        cout << "\n📍 Pivot settled at index: " << p << " (value=" << arr[p] << ")\n";
        printArray(arr, n);

        // Xử lý phần bên trái
        if (p - 1 > l)
        {
            cout << "\n  ⬅️  LEFT subarray exists [" << l << " -> " << (p-1) << "]\n";
            stack[++top] = l;
            stack[++top] = p - 1;
            cout << "  📥 PUSH to stack: l=" << l << ", h=" << (p-1) << " | Stack top: " << top << "\n";
        }
        else
        {
            cout << "\n  ⬅️  LEFT subarray: NONE (already sorted or single element)\n";
        }

        // Xử lý phần bên phải
        if (p + 1 < h)
        {
            cout << "\n  ➡️  RIGHT subarray exists [" << (p+1) << " -> " << h << "]\n";
            stack[++top] = p + 1;
            stack[++top] = h;
            cout << "  📥 PUSH to stack: l=" << (p+1) << ", h=" << h << " | Stack top: " << top << "\n";
        }
        else
        {
            cout << "\n  ➡️  RIGHT subarray: NONE (already sorted or single element)\n";
        }

        cout << "\n📊 Current stack state:\n";
        printStack(stack, top, stackSize * 2);
        
        cout << "\n🔢 Array progress: ";
        printArray(arr, n);
    }
    
    cout << "\n" << string(60, '=') << "\n";
    cout << "✅ SORTING COMPLETE after " << stepCount << " iterations!\n";
    cout << string(60, '=') << "\n";
}

void printArray(int arr[], int size)
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << arr[i];
        if (i < size - 1) cout << ",";
    }
    cout << " ]\n";
}

void printStack(int stack[], int top, int size)
{
    cout << "   Stack (top=" << top << "): [";
    for (int i = 0; i < size; i++)
    {
        cout << stack[i] << " ";
    }
    cout << " ]\n";
    
    if (top < 0)
    {
        cout << "   ⚠️  Stack is EMPTY\n";
    }
}

int main()
{
#ifndef INPUT
    freopen("output.log", "w", stdout);
#endif

    cout << "\n╔════════════════════════════════════════════════════════╗\n";
    cout << "║              QUICKSORT DEBUGGER                      ║\n";
    cout << "╚════════════════════════════════════════════════════════╝\n";
    
    cout << "\n📋 Initial array: ";
    printArray(arr, n);
    cout << "   Size: " << n << " elements\n";

    quickSortIterative(arr, 0, n - 1);

    cout << "\n🎉 Final sorted array: ";
    printArray(arr, n);
    cout << "\n";

    return 0;
}