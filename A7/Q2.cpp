/*
Q2. Improved Selection Sort
Find min and max on each pass and arrange from both ends.
*/

#include <iostream>
using namespace std;

void improvedSel(int a[], int n)
{
    int left = 0, right = n-1;

    while(left < right)
    {
        int mn = left;
        int mx = right;

        if(a[mn] > a[mx])
        {
            int t = a[mn];
            a[mn] = a[mx];
            a[mx] = t;
        }

        for(int i = left; i <= right; i++)
        {
            if(a[i] < a[mn]) mn = i;
            if(a[i] > a[mx]) mx = i;
        }

        // swap min
        int t1 = a[left];
        a[left] = a[mn];
        a[mn] = t1;

        if(mx == left) mx = mn;

        // swap max
        int t2 = a[right];
        a[right] = a[mx];
        a[mx] = t2;

        left++;
        right--;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[500];
    for(int i=0;i<n;i++) cin >> arr[i];

    improvedSel(arr , n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
