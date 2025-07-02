int maxProduct(vector<int>& nums) {
        int prod1=nums[0];
        int prod2=nums[0];
        int ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            int temp=max(nums[i], max(nums[i]*prod1, nums[i]*prod2));
            prod2=min(nums[i], min(nums[i]*prod1, nums[i]*prod2));
            prod1=temp;
            ans=max(ans, prod1);
        }
        return ans;
    }
