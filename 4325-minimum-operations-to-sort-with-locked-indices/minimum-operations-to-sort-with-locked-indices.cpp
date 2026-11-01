class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int r = 0;
        int l = n-1;
        vector<int>sweep(n+1,0);

        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                int maxi = max(i+1,nums[i]);
                int mini = min(i+1,nums[i]);
                sweep[mini-1]++;
                sweep[maxi]--;
                // r = max(maxi,r);
                // l = min(mini,l);
            }
        }
        for(int i=1;i<n;i++){
            sweep[i] = sweep[i] + sweep[i-1];
        }
        int ret = 0;
        for(int i=0;i<=n-1;i++){
            if(locked[i] && sweep[i]>0 ) ret++;
        }
        if(k<ret) return -1;
        //if(l==n-1) return 0;
        // so using the bubble sort we can get it 
        int ct = 0 ;
        for(int i=n-1;i>=0;i--){
            //int mini = nums[l];
            for(int j=0;j<=i-1;j++){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    ct++;
                }
            }
        }
        return ret+ct;
    }
};