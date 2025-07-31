class Solution
{
public:
    int minDeletion(string s, int k)
    {
        vector<int> freq_arr(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            freq_arr[s[i] - 'a']++;
        }

        sort(freq_arr.begin(), freq_arr.end());

        int n = s.length();
        int distincts = 0;
        for (int i = 26 - k - 1; i >= 0; i--)
        {
            distincts += freq_arr[i];
        }

        return distincts;
    }
};