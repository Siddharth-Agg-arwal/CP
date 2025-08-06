#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;

        // if(a1 == a2 && b1 == b2){
        //     cout << "Yes" << endl;
        //     continue;
        // }
        // if((a1 == a2 && b1 != b2) || (a1 != a2 && b1 == b2)){
        //     cout << "No" << endl;
        //     continue;
        // }
        // if(a1 > a2 && b1 > b2){
        //     if(a1 - a2 == b1 - b2){
        //         cout << "Yes\n";
        //     }
        //     else{
        //         cout << "No\n";
        //     }
        // }

        // if(a1 < a2 && b1 < b2){
        //     cout << "No\n";
        //     continue;
        // }

        int v1 = 5 * a1 + b1;
        int v2 = 5 * a2 + b2;

        if (v1 >= v2 && (v1 - v2) % 6 == 0)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }

        // if(a1 < a2 || b1 < b2){
        //     if(abs(a2 - b2) == abs(a1 - b1)*5){
        //         cout << "Yes\n";
        //     }
        //     else{
        //         cout << "No\n";
        //     }
        // continue;
        // //     if(b2 == (b1 - (a2 - a1)*5)){
        // //         cout << "Yes\n";
        // //     }
        // //     else{
        // //         cout << "No\n";
        // //     }
        // //     continue;
        // // }
        // // if(b1 < b2){
        // //     if(a2 == (a1 - (b2 - b1)/5)){
        // //         cout << "Yes\n";
        // //     }
        // //     else{
        // //         cout << "No\n";
        // //     }
        // //     continue;
        // }
    }

    return 0;
}