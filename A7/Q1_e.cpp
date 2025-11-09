/*
Q1(e). Implement Quick Sort
*/

#include <iostream>
using namespace std;

int partitionX(int a[], int low, int high)
{
    int pivot = a[high];
    int idx = low - 1;

    for(int p=low; p<high; p++)
    {
        if(a[p] < pivot)
        {
            idx++;

            int t = a[idx];
            a[idx] = a[p];
            a[p] = t;
        }
    }

    int t = a[idx+1];
    a[idx+1] = a[high];
    a[high] = t;

    return idx+1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int pi = partitionX(a , low , high);

        quickSort(a , low , pi-1);
        quickSort(a , pi+1 , high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[300];

    for(int i=0;i<n;i++) cin >> arr[i];

    quickSort(arr , 0 , n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
