#include<iostream>
#include<chrono>  
using namespace std;

const int max_size = 100;
int binary_search(int arr[], int x, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] < x){
        return binary_search(arr, x, mid+1, high);
    }
    else{
        return binary_search(arr, x, low, mid-1);
    }
}
int main(){
    int x;
    cout<<"Enter element to search: ";
    cin>>x;    
    int min, max;
    cout<<"Enter minimum number of elements: ";
    cin>>min;
    cout<<"Enter maximum number of elements: ";
    cin>>max;

    srand(time(0)); 
    for(int n = min; n <= max; n++){
        cout<<"\nArray size = "<<n<<endl;
        int arr[max_size];
        for(int i=0; i<n; i++){
            arr[i] = rand() % 100;
        }
        sort(arr, arr+n);

        cout<<"Sorted array: ";
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        auto start = chrono::high_resolution_clock::now();
        int result = binary_search(arr, x, 0, n-1);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        if(result != -1){
            cout<<"Element found at index "<<result<<endl;
        }
        else{
            cout<<"Element not found"<<endl;
        }
        cout<<"Time taken: "<<duration.count()<<" ns"<<endl;
    }
    return 0;
}
