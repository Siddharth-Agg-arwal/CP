#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n = sqrt(stoi(s));
    if(n * n == stoi(s)) {
        cout << 0 << " " << n << endl;
    } else {
        cout << -1 << endl;
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