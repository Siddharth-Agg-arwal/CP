#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n3 = nums.size();
        int n = n3 / 3;
        int N = 3 * n;

        vector<long long> prefix(N);
        priority_queue<long long> maxH;
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            maxH.push(nums[i]);
        }
        prefix[n - 1] = sum;

        for (int i = n; i < N; ++i)
        {
            if (!maxH.empty() && nums[i] < maxH.top())
            {
                sum += nums[i] - maxH.top();
                maxH.pop();
                maxH.push(nums[i]);
            }
            prefix[i] = sum;
        }

        vector<long long> suffix(N);
        priority_queue<long long, vector<long long>, greater<>> minH;
        sum = 0;

        for (int i = N - 1; i >= 2 * n; --i)
        {
            sum += nums[i];
            minH.push(nums[i]);
        }
        suffix[2 * n] = sum;

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            if (!minH.empty() && nums[i] > minH.top())
            {
                sum += nums[i] - minH.top();
                minH.pop();
                minH.push(nums[i]);
            }
            suffix[i] = sum;
        }

        long long answer = LLONG_MAX;
        for (int i = n; i <= 2 * n; ++i)
        {
            answer = min(answer, prefix[i - 1] - suffix[i]);
        }
        return answer;
    }
};
