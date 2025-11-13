/*
Q1(b). Implement Insertion Sort
*/

#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    int i, j, key;

    for(i = 1 ; i < n ; i++)
    {
        key = a[i];         
        j = i - 1;

        // shift
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
        //cout<<"step"<<i<<"\n"; // debug
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[150];
    for(int x=0;x<n;x++) cin >> arr[x];

    insertion_sort(arr , n);

    for(int x = 0; x < n; x++)
        cout << arr[x] << " ";
}
