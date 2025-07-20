#include <bits/stdc++.h>
using namespace std;

class SegTree
{

public:
    vector<int> seg;
    SegTree(int n)
    {
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int> &arr, int orr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr, !orr);
        build(2 * idx + 2, mid + 1, high, arr, !orr);

        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }

    void update(int idx, int low, int high, int i, int val, int orr)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val, !orr);
        else
            update(2 * idx + 2, mid + 1, high, i, val, !orr);

        if (orr)
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        else
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
    }
};

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     // cin >> height >> m;
//     n = 1 << n;
//     vector<int> arr(n);

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     vector<vector<int>> queries(m, vector<int>(2));
//     for (int i = 0; i < m; i++)
//     {
//         cin >> queries[i][0] >> queries[i][1];
//     }

//     if(n == 2){
//         // cout << (arr[0] | arr[1]) << endl;
//         for(int i = 0; i < m; i++){
//             arr[queries[i][0] - 1] = queries[i][1];
//             cout << (arr[0] | arr[1]) << endl;
//         }
//         return 0;
//     }

//     SegTree st(n);
//     if (n % 2 == 0)
//         st.build(0, 0, n - 1, arr, 0);
//     else
//         st.build(0, 0, n - 1, arr, 1);

//     for (int i = 0; i < m; i++)
//     {
//         if (st.seg[queries[i][0] - 1] == queries[i][1]){
//             cout << st.seg[0] << endl;
//             continue;
//         }

//         if (n % 2 == 0)
//             st.update(0, 0, n - 1, queries[i][0] - 1, queries[i][1], 0);
//         else
//             st.update(0, 0, n - 1, queries[i][0] - 1, queries[i][1], 1);
//         cout << st.seg[0] << endl;
//     }
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    cin >> h >> m;
    int N = 1 << h;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    bool startWithOr = (h % 2 == 1);
    SegTree st(N);
    st.build(0, 0, N - 1, arr, startWithOr);

    while (m--)
    {
        int p, b;
        cin >> p >> b;
        --p;
        st.update(0, 0, N - 1, p, b, startWithOr);
        cout << st.seg[0] << "\n";
    }
    return 0;
}
