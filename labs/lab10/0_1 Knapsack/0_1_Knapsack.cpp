#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

const int MAX = 100;

int main(){
    int min_n, max_n;

    srand(time(0));
    ofstream fout("knapsack.txt");

    cout<<"Enter minimum number of items: ";
    cin>>min_n;

    cout<<"Enter maximum number of items: ";
    cin>>max_n;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(int n=min_n; n<=max_n; n++){
        cout<<"Items = "<<n<<endl;

        int weight[MAX], profit[MAX];

        for(int i=1; i<=n; i++){
            weight[i] = rand() % 10 + 1;
            profit[i] = rand() % 50 + 1;
        }

        int capacity=n * 5;
        int dp[MAX][MAX];
        auto start = chrono::high_resolution_clock::now();

        for(int i=0; i<=n; i++){
            for(int w=0; w<=capacity; w++){
                if(i == 0 || w == 0){
                    dp[i][w] = 0;
                }
                else if(weight[i] <= w){
                    dp[i][w] = max(profit[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
                }
                else{
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Max profit = "<<dp[n][capacity]<<endl;
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;

        fout<<n<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}