
/*
Q1(d). Implement Merge Sort
*/

#include <iostream>
using namespace std;

void mergeFn(int a[], int l, int mid, int r);
void mergeSort(int a[], int l, int r);

int main()
{
    int n;
    cin >> n;
    int arr[200];

    for(int i=0;i<n;i++) cin>>arr[i];

    mergeSort(arr , 0 , n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}

void mergeFn(int a[], int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[200], R[200];

    for(i=0;i<n1;i++) L[i] = a[l + i];
    for(j=0;j<n2;j++) R[j] = a[mid + 1 + j];

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while(i < n1) a[k++] = L[i++];
    while(j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r)
{
    if(l < r)
    {
        int mid = (l+r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        mergeFn(a, l, mid, r);
    }
}
