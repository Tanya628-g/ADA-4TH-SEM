#include<iostream>
#include<chrono>
using namespace std;

const int MAX = 100;
void MaxMin(int a[], int i, int j, int max, int min){
    int mid, max1, min1;

    if(i == j){
        max = min = a[i];
    }
    else if(i == j - 1){
        if(a[i] < a[j]){
            max = a[j];
            min = a[i];
        }
        else{
            max = a[i];
            min = a[j];
        }
    }
    else{
        mid = (i + j) / 2;
        MaxMin(a, i, mid, max, min);
        MaxMin(a, mid + 1, j, max1, min1);

        if(max < max1){
            max = max1;
        }
        if(min > min1){
            min = min1;
        }
    }
}
int main(){
    int n;
    int a[MAX];
    int max, min;

    cout<<"Enter number of elements: ";
    cin>>n;
    srand(time(0));
    cout<<"Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    auto start = std::chrono::high_resolution_clock::now();
    MaxMin(a, 0, n-1, max, min);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    

    cout<<"\nMaximum element = "<<max<<endl;
    cout<<"Minimum element = "<<min<<endl;

    return 0;
}
