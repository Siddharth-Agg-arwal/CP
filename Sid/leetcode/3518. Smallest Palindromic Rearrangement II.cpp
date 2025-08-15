#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution
{
private:
    // Corresponds to the static maxK in the Java code
    static const long long maxK = 1000001;

    long long combinations(int n, int k)
    {
        if (k < 0 || k > n)
        {
            return 0;
        }
        if (k > n - k)
        {
            k = n - k;
        }
        if (k == 0)
        {
            return 1;
        }

        long long result = 1;
        for (int i = 1; i <= k; ++i)
        {
            result = result * (n - i + 1) / i;
            if (result >= maxK)
            {
                return maxK;
            }
        }
        return result;
    }

    long long countPermutations(const std::vector<int> &counts)
    {
        int total_len = 0;
        for (int count : counts)
        {
            total_len += count;
        }

        long long result = 1;
        for (int count : counts)
        {
            if (count > 0)
            {
                result *= combinations(total_len, count);
                if (result >= maxK)
                {
                    return maxK;
                }
                total_len -= count;
            }
        }
        return result;
    }

public:
    std::string smallestPalindrome(std::string inputStr, int K_int)
    {
        long long K = K_int;
        std::vector<int> frequency(26, 0);
        for (char ch : inputStr)
        {
            frequency[ch - 'a']++;
        }

        char mid_char = '\0';
        int odd_counts = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (frequency[i] % 2 != 0)
            {
                odd_counts++;
                mid_char = 'a' + i;
            }
        }

        if (odd_counts > 1)
        {
            return "";
        }

        std::vector<int> halfFreq(26, 0);
        int halfLength = 0;
        for (int i = 0; i < 26; ++i)
        {
            halfFreq[i] = frequency[i] / 2;
            halfLength += halfFreq[i];
        }

        long long totalPerms = countPermutations(halfFreq);
        if (K > totalPerms)
        {
            return "";
        }

        std::string firstHalf;
        for (int i = 0; i < halfLength; ++i)
        {
            for (int c = 0; c < 26; ++c)
            {
                if (halfFreq[c] > 0)
                {
                    halfFreq[c]--;
                    long long perms = countPermutations(halfFreq);
                    if (perms >= K)
                    {
                        firstHalf += (char)('a' + c);
                        break;
                    }
                    else
                    {
                        K -= perms;
                        halfFreq[c]++;
                    }
                }
            }
        }

        std::string secondHalf = firstHalf;
        std::reverse(secondHalf.begin(), secondHalf.end());

        if (mid_char != '\0')
        {
            return firstHalf + mid_char + secondHalf;
        }
        else
        {
            return firstHalf + secondHalf;
        }
    }
};