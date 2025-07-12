#include <bits/stdc++.h>
#include <iostream>
#define IOS()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
using namespace std;

int main()
{
    IOS();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        // int ar1size = l - 1;
        // int ar2size = r - l + 1;
        // int ar3size = n - r;

        long long sum2 = 0;
        vector<int> arr1, arr2, arr3;
        for (int i = 0; i < l - 1; i++)
            arr1.push_back(nums[i]);
        for (int i = l - 1; i < r; i++)
        {
            arr2.push_back(nums[i]);
            sum2 += nums[i];
        }

        for (int i = r; i < n; i++)
            arr3.push_back(nums[i]);

        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end(), greater<int>());
        sort(arr3.begin(), arr3.end());

        long long sum1 = sum2, sum3 = sum2;
        // int j = arr2.size() - 1;
        for (int i = 0; i < arr1.size() && i < arr2.size(); i++)
        {
            if (arr2[i] > arr1[i])
            {
                sum1 -= arr2[i];
                sum1 += arr1[i];
                // j -= 1;
            }
            else
            {
                break;
            }
        }

        // cout << "a1 : ";
        // for(int i = 0; i < arr1.size(); i++) cout << arr1[i] << " ";
        // cout << endl;
        // cout << "a2 : ";
        // for(int i = 0; i < arr2.size(); i++) cout << arr2[i] << " ";
        // cout << endl;
        // cout << "a3 : ";
        // for(int i = 0; i < arr3.size(); i++) cout << arr3[i] << " ";
        // cout << endl;

        // j = arr2.size() - 1;
        for (int i = 0; i < arr3.size() && i < arr2.size(); i++)
        {
            if (arr2[i] > arr3[i])
            {
                sum3 -= arr2[i];
                sum3 += arr3[i];
                // j -= 1;
            }
            else
            {
                break;
            }
        }
        // cout << sum1 << " " << sum2 << " " << sum3 << endl;
        cout << min(sum1, sum3) << endl;
        // cout << endl;
    }

    return 0;
}