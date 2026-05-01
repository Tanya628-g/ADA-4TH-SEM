#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
const int MAX = 100;

int main(){
    int min_el, max_el;
    srand(time(0));
    ofstream fout("knapsack.txt");

    cout<<"Enter minimum number of items: ";
    cin>>min_el;

    cout<<"Enter maximum number of items: ";
    cin>>max_el;
    cout<<endl;

    fout<<"n time_ns"<<endl;
    for(int n=min_el; n<=max_el; n++){
        cout<<"Number of items = "<<n<<endl;

        double arr[MAX][3];
        for(int i = 0; i < n; i++){
            arr[i][0] = rand() % 100 + 1;   
            arr[i][1] = rand() % 50 + 1;    
            arr[i][2] = arr[i][0] / arr[i][1];

            cout<<"Item "<<i+1<<": P="<<arr[i][0]<<" W="<<arr[i][1]<<" P/W="<<arr[i][2]<<endl;
        }
        int capacity = rand() % (n * 25) + 1;
        cout<<"Capacity = "<<capacity<<endl;
        auto start = chrono::high_resolution_clock::now();

        for(int i=0; i<n - 1; i++){
            for(int j=i + 1; j<n; j++){
                if(arr[i][2] < arr[j][2]){
                    for(int k=0; k<3; k++){
                        swap(arr[i][k], arr[j][k]);
                    }
                }
            }
        }
        double totalProfit = 0;
        int cap = capacity;
        for(int i=0; i< n; i++){
            if(cap >= arr[i][1]){
                cap -= arr[i][1];
                totalProfit += arr[i][0];
            }
            else{
                totalProfit += arr[i][0] * (cap / arr[i][1]);
                break;
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Maximum Profit: "<<totalProfit<<endl;
        cout<<"Time taken(ns): "<<duration.count()<<endl<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}