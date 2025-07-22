#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <bitset>

using namespace std;

int optimizeNumber(int a, int c)
{
    int m = a | c;

    // Find the most significant bit set in c
    int highestBit = 31;
    while (highestBit >= 0 && ((c >> highestBit) & 1) == 0)
        highestBit--;

    // Start from highest bit and go down
    for (int i = highestBit; i >= 0; --i)
    {
        bool bitInC = (c >> i) & 1;
        bool bitInM = (m >> i) & 1;

        if (bitInM == 1 && bitInC == 0)
        {
            // Try setting bit i to 0
            int temp = m & ~(1 << i);
            if (temp >= a)
            {
                m = temp; // Keep it as 0
            }
            // else, we keep it 1 (do nothing)
        }
    }

    return m;
}
int main()
{
    int a = 3, c = 4;
    cout << "Optimized number: " << optimizeNumber(a, c) << endl;
    return 0;
}
