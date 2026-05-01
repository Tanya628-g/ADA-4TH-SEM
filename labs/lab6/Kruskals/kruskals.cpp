#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;
const int MAX = 100;

struct Edge{
    int u, v, w;
};
int parent[MAX], h[MAX];

int set(int i){
    if(parent[i] != i){
        parent[i] = set(parent[i]);
    }
    return parent[i];
}
void union_(int u, int v){
    int uroot = set(u);
    int vroot = set(v);

    if(h[uroot] < h[vroot]){
        parent[uroot] = vroot;
    }
    else if(h[uroot] > h[vroot]){
        parent[vroot] = uroot;
    }
    else{
        parent[vroot] = uroot;
        h[uroot]++;
    }
}
int main(){
    int min_v, max_v;
    Edge edges[MAX];

    srand(time(0));
    ofstream fout("kruskal.txt");

    cout<<"Enter minimum number of vertices: ";
    cin>>min_v;

    cout<<"Enter maximum number of vertices: ";
    cin>>max_v;
    cout<<endl;
    fout<<"n time_ns"<<endl;

    for(int v=min_v; v<=max_v; v++){
        int e = v * 2;   

        cout<<"Vertices = "<<v<<" Edges = "<<e<<endl;
        for(int i = 0; i < e; i++){
            edges[i].u = rand() % v;
            edges[i].v = rand() % v;
            edges[i].w = rand() % 100 + 1;
        }

        for(int i=0; i<v; i++){
            parent[i] = i;
            h[i] = 0;
        }
        auto start = chrono::high_resolution_clock::now();

        sort(edges, edges + e, [](Edge a, Edge b){
            return a.w < b.w;
        });
        int mst_edges = 0;
        for(int i=0; i<e; i++){
            int u=edges[i].u;
            int v=edges[i].v;

            if(set(u) != set(v)){
                union_(u, v);
                mst_edges++;
                if(mst_edges == v - 1){
                    break;
                }
            }
        }
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;
        fout<<v<<" "<<duration.count()<<endl;
    }
    fout.close();
    return 0;
}