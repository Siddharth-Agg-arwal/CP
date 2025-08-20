#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;

        string ans = "";

        // int half = n/2;
        // int i = 0;

        // for(; i < half; i++){
        //     ans += 'a' + (i%26);
        // }

        // if(n%2 == 1){
        //     ans += 'a' + (i%26);
        // }
        // i--;

        for (int i = 0; i < n; i++)
        {
            ans += 'a' + (i % 5);
        }

        // cout << ans << endl;

        // bool check = false;
        // for(int i = 0; i < n; i++){
        //     if(!check){
        //         ans += 'a';
        //         check = true;
        //     }
        //     else{
        //         ans += 'b';
        //         check = false;
        //     }
        // }

        // if(n%2 == 1){
        //     ans.substr(0, n - 1);
        //     ans += ans[n - 2];
        // }

        cout << ans << endl;
    }
}
