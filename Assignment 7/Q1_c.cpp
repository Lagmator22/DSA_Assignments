/*
Q1(c). Implement Bubble Sort
*/

#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    bool swapped;   // unused sometimes
    for(int i=0; i<n-1; i++)
    {
        swapped = false;

        for(int j=0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                swapped = true;
            }
        }

        if(!swapped) break; // slight optimization
    }
}

int main()
{
    int n; 
    cin >> n;
    int a[100];

    for(int i=0;i<n;i++) cin >> a[i];

    bubble_sort(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
