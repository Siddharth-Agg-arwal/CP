class Solution
{
public:
    char kthCharacter(long long k, vector<int> &operations)
    {
        vector<long long> arr_length;
        long long it = 1;
        // arr_length.push_back(it);
        for (auto &op : operations)
        {
            it *= 2;
            arr_length.push_back(it);
            if (it >= k)
                break;
        }

        long long change = 0;
        long long n = arr_length.size();
        for (long long i = n - 1; i >= 0; i--)
        {
            long long curr_length = arr_length[i];
            if (k > curr_length / 2)
            {
                if (operations[i] == 1)
                {
                    change += 1;
                }
                k = k - curr_length / 2;
            }
        }

        return char('a' + change % 26);
    }
};