#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int str_len = 0;
        string str = "";
        cin >> str_len >> str;
        bool flag = false;
        vector<int> freq_arr(26, 0);

        for (int i = 0; i < str_len; i++)
        {
            freq_arr[str[i] - 'a'] += 1;
            if (freq_arr[str[i] - 'a'] > 1)
            {
                if (str[i] == str[0] && str[i] == str[str_len - 1])
                {
                    if (freq_arr[str[i] - 'a'] > 2)
                    {
                        cout << "YES" << endl;
                        flag = true;
                        break;
                    }
                }
                else
                {
                    cout << "YES" << endl;
                    flag = true;
                    break;
                }
            }
        }

        if (!flag)
            cout << "NO" << endl;
    }

    return 0;
}