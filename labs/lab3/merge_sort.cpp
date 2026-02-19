#include<iostream>
using namespace std;
#include<chrono>

void merge(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = low;
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
    if(i == mid + 1){
        for(int x = mid + 1; x <= high; x++){
            b[k] = arr[x];
            k++;
        }        
    } 
    else{
        for(int x = i; x <= mid; x++){
            b[k] = arr[x];
            k++;
        }
    }
    for(int x = low; x <= high; x++){
        arr[x] = b[x - low];
    }
}
void merge_sort(int arr[], int a1, int an){
    if(a1 < an){
        int mid = (a1 + an) / 2;
        merge_sort(arr, a1, mid);
        merge_sort(arr, mid + 1, an);
        merge(arr, a1, mid, an);

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

    for (int n = min; n <= max; n++) {
        cout<<endl<<"unsorted array = ";
        int arr[n];

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
            cout<< arr[i] <<" ";
        }
        cout<<endl<<"sorted arrray = ";
        auto start = std::chrono::high_resolution_clock::now();
        merge_sort(arr, 0, mid, n-1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout<<endl<<"Time Taken = "<<duration.count()<<endl;
    }    
    return 0;
}