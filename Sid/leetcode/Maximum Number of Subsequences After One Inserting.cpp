class Solution
{
public:
    // long long lctCounter(const string & s, string curr_string, int prev_idx, int curr_idx){
    //     if(curr_string.size() == 3 && curr_string == "LCT") return 1;
    //     if(curr_idx == s.size()) return 0;

    //     long long take = 0;
    //     if(s[prev_idx] == 'L' && s[curr_idx] == 'C'){
    //         take = lctCounter(s, curr_string + "C", curr_idx, curr_idx + 1);
    //     }
    //     else if(s[prev_idx] == 'C' && s[curr_idx] == 'T'){
    //         take = lctCounter(s, curr_string + "T", curr_idx, curr_idx + 1);
    //     }

    //     long long not_take = lctCounter(s, curr_string, prev_idx, curr_idx + 1);

    //     return take + not_take;
    // }

    long long numOfSubsequences(string s)
    {
        // cout << lctCounter(s, "", 0, 0) << endl;
        // return 0;
        int n = s.length();
        vector<long long> pref_L(n + 1, 0);
        vector<long long> pref_C(n + 1, 0);
        vector<long long> pref_T(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == 'L')
                pref_L[i] = pref_L[i - 1] + 1;
            else
                pref_L[i] = pref_L[i - 1];
            if (s[i - 1] == 'C')
                pref_C[i] = pref_C[i - 1] + 1;
            else
                pref_C[i] = pref_C[i - 1];
            if (s[i - 1] == 'T')
                pref_T[i] = pref_T[i - 1] + 1;
            else
                pref_T[i] = pref_T[i - 1];
        }

        long long max_imp = 1;
        long long total_combs = 0;
        // for(int i = 1; i<n; i++){
        //     if(pref_C[i] == 0) continue;
        //     long long curr_imp = (pref_C[i] - pref_C[i-1]) * pref_L[i-1] * (pref_T[n] - pref_T[i]);
        // total_combs += curr_imp;
        // long long l1 = (pref_C[i] - pref_C[i-1] + 1) * pref_L[i-1] * (pref_T[n] - pref_T[i]);
        // long long l2 = (pref_C[i] - pref_C[i-1]) * (pref_L[i-1] + 1) * (pref_T[n] - pref_T[i]);
        // long long l3 = (pref_C[i] - pref_C[i-1]) * (pref_L[i-1]) * (pref_T[n] - pref_T[i] + 1);

        // max_imp = max(max_imp, max(l1, max(l2, l3)));
        // cout << max_imp << " ";
        // }

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'C')
            {
                total_combs += pref_L[i] * (pref_T[n] - pref_T[i + 1]);
            }
        }

        long long max_combs = total_combs;
        vector<long long> Tfromend(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            Tfromend[i] = Tfromend[i + 1];
            if (s[i] == 'C')
                Tfromend[i] += (pref_T[n] - pref_T[i + 1]);
        }

        vector<long long> Lfromstart(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            Lfromstart[i] = Lfromstart[i - 1];
            if (s[i - 1] == 'C')
                Lfromstart[i] += (pref_L[i - 1]);
        }

        for (int i = 0; i <= n; i++)
        {
            long long lctL = total_combs + Tfromend[i];
            max_combs = max(max_combs, lctL);
            long long lctC = total_combs + (pref_L[i] * (pref_T[n] - pref_T[i]));
            max_combs = max(max_combs, lctC);
            long long lctT = total_combs + Lfromstart[i];
            max_combs = max(max_combs, lctT);
            Maximum Number of Subsequences After One Inserting
        }

        return max_combs;
    }
};