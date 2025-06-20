#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int temp = x;
        long long reversed_val = 0;

        while (temp)
        {
            reversed_val = reversed_val * 10 + (temp % 10);
            temp = temp / 10;
        }

        if (reversed_val == x)
        {
            return true;
        }

        return false;
    }
};