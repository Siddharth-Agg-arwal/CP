#include <iostream>
#include <vector>
using namespace std;

void print_permuatation(int n)
{
    vector<int> permute(n, 0);
    int lptr = 0;
    int rptr = n - 1;

    int count = 1;
    while (lptr <= rptr)
    {
        permute[lptr] = count;
        count += 1;
        lptr += 1;

        if (lptr <= rptr)
        {
            permute[rptr] = count;
            count += 1;
            rptr -= 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << permute[i] << " ";
    }
    cout << endl;
}

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        int n = 0;
        cin >> n;
        print_permuatation(n);
    }

    return 0;
}