class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        long long sum1 = 0;
        long long sum2 = 0;
        int n = basket1.size();
        // basket1.sort(basket1.begin(), basket1.end());
        // basket2.sort(basket2.begin(), basket2.end());
        unordered_map<int, int> freq_map1;
        unordered_map<int, int> freq_map2;
        int min_el1 = 1e9 + 1;
        int min_el2 = 1e9 + 1;
        for (int i = 0; i < n; i++)
        {
            freq_map1[basket1[i]]++;
            freq_map2[basket2[i]]++;
            min_el1 = min(min_el1, basket1[i]);
            min_el2 = min(min_el2, basket2[i]);
        }

        vector<int> swap1;
        vector<int> swap2;
        for (auto it : freq_map1)
        {
            int freq = it.second;
            int term = it.first;
            if (freq_map2.find(term) == freq_map2.end())
            {
                if (freq % 2 == 0)
                {
                    for (int i = 0; i * 2 < freq; i++)
                    {
                        swap1.push_back(it.first);
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                int val2 = freq_map2[term];
                if ((freq + val2) % 2 == 1)
                {
                    return -1;
                }
                else
                {
                    if (freq > val2)
                    {
                        for (int i = 0; i * 2 < (freq - val2); i++)
                        {
                            swap1.push_back(it.first);
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        for (auto it : freq_map2)
        {
            int freq = it.second;
            int term = it.first;
            if (freq_map1.find(term) == freq_map1.end())
            {
                if (freq % 2 == 0)
                {
                    for (int i = 0; i * 2 < freq; i++)
                    {
                        swap2.push_back(it.first);
                    }
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                int freq2 = freq_map1[term];
                if ((freq + freq2) % 2 == 1)
                {
                    return -1;
                }
                else
                {
                    if (freq > freq2)
                    {
                        for (int i = 0; i * 2 < (freq - freq2); i++)
                        {
                            swap2.push_back(it.first);
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }

        // for(auto a : swap1){
        //     cout << a << " ";
        // }
        // cout << endl;
        // for(auto b : swap2){
        //     cout << b << " ";
        // }

        int m = swap1.size(), k = swap2.size();
        if (m != k)
            return -1;
        sort(swap1.begin(), swap1.end());
        sort(swap2.begin(), swap2.end());

        long long ans = 0;
        int j = m - 1;
        int overall_min = min(min_el1, min_el2);
        for (int i = 0; i < m; i++)
        {
            if (2 * overall_min < min(swap1[i], swap2[j]))
            {
                ans += 2 * overall_min;
            }
            else
            {
                ans += min(swap1[i], swap2[j]);
                // j -= 1;
            }
            j -= 1;
            // ans += min(swap1[i], swap2[]);
        }

        // if(j != 0){
        //     while(j >= 0){
        //         ans += min_el1;
        //         j -= 1;
        //     }
        // }

        return ans;
    }
};