#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;

    while (tests--)
    {
        int l = 0, r = 0;
        cin >> l >> r;

        vector<int> vec_l;
        vector<int> vec_r;

        while (l > 0)
        {
            int val1 = l % 10;
            int val2 = r % 10;
            vec_l.push_back(val1);
            vec_r.push_back(val2);
            l /= 10;
            r /= 10;
        }

        for(int i = l; i <= r; i++){
            
        }   
    }
}