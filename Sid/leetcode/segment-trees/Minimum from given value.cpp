class segTree
{

private:
    vector<int> seg;
    // int n;

public:
    segTree() {}

    segTree(int _n)
    {
        seg.resize(4 * _n + 1);
        // n = _n;
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
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r)
    {
        if (l > high || r < low)
            return 0;
        if (l <= low && r >= high)
            return seg[idx];

        int mid = (low + high) / 2;
        int l_less = query(2 * idx + 1, low, mid, l, r);
        int r_less = query(2 * idx + 2, mid + 1, high, l, r);

        return l_less + r_less;
    }
};

class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        int max_el = -1e9;
        int min_el = 1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            max_el = max(nums[i], max_el);
            min_el = min(nums[i], min_el);
        }

        vector<int> ans(nums.size());
        if (max_el <= 0)
        {
            vector<int> freq_arr(abs(min_el) + 1, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                freq_arr[abs(nums[i])] += 1;
            }
            int n = abs(min_el);
            segTree s1(n);
            s1.build(0, 0, n - 1, freq_arr);
            for (int i = 0; i < nums.size(); i++)
            {
                ans[i] = s1.query(0, 0, abs(min_el) - 1, abs(nums[i]), abs(min_el));
            }
            return ans;
        }
        else if (min_el >= 0)
        {
            int n = abs(max_el);
            segTree s1(n);
            vector<int> freq_arr(max_el + 1, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                freq_arr[nums[i]] += 1;
            }
            s1.build(0, 0, n - 1, freq_arr);
            for (int i = 0; i < nums.size(); i++)
            {
                ans[i] = s1.query(0, 0, max_el - 1, 0, nums[i] - 1);
            }
            return ans;
        }
        else
        {
            segTree s1(max_el);
            vector<int> freq_arr1(max_el + 1, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                freq_arr1[nums[i]] += 1;
            }
            s1.build(0, 0, max_el - 1, freq_arr1);
            vector<int> freq_arr2(abs(min_el) + 1, 0);
            for (int i = 0; i < nums.size(); i++)
            {
                freq_arr2[abs(nums[i])] += 1;
            }
            segTree s2(abs(min_el));
            s1.build(0, 0, abs(min_el) - 1, freq_arr2);
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > 0)
                {
                    ans[i] = s1.query(0, 0, max_el - 1, 0, nums[i] - 1) + s2.query(0, 0, abs(min_el) - 1, 0, abs(min_el));
                }
                else
                {
                    ans[i] = s2.query(0, 0, abs(min_el) - 1, abs(nums[i]) + 1, abs(min_el));
                }
            }
        }

        return ans;
    }
};