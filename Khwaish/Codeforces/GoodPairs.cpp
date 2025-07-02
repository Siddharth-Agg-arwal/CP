#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n;
    int goodPairs;
    string s;
    cin >> n >> goodPairs;
    cin >> s;
    int z=0;
    int o=0;
    for(int i=0; i<n; i++){
        if(s[i] == '0') z++;
        else o++;
    }
    int totPairs = n/2;
    int badPairs = totPairs - goodPairs;
    while(badPairs > 0) {
        if(z > 0 && o > 0) {
            z--;
            o--;
            badPairs--;
        } 
        else{
            cout << "NO" << endl;
            return;
        }
    }
    int zeroPairs = z / 2;
    int onePairs = o / 2;
    if(zeroPairs + onePairs >= goodPairs) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
