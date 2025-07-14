class Solution
{
public:
    void collision_occured(string &top_sign, stack<int> &sters, int &curr_ster)
    {
        while (!sters.empty())
        {
            if (top_sign == "neg")
                break;
            if (abs(sters.top()) > abs(curr_ster))
            {
                break;
            }
            else if (abs(sters.top()) < abs(curr_ster))
            {
                sters.pop();
                if (sters.empty() || sters.top() < 0)
                {
                    sters.push(curr_ster);
                    top_sign = "neg";
                    break;
                }
                else
                {
                    top_sign = (sters.top() > 0 ? "pos" : "neg");
                }
            }
            else
            {
                sters.pop();
                if (!sters.empty())
                {
                    top_sign = (sters.top() > 0 ? "pos" : "neg");
                }
                return;
            }
        }
    }

    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        bool collision = false;

        stack<int> sters;
        string top_sign = "";
        for (int i = 0; i < asteroids.size(); i++)
        {
            if (sters.empty())
            {
                sters.push(asteroids[i]);
                top_sign = (asteroids[i] > 0 ? "pos" : "neg");
            }
            else if (top_sign == "pos" && asteroids[i] < 0)
            {
                collision_occured(top_sign, sters, asteroids[i]);
            }
            else
            {
                sters.push(asteroids[i]);
                top_sign = (asteroids[i] > 0 ? "pos" : "neg");
            }
        }

        vector<int> ans(sters.size());
        for (int i = sters.size() - 1; i >= 0; i--)
        {
            ans[i] = sters.top();
            sters.pop();
        }

        return ans;
    }
};