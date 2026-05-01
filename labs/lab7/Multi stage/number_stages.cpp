#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

#define INF 10000
const int MAX = 50;

int main(){
    int min_v, max_v;
    int arr[MAX][MAX];
    int current[MAX], next[MAX];
    int visited[MAX], indegree[MAX];

    srand(time(0));
    ofstream fout("Multi_stages.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_v;

    cout<<"Enter maximum number of vertices: ";
    cin>>max_v;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(int v = min_v; v <= max_v; v++){
        cout<<"Vertices = "<<v<<endl;

        for(int i = 0; i < v; i++){
            visited[i] = 0;
            indegree[i] = 0;

            for(int j = 0; j < v; j++){
                if(i == j){
                    arr[i][j] = 0;
                }
                else{
                    arr[i][j] = INF;
                }
            }
        }

        // generate random DAG
        for(int i = 0; i < v - 1; i++){
            for(int j = i + 1; j < v; j++){
                if(rand() % 2){
                    arr[i][j] = rand() % 50 + 1;
                    indegree[j]++;
                }
            }
        }

        int stages = 1;

        auto start = chrono::high_resolution_clock::now();

        int source = 0;

        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                source = i;
                break;
            }
        }

        int k = 1;
        current[0] = source;
        visited[source] = 1;

        while(true){
            int p = 0;

            for(int i = 0; i < k; i++){
                int node = current[i];

                for(int j = 0; j < v; j++){
                    if(arr[node][j] != 0 && arr[node][j] != INF && visited[j] == 0){
                        next[p] = j;
                        p++;
                        visited[j] = 1;
                    }
                }
            }

            if(p == 0){
                break;
            }

            for(int i = 0; i < p; i++){
                current[i] = next[i];
            }

            k = p;
            stages++;
        }

        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Stages = "<<stages<<endl;
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;

        fout<<v<<" "<<duration.count()<<endl;
    }

    fout.close();
    return 0;
}