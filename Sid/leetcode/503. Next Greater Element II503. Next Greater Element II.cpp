class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);

        if (n == 1)
            return {-1};

        stack<int> st;
        st.push(0);
        for (int i = 1, j = 0; j <= n * 2; j++, i = (i + 1) % n)
        {
            int top_idx = st.top();
            if (nums[i] <= nums[top_idx])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && nums[top_idx] < nums[i])
                {
                    if (ans[top_idx] == -1)
                        ans[top_idx] = nums[i];
                    st.pop();
                    if (!st.empty())
                        top_idx = st.top();
                }
                st.push(i);
            }
        }

        return ans;
    }
};