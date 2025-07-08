class Solution
{
public:
    bool couponValidator(string s)
    {

        if (s.size() == 0)
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 97 && s[i] <= 122)
                continue;
            if (s[i] >= 65 && s[i] <= 90)
                continue;
            if (s[i] >= 48 && s[i] <= 58)
                continue;
            if (s[i] == 95)
                continue;

            return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        vector<string> elec_coup, groc_coup, phar_coup, rest_coup;

        for (int i = 0; i < code.size(); i++)
        {
            if (!isActive[i])
                continue;
            if (couponValidator(code[i]))
            {
                string cat = businessLine[i];
                if (cat == "electronics")
                    elec_coup.push_back(code[i]);
                else if (cat == "grocery")
                    groc_coup.push_back(code[i]);
                else if (cat == "restaurant")
                    rest_coup.push_back(code[i]);
                else if (cat == "pharmacy")
                    phar_coup.push_back(code[i]);
            }
        }

        sort(elec_coup.begin(), elec_coup.end());
        sort(groc_coup.begin(), groc_coup.end());
        sort(rest_coup.begin(), rest_coup.end());
        sort(phar_coup.begin(), phar_coup.end());

        // cout << elec_coup.size() << " " << groc_coup.size()  << " " << phar_coup.size()  << " " << rest_coup.size();

        elec_coup.insert(elec_coup.end(), groc_coup.begin(), groc_coup.end());
        elec_coup.insert(elec_coup.end(), phar_coup.begin(), phar_coup.end());
        elec_coup.insert(elec_coup.end(), rest_coup.begin(), rest_coup.end());

        return elec_coup;
    }
};