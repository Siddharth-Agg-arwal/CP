#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

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
        int n;
        long long k;
        cin >> n >> k;

        priority_queue<long long, vector<long long>, greater<long long>> pq;

        long long total_sum = 0;
        for (int i = 0; i < n; i++)
        {
            long long val;
            cin >> val;
            total_sum += val;
            pq.push(val);
        }

        while (k > 0)
        {
            long long min1 = pq.top();
            pq.pop();
            long long min2 = pq.top();
            pq.pop();

            long long new_val = (min1 + min2 + 1) / 2;

            if (min2 <= min1 + 1)
            {
                total_sum += new_val;
                k--;
                if (k > 0)
                {
                    total_sum += k * new_val; // Add for all remaining steps
                }
                break;
            }

            total_sum += new_val;
            pq.push(min1);
            pq.push(min2);
            pq.push(new_val);
            k--;
        }

        cout << total_sum << endl;
    }
    return 0;
}