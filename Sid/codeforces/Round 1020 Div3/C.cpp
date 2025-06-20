#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int size_arr = 0, max_elem = 0;
        cin >> size_arr >> max_elem;

        vector<int> arrA(size_arr, 0);
        vector<int> arrB(size_arr, 0);

        int max_a = -1;
        int min_a = 1e9;
        for (int i = 0; i < size_arr; i++)
        {
            cin >> arrA[i];
            max_a = max(max_a, arrA[i]);
            min_a = min(min_a, arrA[i]);
        }

        // cout << max_a << " " << min_a << endl;
        int blank_counts = 0;
        set<int> ABsums;
        for (int i = 0; i < size_arr; i++)
        {
            cin >> arrB[i];
            if (arrB[i] != -1)
                ABsums.insert(arrA[i] + arrB[i]);
            else
                blank_counts += 1;
        }

        if (ABsums.size() > 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (ABsums.size() == 1)
        {
            auto sum = ABsums.begin();
            if (*sum < max_a)
            {
                cout << 0 << endl;
            }
            else if (*sum > min_a + max_elem)
            {
                cout << 0 << endl;
            }
            else if (*sum <= min_a + max_elem && blank_counts < size_arr)
            {
                cout << 1 << endl;
            }
            continue;
        }

        // if (blank_counts == size_arr)
        cout << min_a + max_elem - max_a + 1 << endl;
        // continue;
        // cout << 1 << endl;
    }

    return 0;
}