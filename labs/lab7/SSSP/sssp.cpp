#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

const int MAX = 100;
const int INTMAX = 100000;

void sssp(int cost[MAX][MAX], int n, int source){
    int dist[MAX], visited[MAX];

    for(int i = 0; i < n; i++){
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(int count = 0; count < n - 1; count++){
        int min = INTMAX;
        int u = -1;

        for(int i = 0; i < n; i++){
            if(!visited[i] && dist[i] < min){
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int i = 0; i < n; i++){
            if(!visited[i] && cost[u][i] != INTMAX){
                if(dist[i] > dist[u] + cost[u][i]){
                    dist[i] = dist[u] + cost[u][i];
                }
            }
        }
    }
}

int main(){
    int min_n, max_n;
    int cost[MAX][MAX];

    srand(time(0));
    ofstream fout("sssp.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_n;

    cout<<"Enter maximum number of vertices: ";
    cin>>max_n;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(int n = min_n; n <= max_n; n++){
        cout<<"Vertices = "<<n<<endl;

        // generate random graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    cost[i][j] = 0;
                }
                else{
                    if(rand() % 2)
                        cost[i][j] = rand() % 50 + 1;
                    else
                        cost[i][j] = INTMAX;
                }
            }
        }

        int source = 0;

        auto start = chrono::high_resolution_clock::now();

        sssp(cost, n, source);

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;

        fout<<n<<" "<<duration.count()<<endl;
    }

    fout.close();
    return 0;
}