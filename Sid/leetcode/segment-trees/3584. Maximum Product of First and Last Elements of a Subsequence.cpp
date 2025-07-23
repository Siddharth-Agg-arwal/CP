class segTree
{
    vector<pair<long long, long long>> seg;

public:
    segTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx].first = nums[low];
            seg[idx].second = nums[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx].first = min(seg[2 * idx + 1].first, seg[2 * idx + 2].first);
        seg[idx].second = max(seg[2 * idx + 1].second, seg[2 * idx + 2].second);
    }

    pair<long long, long long> query(int idx, int low, int high, int l, int r)
    {
        if (r < low || l > high)
            return {LLONG_MAX, LLONG_MIN};
        if (r >= high && l <= low)
            return seg[idx];

        int mid = (low + high) / 2;
        pair<long long, long long> left = query(2 * idx + 1, low, mid, l, r);
        pair<long long, long long> right = query(2 * idx + 2, mid + 1, high, l, r);
        return {min(left.first, right.first), max(left.second, right.second)};
    }
};

class Solution
{
public:
    long long maximumProduct(vector<int> &nums, int m)
    {
        long long max_prod = LLONG_MIN;
        segTree st(nums.size());
        st.build(0, 0, nums.size() - 1, nums);
        for (int i = 0; i <= nums.size() - m; i++)
        {
            long long curr_prod = LLONG_MIN;
            pair<long long, long long> min_max = st.query(0, 0, nums.size() - 1, i + m - 1, nums.size() - 1);
            curr_prod = max(((long long)nums[i] * min_max.first), ((long long)nums[i] * min_max.second));
            // for(int j = i + m - 1; j < nums.size(); j++){
            //     curr_prod = max<long long>((long long)nums[i] * nums[j], curr_prod);
            // cout << curr_prod << " ";
            // }
            max_prod = max(curr_prod, max_prod);
        }

        return (max_prod == LLONG_MIN ? -1 : max_prod);
    }
};