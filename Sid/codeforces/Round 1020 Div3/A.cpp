#include <iostream>
#include <string>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    for (int t = 0; t < tc; t++)
    {
        int n;
        cin >> n;

        string str;
        cin >> str;

        int num1s = 0, num0s = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
                num1s += 1;
            else
                num0s += 1;
        }

        int total1s = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
                total1s = total1s + num1s - 1;
            else
                total1s = total1s + num1s + 1;
        }
        cout << total1s << endl;
    }

    return 0;
}