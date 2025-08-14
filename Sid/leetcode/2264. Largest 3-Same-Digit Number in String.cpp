class Solution
{
public:
    string largestGoodInteger(string num)
    {
        string ans = "";
        for (int i = 2; i < num.size(); i++)
        {
            if (num[i] == num[i - 1] && num[i] == num[i - 2])
            {
                if (ans == "")
                {
                    string t = num.substr(i - 2, 3);
                    // t  = num[i-2] + num[i-1] + num[i];
                    // cout << t << endl;
                    ans = t;
                }
                else
                {
                    // string t = "";
                    // t  = num[i-2] + num[i-1] + num[i];
                    string t = num.substr(i - 2, 3);
                    // cout << t << endl;
                    if (ans < t)
                    {
                        ans = t;
                    }
                }
            }
        }

        return ans;
    }
};