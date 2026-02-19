#include<iostream>
using namespace std;
#include<chrono>

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int b[high - low + 1];
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            b[k] = arr[i];
            i++;
        }
        else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }  
    while(i <= mid){
        b[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        b[k] = arr[j];
        j++;
        k++;
    }
    for(int x = 0; x < k; x++){
        arr[low + x] = b[x];
    }
}
void merge_sort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main(){
    int min,max;
    cout<< "enter minimum numbers of elemnets to be sorted ";
    cin>>min;
    cout<<"enter maximum numbes of elements to be sorted ";
    cin>>max;
    int mid, low, high;
    srand(time(0));

    for (int n = min; n <= max; n++){
        cout<<endl<<"unsorted array = ";
        int arr[n];

        for (int i = 0; i < n; i++){
            arr[i] = rand() % 100;
            cout<< arr[i] <<" ";
        }
        auto start = std::chrono::high_resolution_clock::now();
        merge_sort(arr, 0, n-1);
        auto end = std::chrono::high_resolution_clock::now();
        
        cout<<endl<<"sorted arrray = ";
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        cout<<endl<<"Time Taken = "<<duration.count()<<" us"<<endl;
    }    
    return 0;
}