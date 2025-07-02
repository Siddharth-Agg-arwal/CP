#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int last=arr[0];
    int ans=1;
    for(int i = 1; i < n; i++) {
        if(arr[i] > last+1) {
            ans ++;
            last = arr[i];
        }
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