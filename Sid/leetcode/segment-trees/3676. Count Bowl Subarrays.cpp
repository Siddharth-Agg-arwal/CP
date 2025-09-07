class SegTree
{
    // int n;
public:
    vector<int> seg;

    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int low, int high)
    {
        if (r < low || l > high)
        {
            return INT_MIN;
        }
        if (low >= l && high <= r)
        {
            return seg[idx];
        }

        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, l, r, low, mid);
        int right = query(2 * idx + 2, l, r, mid + 1, high);
        return max(left, right);
    }
};

class Solution
{
public:
    long long bowlSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        SegTree s(n);

        s.build(0, 0, n - 1, nums);
        int l = 0, r = 2;

        // long long bowls = 0;
        // while(r < n){
        //     int max_btw = s.query(0, l + 1, r - 1, 0, n - 1);
        //     // cout << max_btw << endl;
        //     int min_ends = min(nums[l], nums[r]);
        //     if(max_btw < min_ends){
        //         bowls++;
        //     }

        //     if(nums[l] < nums[r]){
        //         l++;
        //     }
        //     else{
        //         r++;
        //     }

        //     if(r - l == 1){
        //         r++;
        //     }
        // }

        // l++;
        // if(r - l >= 2){
        //     r = n - 1;
        //     while(r - l >= 2){
        //         int max_btw = s.query(0, l + 1, r - 1, 0, n - 1);
        //         int min_ends = min(nums[l], nums[r]);
        //         if(max_btw < min_ends){
        //             bowls++;
        //         }
        //         l++;
        //     }
        // }

        // return bowls;
        // long long bowls = 0;
        // for(int l = 0; l < n; l++){
        //     for(int r = l + 2; r < n; r++){
        //         int max_btw = s.query(0, l + 1, r - 1, 0, n - 1);
        //         int min_ends = min(nums[l], nums[r]);
        //         if(max_btw < min_ends){
        //             bowls++;
        //         }
        //     }
        // }
        // return bowls;

        vector<int> left_gr(n, -1), right_gr(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                left_gr[i] = st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            if (!st.empty())
                right_gr[i] = st.top();
            st.push(i);
        }

        long long bowls = 0;
        for (int i = 0; i < n; i++)
        {
            int l = left_gr[i];
            int r = right_gr[i];
            if (l != -1 && r != n && r - l >= 2)
            {
                int max_btw = s.query(0, l + 1, r - 1, 0, n - 1);
                int min_ends = min(nums[l], nums[r]);
                if (max_btw < min_ends)
                    bowls++;
            }
        }

        return bowls;
    }
};