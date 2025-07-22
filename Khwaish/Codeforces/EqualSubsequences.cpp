#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string ans="";
    for(int i=0; i<k; i++){
        ans+='1';
    }
    for(int i=0; i<n-k; i++){
        ans+='0';
    }
    cout << ans << endl;
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