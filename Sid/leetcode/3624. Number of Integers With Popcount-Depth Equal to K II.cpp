class Fenwick
{
    int n;
    vector<int> f;

public:
    Fenwick(int _n) : n(_n), f(n + 1, 0) {}
    void update(int i, int v)
    {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }

    int query(int i) const
    {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }

    int query(int l, int r) const
    {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};

class Solution
{
public:
    int popDepth(long long n)
    {
        int d = 0;
        while (n != 1)
        {
            n = __builtin_popcountll(n);
            ++d;
        }
        return d;
    }

    vector<int> popcountDepth(vector<long long> &nums, vector<vector<long long>> &queries)
    {

        int n = nums.size();
        const int D = 5;
        vector<Fenwick> bit;
        for (int d = 0; d < D; d++)
        {
            bit.emplace_back(n);
        }

        vector<int> depth_arr(n);
        for (int i = 0; i < n; i++)
        {
            int d = popDepth(nums[i]);
            depth_arr[i] = d;
            bit[d].update(i + 1, 1);
        }

        vector<int> ans;
        for (auto &q : queries)
        {
            if (q[0] == 2)
            {
                int idx = q[1];
                long long val = q[2];
                int old = depth_arr[idx];
                int new_v = popDepth(val);
                if (old != new_v)
                {
                    bit[old].update(idx + 1, -1);
                    bit[new_v].update(idx + 1, +1);
                    depth_arr[idx] = new_v;
                }
            }
            else
            {
                int l = q[1], r = q[2], k = q[3];
                if (k < 0 || k >= D)
                    ans.push_back(0);
                else
                    ans.push_back(bit[k].query(l + 1, r + 1));
            }
        }

        return ans;
        //     vector<int> set_bits(nums.size(), 0);

        //     for(int i = 0; i < nums.size(); i++){
        //         set_bits[i] =  popDepth(nums[i]);
        //     }

        //     vector<int> ans;
        //     for(auto query : queries){
        //         if(query.size() == 3){
        //             long long idx = query[1];
        //             long long val = query[2];
        //             set_bits[idx] = popDepth(val);
        //         }
        //         else{
        //             long long l = query[1];
        //             long long r = query[2];
        //             long long k = query[3];
        //             long long curr = 0;
        //             for(int i = l; i <= r; i++){
        //                 // cout << set_bits[i] << " ";
        //                 if(set_bits[i] == k){
        //                     curr += 1;
        //                 }
        //             }
        //             // cout << endl;

        //             ans.push_back(curr);
        //         }
        //     }

        //     return ans;
    }
};

// [0,0,1,0,0,1,0,0,2]