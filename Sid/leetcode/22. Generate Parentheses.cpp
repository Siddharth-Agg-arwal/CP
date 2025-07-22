class Solution
{
public:
    // void genParenthesisHelper(string& curr_string, int num_brackets_left, int num_brackets_right, vector<string>& strings, int n){
    //     if(num_brackets_right < num_brackets_left){
    //         curr_string = curr_string.substr(0, curr_string.size() - 1);
    //         num_brackets_right += 1;
    //         return;
    //     }
    //     if(curr_string.size() == n){
    //         strings.push_back(curr_string);
    //         num_brackets_right = n;
    //         num_brackets_left = n;
    //         return;
    //     }
    void dfs(string &s, int openRem, int closeRem, vector<string> &out)
    {
        if (openRem == 0 && closeRem == 0)
        {
            out.push_back(s);
            return;
        }
        if (openRem > 0)
        {
            s.push_back('(');
            dfs(s, openRem - 1, closeRem, out);
            s.pop_back();
        }
        if (closeRem > openRem)
        {
            s.push_back(')');
            dfs(s, openRem, closeRem - 1, out);
            s.pop_back();
        }
    }

    // genParenthesisHelper(curr_string + "(", num_brackets_left - 1, num_brackets_right, strings, n);
    // genParenthesisHelper(curr_string + ")", num_brackets_left, num_brackets_right - 1, strings, n);

    // }
    vector<string> generateParenthesis(int n)
    {
        int num_brackets_left = n, num_brackets_right = n;
        vector<string> strings;
        string curr_string = "";
        dfs(curr_string, n, n, strings);
        return strings;
    }
};