#include<iostream>
#include<chrono>
#include<fstream>
#include<vector>
using namespace std;

const int MAX = 100;

struct point{
    int x, y;
};

int orientation(point a, point b, point c){
    return (b.x - a.x)*(c.y - a.y) -
           (b.y - a.y)*(c.x - a.x);
}

bool insideTriangle(point a, point b, point c, point p){
    int o1 = orientation(a, b, p);
    int o2 = orientation(b, c, p);
    int o3 = orientation(c, a, p);

    if((o1 >= 0 && o2 >= 0 && o3 >= 0) ||
       (o1 <= 0 && o2 <= 0 && o3 <= 0))
        return true;

    return false;
}

int main(){
    int min_el, max_el;

    srand(time(0));
    ofstream fout("convex_hull.txt");

    cout<<"Enter minimum number of points: ";
    cin>>min_el;

    cout<<"Enter maximum number of points: ";
    cin>>max_el;
    cout<<endl;

    fout<<"n time_ns"<<endl;

    for(int n = min_el; n <= max_el; n++){
        cout<<"Number of points = "<<n<<endl;

        vector<point> points(n);

        for(int i = 0; i < n; i++){
            points[i].x = rand() % 100;
            points[i].y = rand() % 100;
            cout<<"("<<points[i].x<<","<<points[i].y<<") ";
        }
        cout<<endl;

        vector<bool> ishull(n, false);

        auto start = chrono::high_resolution_clock::now();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    bool valid = true;

                    for(int m = 0; m < n; m++){
                        if(m == i || m == j || m == k)
                            continue;

                        if(insideTriangle(points[i], points[j], points[k], points[m])){
                            valid = false;
                            break;
                        }
                    }

                    if(valid){
                        ishull[i] = true;
                        ishull[j] = true;
                        ishull[k] = true;
                    }
                }
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<"Convex Hull Points:"<<endl;
        for(int i = 0; i < n; i++){
            if(ishull[i]){
                cout<<"("<<points[i].x<<","<<points[i].y<<") ";
            }
        }
        cout<<endl;

        cout<<"Time taken(ns) = "<<duration.count()<<endl<<endl;

        fout<<n<<" "<<duration.count()<<endl;
    }

    fout.close();
    return 0;
}