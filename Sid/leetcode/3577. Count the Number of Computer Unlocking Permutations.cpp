class Solution
{
public:
    const int mod = 1e9 + 7;

    long long factorial(int n)
    {
        if (n == 0)
            return 1;
        long long val = 1;
        while (n > 0)
        {
            val = (long long)(val * n) % mod;
            n -= 1;
        }
        return val;
    }
    int countPermutations(vector<int> &complexity)
    {
        int n = complexity.size();
        unordered_map<int, int> freq_map;
        int min_val = 1e9 + 1;
        for (int i = 1; i < complexity.size(); i++)
        {
            // freq_map[complexity[i]]++;
            if (complexity[i] < complexity[0])
                return 0;
            if (complexity[i] == complexity[0])
                return 0;
            freq_map[complexity[i]]++;
        }

        long long total_combs = factorial(n - 1);
        // for(auto it : freq_map){
        //     if(it.second > 1){
        //         while(it.second > 1){
        //             total_combs /= 2;
        //             it.second -= 1;
        //         }
        //     }
        // }

        return total_combs;
    }
};