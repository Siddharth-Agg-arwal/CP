class FindSumPairs
{
    unordered_map<int, int> freq_nums1, freq_nums2;
    vector<int> arr1, arr2;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        arr1.resize(nums1.size());
        arr1 = nums1;
        arr2.resize(nums2.size());
        arr2 = nums2;

        for (int i = 0; i < nums1.size(); i++)
        {
            freq_nums1[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            freq_nums2[nums2[i]] += 1;
        }
    }

    void add(int index, int val)
    {
        int curr = arr2[index];
        arr2[index] += val;
        freq_nums2[curr] -= 1;
        if (freq_nums2[curr] == 0)
            freq_nums2.erase(curr);
        freq_nums2[curr + val] += 1;
    }

    int count(int tot)
    {
        int tot_count = 0;
        for (auto it : freq_nums1)
        {
            if (it.first > tot)
                continue;
            int val = tot - it.first;
            if (freq_nums2.find(val) != freq_nums2.end())
            {
                tot_count += freq_nums2[val] * it.second;
            }
        }

        return tot_count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */