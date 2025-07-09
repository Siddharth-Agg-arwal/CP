class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> yes;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                yes.push('(');
                continue;
            }
            if (!yes.empty() && s[i] == ')' && yes.top() == '(')
            {
                yes.pop();
            }
            else
            {
                yes.push(')');
            }
        }

        return yes.size();
    }
};