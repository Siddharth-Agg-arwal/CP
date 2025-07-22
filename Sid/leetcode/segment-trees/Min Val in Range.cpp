#include <bits/stdc++.h>
using namespace std;

class SEGTree
{
    vector<int> seg;

public:
    SEGTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, int arr[], int seg[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = ((low + high) / 2);
        build(2 * idx + 1, low, mid, arr, seg);
        build(2 * idx + 2, mid + 1, high, arr, seg);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r, int seg[])
    {
        // no overlap
        if (r < low || high < l)
            return INT_MAX;

        // complete overlap
        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;
        int left = query(2 * idx + 1, low, mid, l, r, seg);
        int right = query(2 * idx + 2, mid + 1, high, l, r, seg);
        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val, int seg[])
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val, seg);
        else
            update(2 * idx + 2, mid + 1, high, i, val, seg);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     int seg[4 * n];
//     build(0, 0, n - 1, arr, seg);
// }