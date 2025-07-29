class Solution
{
public:
    static int count_digits(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    static bool comparator(const int &a, const int &b)
    {
        int v1 = count_digits(a), v2 = count_digits(b);
        if (v1 == v2)
            return a < b;
        return v1 < v2;
    }

    int minSwaps(vector<int> &nums)
    {
        unordered_map<int, int> num_idx;
        int n = nums.size();
        vector<int> nums2 = nums;

        sort(nums.begin(), nums.end(), comparator);
        for (int i = 0; i < n; i++)
        {
            num_idx[nums[i]] = i;
        }
        // for(int i = 0; i < n; i++) cout << nums[i] << " ";

        int total_swap = 0;
        vector<bool> swapped(n, false);

        for (int i = 0; i < n; i++)
        {
            if (swapped[i] || num_idx[nums2[i]] == i)
            {
                swapped[i] = true;
                continue;
            }

            int cycle = 0;
            int j = i;
            while (!swapped[j])
            {
                swapped[j] = true;
                j = num_idx[nums2[j]];
                cycle++;
            }

            if (cycle > 0)
                total_swap += (cycle - 1);
        }

        return total_swap;
    }
};