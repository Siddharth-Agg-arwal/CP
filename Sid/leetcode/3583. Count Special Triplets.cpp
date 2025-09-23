class Solution
{
public:
    static bool comparator(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first < b.first;
    }
    int specialTriplets(vector<int> &nums)
    {
        // vector<pair<int,int>> num_idx(nums.size());
        // for(int i=0 ; i< nums.size(); i++){
        //     num_idx[i].first = nums[i];
        //     num_idx[i].second = i;
        // }
        // sort(num_idx.begin(), num_idx.end(), comparator);

        // int j = 0, i = 1, k = nums.size() - 1;
        // while(i < k && j < i){

        // }

        const int mod = 1e9 + 7;
        int n = nums.size();

        unordered_map<long long, int> right, left;
        right.reserve(2 * n);
        left.reserve(2 * n);

        for (auto &x : nums)
        {
            right[x]++;
        }

        long long ans = 0;
        for (int j = 0; j < n; j++)
        {
            long long x = nums[j];
            if (--right[x] < 0)
            {
                right[x] = 0;
            }

            long long twice = 2LL * x;
            int countL = left[twice];
            int countR = right[twice];

            ans = (ans + 1LL * countL * countR) % mod;
            left[x]++;
        }

        return ans;
    }
};