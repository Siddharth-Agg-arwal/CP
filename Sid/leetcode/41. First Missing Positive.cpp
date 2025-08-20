class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {

        int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     if(nums[i] == i + 1){
        //         nums[i] = INT_MAX;
        //     }
        //     else{
        //         if(nums[i] <= 0 || nums[i] > n){
        //             nums[i] = INT_MIN;
        //         }
        //         else{
        //             if(nums[nums[i] - 1] != INT_MAX){
        //                 int next_term = nums[nums[i] - 1];
        //                 while(next_term != INT_MAX){

        //                 }
        //             }
        //         }
        //     }
        // }

        // for(int i = 0; i < n; i++){
        //     if(nums[i] != i + 1){
        //         if(nums[i] > n || nums[i] <= 0){
        //             continue;
        //         }
        //         else{
        //             swap(nums[i], nums[nums[i] - 1]);
        //             // i -= 1;
        //         }
        //     }
        // }

        // for(int i = 0; i < n; i++){
        //     // cout << nums[i] << " ";
        //     if(nums[i] != i + 1){
        //         return i + 1;
        //     }
        // }.

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int num = abs(nums[i]);
            if (num > n)
                continue;

            // num--;
            if (nums[num - 1] > 0)
                nums[num - 1] = -1 * nums[num - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};