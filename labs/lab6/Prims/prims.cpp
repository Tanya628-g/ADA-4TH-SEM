#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

const int MAX = 50;
const int INTMAX = 100000;

void prims(int cost[MAX][MAX], int n){
    int t[MAX][2];
    int near[MAX];
    int mincost = 0;
    int k = 0, l = 0;
    int min = INTMAX;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(cost[i][j] < min){
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    t[0][0] = k;
    t[0][1] = l;
    mincost = cost[k][l];

    for(int i=0; i<n; i++){
        if(cost[i][k] < cost[i][l]){
            near[i]= k;
        }
        else{
            near[i] =l;
        }
    }
    near[k] = near[l] = -1;
    for(int j=1; j<n-1; j++){
        min = INTMAX;
        int index = -1;
        for(int i=0; i<n; i++){
            if(near[i] != -1 && cost[i][near[i]] < min){
                min =cost[i][near[i]];
                index= i;
            }
        }
        t[j][0] = index;
        t[j][1] = near[index];
        mincost += cost[index][near[index]];
        near[index] = -1;

        for(int i=0; i<n; i++){
            if(near[i] != -1 && cost[i][index] < cost[i][near[i]]){
                near[i] =index;
            }
        }
    }
    cout<<"Minimum Cost = "<<mincost<<endl;
}
int main(){
    int min_n, max_n;
    int cost[MAX][MAX];

    srand(time(0));
    ofstream fout("prims.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_n;

    cout<<"Enter maximum number of vertices: ";
    cin>>max_n;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(int n=min_n; n<=max_n; n++){
        cout<<"Number of vertices = "<<n<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j){
                    cost[i][j] = 0;
                }
                else{
                    cost[i][j]= rand() % 100 + 1;
                }
            }
        }
        auto start = chrono::high_resolution_clock::now();
        prims(cost, n);
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}