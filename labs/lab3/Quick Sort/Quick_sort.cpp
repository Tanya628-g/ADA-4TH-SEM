#include<iostream>
#include<chrono>
#include<fstream>
using namespace std;

void interchange(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int partition(int a[], int m, int p){
    int v = a[m];    
    int i = m;
    int j = p;
    do{
        do{
            i++;
        } while (a[i] <= v && i <= p);

        do{
            j--;
        } while (a[j] > v);

        if (i < j){
            interchange(a, i, j);
        }
    } while (i < j);
    a[m] = a[j];
    a[j] = v;

    return j;
}
void qs(int a[], int p, int q){
    if (p < q){
        int j = partition(a, p, q);
        qs(a, p, j - 1);
        qs(a, j + 1, q);
    }
}
int main(){
    int min,max;
    cout<< "enter minimum numbers of elemnets to be sorted ";
    cin>>min;
    cout<<"enter maximum numbes of elements to be sorted ";
    cin>>max;
    int mid, low, high;
    srand(time(0));
    ofstream fout("quick_sort.txt");
    fout << "n time_ns"<<endl;


    for (int n = min; n <= max; n++){
        cout<<endl<<"Number of elements = "<<n;
        cout<<endl<<"unsorted array = ";
        int arr[n];

        for (int i = 0; i < n; i++){
            arr[i] = rand() % 100;
            cout<< arr[i] <<" ";
        }
        auto start = std::chrono::high_resolution_clock::now();
        qs(arr, 0, n-1);
        auto end = std::chrono::high_resolution_clock::now();
        
        cout<<endl<<"sorted arrray = ";
        for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        cout<<endl<<"Time Taken = "<<duration.count()<<" ns"<<endl;
        fout<<n<<" "<<duration.count()<<endl;
    }    
    return 0;
}