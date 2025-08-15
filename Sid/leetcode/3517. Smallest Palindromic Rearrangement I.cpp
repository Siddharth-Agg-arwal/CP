class Solution
{
public:
    string smallestPalindrome(string s)
    {
        vector<int> freq_arr(26, 0);
        for (auto c : s)
        {
            freq_arr[c - 'a']++;
        }

        char odd_c = '\0';
        string ans = "";
        for (int i = 0; i < 26; i++)
        {
            if (freq_arr[i] == 0)
                continue;
            if (freq_arr[i] % 2 == 1)
            {
                odd_c = i + 'a';
                freq_arr[i]--;
            }
            for (int j = 0; j < freq_arr[i] / 2; j++)
            {
                ans += (i + 'a');
            }
        }
        string temp = ans;
        reverse(temp.begin(), temp.end());
        if (odd_c != '\0')
        {
            ans += odd_c;
        }

        ans += temp;
        return ans;
    }
};