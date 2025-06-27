class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss1(version1);
        stringstream ss2(version2);
        vector<int> str1;
        vector<int> str2;

        string str = "";
        while (getline(ss1, str, '.'))
        {
            int val = stoi(str);
            str1.push_back(val);
        }

        str = "";
        while (getline(ss2, str, '.'))
        {
            int val = stoi(str);
            // if(val%10 == 0){
            // while(val%10 == 0 && val > 0){
            //     val = val/10;
            // }
            // }
            str2.push_back(val);
        }

        int i = 0;
        while (i < str1.size() || i < str2.size())
        {

            int a = (i < str1.size()) ? str1[i] : 0;
            int b = (i < str2.size()) ? str2[i] : 0;
            if (a > b)
                return 1;
            else if (a < b)
                return -1;

            i += 1;
        }

        return 0;
    }
};