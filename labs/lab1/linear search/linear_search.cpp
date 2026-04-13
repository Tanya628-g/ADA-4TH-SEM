#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

int ls(int arr[], int n, int ele){
    for(int i=0; i<n; i++){
        if(arr[i]==ele){
            return i;
        }
    }
    return -1;
}
int main(){
    int min, max;
    cout<<"Enter minimum number of elemnets in array ";
    cin>>min;

    cout<<"Enter Maximum number of elements in array ";
    cin>>max;
    cout<<endl;
    srand(time(0));

    ofstream fout("Linear_Search.txt");
    fout<<"n \t time(ns)\n";

    for(int n=min; n<=max; n++){
        cout<<"Array of Elements: ";
        int arr[n];
        
        for(int i=0; i<n ; i++){
            arr[i] = rand() % 100;
            cout<<arr[i]<<" ";
        }
        int ele= rand() % 100;
        cout<<"Element to be searched: "<<ele<<endl;

        auto start = chrono::high_resolution_clock::now();
        int index= ls(arr,n, ele);
        auto end= chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duration= std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

        if(index != -1){
            cout<<"Element at index: "<<index<<endl;
        }
        else{
            cout<<"Element not found"<<endl;
        }
       cout<<endl<<"Time Taken = "<<duration.count()<<endl;
       fout<<n<<" "<<duration.count()<<endl;
    }
    return 0;

}