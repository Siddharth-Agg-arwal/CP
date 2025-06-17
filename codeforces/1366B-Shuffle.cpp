#include <iostream>
using namespace std;

int indices(int arrSize, int startIdx, int totalOps)
{
    int curr_lptr = startIdx;
    int curr_rptr = startIdx;
    for (int i = 0; i < totalOps; i++)
    {
        int lptr = 0, rptr = 0;
        cin >> lptr >> rptr;
        if (lptr > curr_rptr || rptr < curr_lptr)
        {
            continue;
        }
        else
        {
            curr_lptr = min(curr_lptr, lptr);
            curr_rptr = max(curr_rptr, rptr);
        }
    }

    return curr_rptr - curr_lptr + 1;
}

int main()
{
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i++)
    {
        int arrSize = 0, startIdx = 0, totalOps = 0;
        cin >> arrSize >> startIdx >> totalOps;
        int val = indices(arrSize, startIdx, totalOps);
        cout << val << endl;
    }

    return 0;
}