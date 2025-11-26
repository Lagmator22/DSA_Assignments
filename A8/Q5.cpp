/*5. Implement Heapsort (Increasing/Decreasing order).*/

#include <iostream>
using namespace std;

void heapifyMax(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;

    if(largest != i)
    {
        int t = a[i]; a[i] = a[largest]; a[largest] = t;
        heapifyMax(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMax(a, n, i);
}

void heapSortIncreasing(int a[], int n)
{
    buildMaxHeap(a, n);

    for(int i = n - 1; i >= 1; i--)
    {
        int t = a[0]; a[0] = a[i]; a[i] = t;
        heapifyMax(a, i, 0);
    }
}

void heapSortDecreasing(int a[], int n)
{
    // sort in increasing, then reverse
    heapSortIncreasing(a, n);

    for(int i = 0; i < n/2; i++)
    {
        int t = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = t;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[500];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int choice;
    cin >> choice; // 1 = increasing, 2 = decreasing

    if(choice == 1)
        heapSortIncreasing(arr, n);
    else
        heapSortDecreasing(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
