#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool binary_search(int arr[], int size, int val)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid = (left + right)/2;
        if (arr[mid] == val)
        {
            cout<<"find "<< val <<" in the arr["<< mid <<"]";
            return true;
        }
        else if (arr[mid] < val)
            left = mid + 1;
        else if (arr[mid] > val)
            right = mid - 1;
    }
    return false;
}

int main()
{
#ifndef INPUT
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr_size;
    cin>>arr_size;

    int arr[arr_size];
    for (int i = 0; i < arr_size; i++)
        arr[i] = rand() % 10 + 1;

    // cout arr
    cout << "Arry : \n";
    for (int idx : arr)
    {
        cout << idx <<" ";
    }
    cout<<"\n================\n";

    sort(arr, arr+arr_size); // sort arr

    int val;
    cin>>val;
    cout << "Find value " << val << endl;

    binary_search(arr, arr_size, val);
    

    return 0;
}