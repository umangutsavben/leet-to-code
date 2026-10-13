class Solution {
public:
    bool f(int i,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if(i==nums.size()){
            return dp[n] = true;
        }
        if(dp[i]!=-1) return dp[i];
        bool two = false;
        if(i<n-1){
            if(nums[i]==nums[i+1]){
                two = f(i+2,nums,dp);
            }
        }
        bool three = false;
        if(i<n-2){
            if((nums[i]==nums[i+1] && nums[i]==nums[i+2])||((nums[i+1]-nums[i])==1 && (nums[i+2]-nums[i+1])==1)){
                three = f(i+3,nums,dp);
            }
        }

        return dp[i] = three | two;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        bool ans = f(0,nums,dp);
        return ans;
    }
};