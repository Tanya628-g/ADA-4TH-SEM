#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

const int MAX = 20;

void truthTable(bool arr[], int n, int index){
    if(index == n){
        for(int i = 0; i < n; i++){
            if(arr[i])
                cout<<"true ";
            else
                cout<<"false ";
        }
        cout<<endl;
        return;
    }

    arr[index] = true;
    truthTable(arr, n, index + 1);

    arr[index] = false;
    truthTable(arr, n, index + 1);
}

int main(){
    int min, max;

    cout<<"Enter minimum number of variables: ";
    cin>>min;

    cout<<"Enter maximum number of variables: ";
    cin>>max;
    cout<<endl;

    ofstream fout("truth_table.txt");
    fout<<"n time_ns"<<endl;

    for(int n = min; n <= max; n++){
        cout<<"\nNumber of variables = "<<n<<endl;

        bool arr[MAX];

        auto start = chrono::high_resolution_clock::now();
        truthTable(arr, n, 0);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Time taken = "<<duration.count()<<" ns"<<endl;

        fout<<n<<" "<<duration.count()<<endl;
    }

    fout.close();
    return 0;
}