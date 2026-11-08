class Solution {
public:
    int f(int i,int idx,vector<int>&nums,int &size,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        int a = 0,b=0;
        if(dp[i][idx+1]!=-1)return dp[i][idx+1];
        if(idx==-1||nums[i]>nums[idx]){
            //size++;
            a = 1+f(i+1,i,nums,size,dp);
        }
        b = f(i+1,idx,nums,size,dp);
        return dp[i][idx+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        //vector<int>tmp;
        int size = 0;
        return f(0,-1,nums,size,dp);
    }
};