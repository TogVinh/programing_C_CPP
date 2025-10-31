#include <iostream>
#include <chrono>
#include <random>
#include <cstring>
#include <iomanip>
using namespace std;

#define EMPTY_STACK -1

// int myArray[] = {2, 6, 4, 1, 11, 7, 5};
int myArray[] = {3, 9, 8, 7, 6, 5, 4};

int arrSize = sizeof(myArray) / sizeof(myArray[0]);
int stepCount = 0; // Đếm số bước thực hiện

void printArray(int arr[], int size)
{
    cout << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << arr[i];
        if (i < size - 1) cout << " , ";
    }
    cout << " ]\n";
}

void printStack(int stack[], int size)
{
    cout << "   Stack "  << "[ ";
    for (int i = 0; i < size; i++)
    {
        cout << stack[i] << " , ";
    }
    cout << " ]\n";
}

int partition(int arr[], int low, int high)
{
    cout <<"\n ┌─ PARTITION ────────────────\n";
    int pivot = arr[high];
    int new_pivot = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            new_pivot++;
            cout<<" | Sort Array : ";
            swap(arr[new_pivot], arr[j]);
            printArray(arr, arrSize);
        }
    }

    new_pivot++;
    swap(arr[new_pivot], arr[high]);
    cout<<"\n |\n | ===> Last Array : ";
    printArray(arr, arrSize);
    cout<<" |__________________________\n ";
    return new_pivot;
}

void quickSortIterative(int arr[], int lastIndex)
{
    cout << "<-- Start quick sort -->\n";
    int stackSize = lastIndex ;
    int stack[stackSize];
    memset(stack, -1, sizeof(stack));
    
    int idxStack = EMPTY_STACK; // push to stack, init with empty stack
    int low = 0;
    int high = lastIndex;

    cout <<"numindex : "<< lastIndex << endl;
    cout <<"stackSize : "<< stackSize << endl;
    cout <<"stack init : ";
    printStack(stack, stackSize);

    idxStack++;
    stack[idxStack] = low;
    idxStack++;
    stack[idxStack] = high;

    cout << "new stack before loop \n";
    printStack(stack, stackSize);

    while (idxStack >=0 )
    {
        stepCount++;
        cout << "\n" << string(60, '=') << "\n";
        cout << "🔄 ITERATION #" << stepCount << "\n";
        cout << string(60, '=') << "\n";

        // get high and low from stack
        /** low is push to stack before high
         * => Must be pop high from stack before get pop low
         */

        high = stack[idxStack];
        stack[idxStack] = -1;
        idxStack--; // pop high from stack
        
        low = stack[idxStack];
        stack[idxStack] = -1;
        idxStack--; // pop low from stack

        cout << "low : "<< low<< endl;
        cout << "high : "<< high<< endl;
        cout << "Stack Pop : ";
        printStack(stack, stackSize);

        int pivot = partition(arr, low, high);
        cout << "pivot : " <<pivot<<endl;

        // check the left of pivot
        if (pivot - 1 > low)
        {
            //code
            cout << "Push Left\n";
            idxStack++;
            stack[idxStack] = low;
            idxStack++;
            stack[idxStack] = pivot - 1;
        }

        // check in the right
        if (pivot + 1 < high)
        {
            //code
            cout << "Push Right\n";
            idxStack++;
            stack[idxStack] = pivot + 1;
            idxStack++;
            stack[idxStack] = high;
        }
        cout << "Push Stack : ";
        printStack(stack, stackSize);
    }
    
}



int main()
{
#ifndef INPUT
    freopen("output.log", "w", stdout);
#endif
    
    cout << "\n📋 Initial array: ";
    printArray(myArray, arrSize);
    cout << "   Size: " << arrSize << " elements\n";

    quickSortIterative(myArray, arrSize - 1);

    cout << "\n🎉 Final sorted array: ";
    printArray(myArray, arrSize);
    cout << "\n";

    return 0;
}