#include<iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high){
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
void merge_sort(int *array, int a1, int an){
    if(a1 < an){
        int mid = (a1 + an) / 2;
        merge_sort(array, a1, mid);
        merge_sort(array, mid + 1, an);
        merge(array, a1, mid, an);
    }
}
int main(){

}