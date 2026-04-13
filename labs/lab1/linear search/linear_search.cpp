#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

void ls(int arr[], int ele){
    int mid;
    cout<<"Enter element to be search";
    ele = rand() % 100;
    cout<<ele<<endl;


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
    fout<<"n \t time(ns)";

    for(int n=min; n<=max; n++){
        cout<<"Array of Elements: ";
        int arr[n];
        
        for(int i=0; i<=n ; i++){
            arr[i] = rand() % 100;
            cout<<arr[i]<<" ";
        }
        cout<<"Element searched at "<<ls(arr, n);

        auto start = chrono::high_resolution_clock::now();
        int ele= ls(arr,n);
        auto end= chrono::high_resolution_clock::now();
        std::chrono::nanoseconds duration= std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

       cout<<endl<<"Time Taken = "<<duration.count()<<endl;
       fout<<n<<" "<<duration.count()<<endl;
    }
    return 0;

}