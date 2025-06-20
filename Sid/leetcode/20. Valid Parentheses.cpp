#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> parentheses;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (parentheses.empty())
                {
                    return false;
                }

                if (s[i] == ')')
                {
                    if (parentheses.top() == '(')
                    {
                        parentheses.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[i] == '}')
                {
                    if (parentheses.top() == '{')
                    {
                        parentheses.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (s[i] == ']')
                {
                    if (parentheses.top() == '[')
                    {
                        parentheses.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                parentheses.push(s[i]);
            }
        }

        if (!parentheses.empty())
            return false;
        return true;
    }
};