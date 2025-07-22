#include <bits/stdc++.h>
using namespace std;

struct info
{
    int open, close, full;

    info() : open(0), close(0), full(0) {}

    info(int _open, int _close, int _full)
        : open(_open), close(_close), full(_full) {}
};

info merge(info left, info right)
{
    info ans = info(0, 0, 0);
    ans.full = left.full + right.full + min(left.open, right.close);
    ans.open = left.open + right.open - min(left.open, right.close);
    ans.close = left.close + right.close - min(left.open, right.close);
    return ans;
}

class Segtree
{
public:
    vector<info> seg;
    Segtree(int n)
    {
        seg.resize(4 * n + 1, info(0, 0, 0));
    }
    void build(int idx, int low, int high, string &s)
    {
        if (low == high)
        {
            seg[idx] = info(s[low] == '(', s[low] == ')', 0);
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, s);
        build(2 * idx + 2, mid + 1, high, s);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    info query(int idx, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return info();
        if (low >= l && high <= r)
            return seg[idx];
        int mid = (low + high) / 2;
        info left = query(2 * idx + 1, low, mid, l, r);
        info right = query(2 * idx + 2, mid + 1, high, l, r);
        return merge(left, right);
    }
};

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    Segtree st(n);
    st.build(0, 0, n - 1, s);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        info temp = st.query(0, 0, n - 1, l - 1, r - 1);
        cout << 2 * temp.full << endl;
    }

    return 0;
}