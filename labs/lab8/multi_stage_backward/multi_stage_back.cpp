#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
const int MAX = 100;
const int INTMAX = 10000;

int main(){
    int min_v, max_v;
    int cost[MAX][MAX];
    srand(time(0));
    ofstream fout("multistage.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_v;
    cout<<"Enter maximum number of vertices: ";

    cin>>max_v;
    cout<<endl;
    fout<<"n time_ns"<<endl;

    for(int vertices=min_v; vertices<=max_v; vertices++){
        cout<<"Vertices = "<<vertices<<endl;
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                if(i == j){
                    cost[i][j] = 0;
                }
                else{
                    cost[i][j] = INTMAX;
                }
            }
        }
        for(int i=0; i<vertices - 1; i++){
            for(int j=i+1; j<vertices; j++){
                if(rand() % 2){
                    cost[i][j] = rand() % 50 + 1;
                }
            }
        }
        int min_cost[MAX];
        int path[MAX];

        auto start = chrono::high_resolution_clock::now();
        min_cost[vertices - 1] = 0;
        for(int i=vertices - 2; i>=0; i--){
            min_cost[i] = INTMAX;
            path[i] = -1;
            for(int j=0; j<vertices; j++){
                if(cost[i][j] != INTMAX && i != j){
                    if(min_cost[i] > cost[i][j] + min_cost[j]){
                        min_cost[i] = cost[i][j] + min_cost[j];
                        path[i] = j;
                    }
                }
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout<<"Minimum cost = "<<min_cost[0]<<endl;
        cout<<"Path: ";
        int current = 0;
        while(current != -1 && current != vertices - 1){
            cout<<current + 1<<" -> ";
            current = path[current];
        }
        cout<<vertices<<endl;
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;
        fout<<vertices<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}