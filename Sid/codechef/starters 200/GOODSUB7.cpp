#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int tc; 
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        
        int st_odd = 0;
        // int st_eve = 0;
        
        bool even = (nums[0]%2 == 0 ? false : true);
        st_odd++;
        for(int i = 1; i < n; i++){
            if(even){
                if(nums[i]%2 == 0){
                    st_odd++; 
                    even = false;
                }
                else{
                    continue;
                }
            }
            else{
                if(nums[i]%2 == 1){
                    st_odd++;
                    even = true;
                }
                else{
                    continue;
                }
            }
        }
        
        cout << st_odd << endl;
    }
}
