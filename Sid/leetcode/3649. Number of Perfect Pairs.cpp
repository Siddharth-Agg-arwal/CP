class Solution
{
public:
    long long perfectPairs(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        // // set<pair<int,int>> uniqs;
        // unordered_map<int,int> val_pairs;
        // // unordered_set<int> starts;
        // long long perf_pair = 0;
        // int n = nums.size();
        // for(int i = 0; i < n - 1; i++){
        //     // if(i > 0 && nums[i] == nums[i - 1]) continue;
        //     long long a = nums[i];
        //     if(i > 0 && a == nums[i - 1]){
        //         val_pairs[a]--;
        //         perf_pair += val_pairs[a];
        //         continue;
        //     }
        //     // starts.insert(nums[i]);
        //     bool prev_pair_perf = false;
        //     for(int j = i + 1; j < n; j++){

        //         if(prev_pair_perf && j > i + 1 && nums[j] == nums[j - 1]){
        //             perf_pair++;
        //             val_pairs[a]++;
        //             continue;
        //         }
        //         else{
        //             prev_pair_perf = false;
        //             // break;
        //         }
        //         long long b = nums[j];
        //         long long mins = min(abs(a - b), abs(a + b));
        //         long long maxs = max(abs(a - b), abs(a + b));
        //         long long minv = min(abs(a), abs(b));
        //         long long maxv = max(abs(a), abs(b));
        //         if(mins <= minv && maxs >= maxv){
        //             perf_pair++;
        //             val_pairs[a]++;
        //             prev_pair_perf = true;
        //             // uniqs.insert({a ,b});
        //         }
        //         else if(a < 0 && b > 0 && b > abs(a)) break;
        //         else if(a > 0 && b > 0) break;

        //         // cout << a << " " << b  << endl;
        //     }
        // }

        // return perf_pair;

        sort(nums.begin(), nums.end());

        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            long long a_val = nums[i];
            long long abs_a = abs(a_val);

            long long min_abs_b = (abs_a + 1) / 2;
            long long max_abs_b = 2 * abs_a;

            auto start = nums.begin() + i + 1;

            auto it1 = lower_bound(start, nums.end(), min_abs_b);
            auto it2 = upper_bound(start, nums.end(), max_abs_b);
            count += distance(it1, it2);

            if (min_abs_b > 0)
            {
                auto it3 = lower_bound(start, nums.end(), -max_abs_b);
                auto it4 = upper_bound(start, nums.end(), -min_abs_b);
                count += distance(it3, it4);
            }
        }

        return count;
    }
};