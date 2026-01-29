#include<bits/stdc++.h>
using namespace std;

int depth = 0;

void printArray(int a[], int n, int start = -1, int end = -1)
{
    for(int i = 0; i < n; i++)
    {
        if(i == start) cout << "[ ";
        cout << a[i] << " ";
        if(i == end) cout << "] ";
    }
    cout << endl;
}

int partition_array(int a[], int start, int en, int n)
{
    int pivot = a[en];
    int partitionIndex = start;

    cout << string(depth*4, ' ')
         << "Pivot = " << pivot << " (index " << en << ")\n";

    for(int i = start; i < en; i++)
    {
        cout << string(depth*4, ' ')
             << "Compare a[" << i << "]=" << a[i]
             << " with pivot " << pivot << endl;

        if(a[i] <= pivot)
        {
            cout << string(depth*4, ' ')
                 << "Swap a[" << i << "] and a[" << partitionIndex << "]\n";
            swap(a[i], a[partitionIndex]);
            partitionIndex++;
            printArray(a, n, start, en);
        }
    }

    cout << string(depth*4, ' ')
         << "Place pivot at index " << partitionIndex << endl;
    swap(a[partitionIndex], a[en]);

    printArray(a, n, start, en);
    cout << endl;

    return partitionIndex;
}

void quicksort(int a[], int start, int en, int n)
{
    if(start < en)
    {
        cout << string(depth*4, ' ')
             << "QuickSort called on range [" << start << ", " << en << "]\n";

        depth++;
        int partitionIndex = partition_array(a, start, en, n);
        depth--;

        cout << string(depth*4, ' ')
             << "Left Subarray\n";
        depth++;
        quicksort(a, start, partitionIndex - 1, n);
        depth--;

        cout << string(depth*4, ' ')
             << "Right Subarray\n";
        depth++;
        quicksort(a, partitionIndex + 1, en, n);
        depth--;
    }
}

int main()
{
    int a[] = {5,6,4,1,3,2,60,7};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Initial Array:\n";
    printArray(a, n);
    cout << "\n--- START QUICK SORT ---\n\n";

    quicksort(a, 0, n - 1, n);

    cout << "\n--- FINAL SORTED ARRAY ---\n";
    printArray(a, n);
}

