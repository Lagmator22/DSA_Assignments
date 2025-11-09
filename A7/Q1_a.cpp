/*
UCS301 – Data Structures Lab
Assignment 7 : Sorting

Q1(a). Implement Selection Sort
*/

#include <iostream>
using namespace std;

void selSort(int arr[], int n) 
{
    int i,j; 
    int pos; 
    int temp ;

    for(i = 0 ; i < n-1 ; i++)
    {
        pos = i;      

        for(j = i+1 ; j < n ; j++)
        {
            if(arr[j] < arr[pos])  
                pos = j;
        }

        // manual swap
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main()
{
    int n; cin >> n;
    int a[200];

    for(int k=0;k<n;k++) cin >> a[k];

    selSort(a , n);

    for(int k=0;k<n;k++) 
        cout<<a[k]<<" ";
}
