#include<iostream>
#include<cmath>
using namespace std;
const int max_size = 100;

int binary_search(int arr[], int x, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low) / 2;
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
void initialise_arr(int arr[], int &n){
    cout<<"enter number of digits"<<" ";
    cin>>n;
    cout<<"enter digits"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void display_arr(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int arr[max_size];
    initialise_arr(arr, n);
    display_arr(arr, n);
    int x;
    cout<<"enter element to search: ";
    cin>>x;
    int result = binary_search(arr, x, 0, n-1);
    if(result != -1){
        cout<<"element found at index "<<result<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}