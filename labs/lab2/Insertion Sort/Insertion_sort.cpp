#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
const int max_size = 100;

void insertion_sort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int min, max;
    cout<<"Enter minimum number of elements: ";
    cin>>min;

    cout<<"Enter maximum number of elements: ";
    cin>>max;

    srand(time(0));
    ofstream fout("insertion_sort.txt");
    fout << "n time_ns"<<endl;

    for(int n = min; n <= max; n++){
        cout<<"\nArray size = "<<n<<endl;
        int arr[max_size];

        cout<<"Unsorted array: ";
        for(int i = 0; i < n; i++){
            arr[i] = rand() % 100;
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        auto start = chrono::high_resolution_clock::now();
        insertion_sort(arr, n);
        auto end = chrono::high_resolution_clock::now();
        cout<<"Sorted array: ";
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        auto duration =chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Time taken: "<<duration.count()<<" ns"<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }

    return 0;
}
