int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>res=arr;
        int ans=arr[0];
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i]) res[i]=max(res[i], res[j]+arr[i]);
            }
            ans=max(ans, res[i]);
        }
        return ans;
    }
