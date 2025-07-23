class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int f_max = 0;
        stack<char> fwd;
        int init_max = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (x > y && s[i] == 'b')
            {
                if (!fwd.empty() && fwd.top() == 'a')
                {
                    init_max += x;
                    fwd.pop();
                }
                else
                    fwd.push(s[i]);
            }
            else if (y > x && s[i] == 'a')
            {
                if (!fwd.empty() && fwd.top() == 'b')
                {
                    init_max += y;
                    fwd.pop();
                }
                else
                    fwd.push(s[i]);
            }
            else
            {
                fwd.push(s[i]);
            }
            // cout << i << " :- " << init_max << endl;
        }

        stack<char> bwd;
        while (!fwd.empty())
        {
            char to_p = fwd.top();
            fwd.pop();
            if (to_p == 'b')
            {
                if (!bwd.empty() && bwd.top() == 'a')
                {
                    init_max += y;
                    bwd.pop();
                }
                else
                {
                    bwd.push(to_p);
                }
            }
            else if (to_p == 'a')
            {
                if (!bwd.empty() && bwd.top() == 'b')
                {
                    init_max += x;
                    bwd.pop();
                }
                else
                    bwd.push(to_p);
            }
            else
            {
                bwd.push(to_p);
            }
        }

        return init_max;
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] == 'a'){
        //         if(!fwd.empty() && fwd.top() == 'a'){
        //             f_max += y;
        //             fwd.pop();
        //         }
        //         else{
        //             fwd.push(s[i]);
        //         }
        //     }
        //     else if(s[i] == 'b'){
        //         if(!fwd.empty() && fwd.top() == 'a'){
        //             f_max += x;
        //             fwd.pop();
        //         }
        //         else{
        //             fwd.push(s[i]);
        //         }
        //     }
        //     else{
        //         fwd.push(s[i]);
        //     }
        // }

        // int b_max = 0;
        // stack<char> bwd;
        // for(int i = 0; i < s.size(); i++){
        //     if(s[i] == 'a'){
        //         if(!bwd.empty() && bwd.top() == 'b'){
        //             b_max += x;
        //             bwd.pop();
        //         }
        //         else{
        //             bwd.push(s[i]);
        //         }
        //     }
        //     else if(s[i] == 'b'){
        //         if(!bwd.empty() && bwd.top() == 'a'){
        //             b_max += y;
        //             bwd.pop();
        //         }
        //         else{
        //             bwd.push(s[i]);
        //         }
        //     }
        //     else{
        //         bwd.push(s[i]);
        //     }
        // }

        // return (f_max, b_max);
    }
};
