#include<iostream>
using namespace std;
#include<chrono>


void merge_sort(int arr[], int low, int mid, int high){
    low=arr[0];
    // high=arr[n-1];
    mid= (high+low)/2;
    for(int i = low; i<=mid; i++){
        // if()
    }
    for(int j= mid +1; j<=high ; j++){

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