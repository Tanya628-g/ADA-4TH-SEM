#include<iostream>
#include<fstream>
#include<chrono>
#include<ctime>
using namespace std;

const int MAX = 100;

int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];

void dijkstra(int n, int start){
    int u = -1, w, min;
    for(int i=1; i<=n; i++){
        visited[i]= 0;
        dist[i]= cost[start][i];
        parent[i] = start;  
    }
    visited[start] = 1;
    dist[start] = 0;
    parent[start] = -1;

    for(int j=2; j<=n; j++){
        min = 999999;
        for(int i=1; i<=n; i++){
            if(dist[i] < min && visited[i] == 0){
                min = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        visited[u] = 1;
        for(w=1; w<=n; w++){
            if(!visited[w]){
                if(dist[w] > dist[u] + cost[u][w]){
                    dist[w]= dist[u] + cost[u][w];
                    parent[w] = u;   // 🔥 update parent
                }
            }
        }
    }
}
void printPath(int v){
    if(v == -1) return;
    printPath(parent[v]);
    cout << v;
    if(parent[v] != -1) cout << " -> ";
}
int main(){
    int min_el, max_el;
    srand(time(0));
    ofstream fout("dijkstra.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_el;
    cout<< "Enter maximum number of vertices: ";
    cin>>max_el;

    fout<<"n time_ns\n";
    for(int n=min_el; n <= max_el; n++){
        cout<<"\nNumber of vertices = " << n << endl;

        for(int i=1; i<=n; i++){
            for(int j=1; j<= n; j++){
                if(i==j)
                    cost[i][j]= 0;
                else
                    cost[i][j]= rand() % 100 + 1; 
            }
        }
        int start= rand() % n + 1;
        cout<<"Starting vertex: "<<start<<endl;

        auto start_time= chrono::high_resolution_clock::now();
        dijkstra(n, start);
        auto end_time= chrono::high_resolution_clock::now();
        chrono::nanoseconds duration= chrono::duration_cast<chrono::nanoseconds>(end_time - start_time);

        for(int i=1; i<=n; i++){
            cout<<"Dist "<<start<<" -> "<<i<<" = "<<dist[i] << " | Path: ";
            printPath(i);   
            cout << endl;
        }
        cout<<"Time(ns): "<< duration.count()<< endl;
        fout<<n<<" "<< duration.count()<<"\n";
    }
    fout.close();
    return 0;
}