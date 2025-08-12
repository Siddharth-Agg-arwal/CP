class Solution
{
public:
    vector<int> grayCode(int n)
    {
        int nums = 1 << n;
        vector<int> ans;
        ans.reserve(nums);

        for (int i = 0; i < nums; i++)
        {
            int val = i ^ (i >> 1);
            ans.push_back(val);
        }
        return ans;
    }
};