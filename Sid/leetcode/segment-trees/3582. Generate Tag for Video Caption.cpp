#include <cctype>
#include <algorithm>

class Solution
{
public:
    string generateTag(string caption)
    {
        stringstream ss(caption);
        string t;
        string res = "#";
        int num = 0;
        for (int i = 0; i < caption.size(); i++)
        {
            if (caption[i] == ' ')
                continue;
            string temp = "";
            while (i < caption.size() && caption[i] != ' ')
            {
                if (caption[i] >= 97 && caption[i] <= 122)
                    temp += caption[i];
                else if (caption[i] >= 65 && caption[i] <= 90)
                    temp += caption[i];
                i += 1;
            }
            if (num == 0)
            {
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                res += temp;
                num += 1;
            }
            else
            {
                std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                std::transform(temp.begin(), temp.begin() + 1, temp.begin(), ::toupper);
                res += temp;
            }
        }

        // cout << res.size() << endl;
        // res = res.substr(0, 100);
        // cout << res.size();
        return res.substr(0, 100);
    }
};