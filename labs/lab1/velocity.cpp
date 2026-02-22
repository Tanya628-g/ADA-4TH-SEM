#include <iostream>
using namespace std;

int ball(double height) {
    if (height < 0.01) return 0;  
    return 1 + ball(height / 2.0);  
}
int main() {
    double min_h, max_h, interval;
    cout<<"Enter minimum height: ";
    cin>>min_h;

    cout<<"Enter maximum height: ";
    cin>>max_h;

    cout<<"Enter interval: ";
    cin>>interval;
    cout<<endl;

    cout<<"Height Bounces";
    cout<<endl;

    for (double h = min_h; h <= max_h; h += interval) {
        int bounces = ball(h);
        cout << h << "\t" << bounces << endl;
    }

    return 0;
}
