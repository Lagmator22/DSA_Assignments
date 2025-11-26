/*
Q6. Priority Queue using Max-Heap
*/

#include <iostream>
using namespace std;

int heapArr[500];
int heapSize = 0;

void swapInt(int &x, int &y)
{
    int t = x; x = y; y = t;
}

void siftUp(int i)
{
    while(i > 0)
    {
        int p = (i - 1) / 2;
        if(heapArr[p] < heapArr[i])
        {
            swapInt(heapArr[p], heapArr[i]);
            i = p;
        }
        else break;
    }
}

void heapifyDown(int i)
{
    while(true)
    {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if(l < heapSize && heapArr[l] > heapArr[largest]) largest = l;
        if(r < heapSize && heapArr[r] > heapArr[largest]) largest = r;

        if(largest != i)
        {
            swapInt(heapArr[i], heapArr[largest]);
            i = largest;
        }
        else break;
    }
}

void pqInsert(int x)
{
    heapArr[heapSize] = x;
    heapSize++;
    siftUp(heapSize - 1);
}

int pqGetMax()
{
    if(heapSize == 0) return -1; // or any sentinel
    return heapArr[0];
}

int pqExtractMax()
{
    if(heapSize == 0) return -1;

    int maxVal = heapArr[0];
    heapArr[0] = heapArr[heapSize - 1];
    heapSize--;
    heapifyDown(0);
    return maxVal;
}

void pqDisplay()
{
    for(int i = 0; i < heapSize; i++)
        cout << heapArr[i] << " ";
    cout << "\n";
}

int main()
{
    int choice;
    do
    {
        cin >> choice;
        if(choice == 1)
        {
            int x;
            cin >> x;
            pqInsert(x);
        }
        else if(choice == 2)
        {
            cout << "Max: " << pqGetMax() << "\n";
        }
        else if(choice == 3)
        {
            int v = pqExtractMax();
            cout << "Extracted: " << v << "\n";
        }
        else if(choice == 4)
        {
            pqDisplay();
        }
        // 0 to exit
    } while(choice != 0);
}
