class NumArray
{
public:
    vector<int> seg;
    int n;

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        seg.resize(4 * n + 1);
        buildTree(0, 0, n - 1, nums);
    }

    void buildTree(int idx, int low, int high, vector<int> &nums)
    {
        if (low == high)
        {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;
        buildTree(2 * idx + 1, low, mid, nums);
        buildTree(2 * idx + 2, mid + 1, high, nums);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void updateHelper(int idx, int low, int high, int index, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (index <= mid)
            updateHelper(2 * idx + 1, low, mid, index, val);
        else
            updateHelper(2 * idx + 2, mid + 1, high, index, val);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void update(int index, int val)
    {
        updateHelper(0, 0, n - 1, index, val);
    }

    int sumRangeHelper(int idx, int low, int high, int left, int right)
    {
        if (left > high || right < low)
            return 0; // no overlap
        if (left <= low && right >= high)
        { // partial overlap
            return seg[idx];
        }
        int mid = (low + high) / 2;
        int l_sum = sumRangeHelper(2 * idx + 1, low, mid, left, right);
        int r_sum = sumRangeHelper(2 * idx + 2, mid + 1, high, left, right);
        return l_sum + r_sum;
    }
    int sumRange(int left, int right)
    {
        return sumRangeHelper(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */