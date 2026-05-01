#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
const int MAX = 50;
double infi = (5.0/0.0);
double A[MAX][MAX];

void shortestpath(int n, double cost[][MAX]){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            A[i][j] = cost[i][j];
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(A[i][j] > A[i][k] + A[k][j]){
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }
    }
}
int main(){
    srand(time(0));

    ofstream fout("Allpairshortest.txt");
    fout<<"n time_ns"<<endl;

    for(int n=5; n<=100; n ++){
        double cost[MAX][MAX];
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j)
                    cost[i][j] = 0;
                else
                    cost[i][j] = infi;
            }
        }
        int e = n + rand() % (n * 2);
        for(int i=1; i<=e; i++){
            int u = rand() % n + 1;
            int v = rand() % n + 1;
            int wt = rand() % 20 + 1;

            if(u != v){
                cost[u][v] = wt;
            }
        }
        auto start = chrono::high_resolution_clock::now();
        for(int i=0; i<100; i++){  
            shortestpath(n, cost);
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout<<"Vertices = "<<n<<" Time(ns) = "<<duration.count()<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}