#include<iostream>
#include<chrono>
using namespace std;

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;

    // temporary array size = high-low+1
    int b[high - low + 1];

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    // copy remaining left part
    while(i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    // copy remaining right part
    while(j <= high)
    {
        b[k] = arr[j];
        j++;
        k++;
    }

    // copy back to original array
    for(int x = 0; x < k; x++)
    {
        arr[low + x] = b[x];
    }
}

void merge_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main(){
    int min, max;

    cout<<"Enter minimum number of elements: ";
    cin>>min;

    cout<<"Enter maximum number of elements: ";
    cin>>max;

    srand(time(0));
    
    for(int n = min; n <= max; n++)
    {
        cout<<"\nUnsorted array = ";

        int arr[n];

        for(int i = 0; i < n; i++)
        {
            arr[i] = rand() % 100;
            cout<<arr[i]<<" ";
        }

        auto start = chrono::high_resolution_clock::now();

        merge_sort(arr, 0, n-1);

        auto end = chrono::high_resolution_clock::now();

        cout<<"\nSorted array = ";
        for(int i = 0; i < n; i++)
        {
            cout<<arr[i]<<" ";
        }

        auto duration =
        chrono::duration_cast<chrono::microseconds>(end - start);

        cout<<"\nTime Taken = "<<duration.count()<<" microseconds\n";
    }

    return 0;
}
