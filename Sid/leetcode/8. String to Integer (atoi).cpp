class Solution
{
public:
    int myAtoi(string s)
    {
        long long val = 0;
        int it = 1;
        int sign = 0;
        bool int_only = false;

        int i = 0;
        while (s[i] == ' ')
            i++;

        for (; i < s.size(); i++)
        {
            if (s[i] - '0' < 0 || s[i] - '0' > 9)
            {
                if (int(s[i]) == 45 && !int_only && sign == 0)
                    sign = 1;
                else if (int(s[i]) == 43 && !int_only && sign == 0)
                    sign = 2;
                else
                    break;
            }
            else
            {
                int_only = true;
                if (s[i] - '0' == 0 && it == 1)
                {
                    continue;
                }
                else
                {
                    it += 1;
                    try
                    {
                        if ((val * 10) + int(s[i] - '0') > INT_MAX)
                            val = pow(2, 31);
                        // else if(val * 10 < INT_MIN) val = INT_MIN;
                        else
                        {
                            val *= 10;
                            val += int(s[i] - '0');
                        }
                    }
                    catch (int nothing)
                    {
                        cout << "do nothing";
                    }
                }
            }
        }

        if (sign == 1)
            val = val * (-1);
        if (val == pow(2, 31))
            return val - 1;
        return val;
    }
};