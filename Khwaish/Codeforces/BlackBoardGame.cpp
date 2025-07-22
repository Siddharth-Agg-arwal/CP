#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int c0=0, c1=0, c2=0, c3=0;
    for(int i=0; i<n; i++){
        if(i%4==0) c0++;
        else if(i%4==1) c1++;
        else if(i%4==2) c2++;
        else c3++;
    }
    int ans = min(c0, c3) + min(c1, c2);
    if(ans*2==n) {
        cout << "BOB" << endl;
    } else {
        cout << "ALICE" << endl;
    }
    return;
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }
    return 0;
}