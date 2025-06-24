#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long factorial(int n)
    {
        long long fact = 1;
        while (n > 0)
        {
            fact = fact * n;
            n -= 1;
        }
        return fact;
    }

    string getPermutation(int n, int k)
    {
        vector<int> inserted;

        for (int i = 1; i <= n; i++)
        {
            inserted.push_back(i);
        }

        k -= 1;
        int terms = n;
        long long fact = factorial(n);
        string ans = "";
        // double k_ = k;
        while (terms > 0)
        {
            int combs = fact / terms;
            int curr_term = k / combs;
            ans += to_string(inserted[curr_term]);
            // cout << inserted[curr_term - 1] << endl;
            inserted.erase(inserted.begin() + curr_term);

            // cout << "fact: " << fact << " " << ",terms: " << terms << " " << ",combs: " << combs << " " << ",curr_term: " << curr_term << ",k: " << k << endl;

            fact = fact / terms;
            terms = terms - 1;
            k %= combs;

            if (k == 0)
                break;
        }

        if (k == 0)
        {
            for (int i = 0; i < inserted.size(); i++)
            {
                ans += to_string(inserted[i]);
            }
        }

        return ans;
    }
};