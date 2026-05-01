#include<iostream>
#include<fstream>
using namespace std;

double reduction = 0.575;
int tips;

void no_of_stoppage(double v){
    if(v < 1.0){
        return;
    }
    tips++;
    no_of_stoppage(v * reduction);
}

int main(){
    int min_v, max_v;
    cout<<"Enter minimum velocity: ";
    cin>>min_v;

    cout<<"Enter maximum velocity: ";
    cin>>max_v;

    ofstream fout("tips_data.txt");
    fout<<"velocity tips"<<endl;

    for(int v=min_v; v<=max_v; v++){
        tips = 0;
        no_of_stoppage(v);
        cout<<endl<<"v= "<<v<<endl;
        cout<<"tips= "<<tips<<endl;
        fout<<v<<" "<<tips<<endl;
    }

    fout.close();
    return 0;
}