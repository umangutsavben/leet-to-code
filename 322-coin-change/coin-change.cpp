class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amt+1,1e9));
        for(int i=0;i<amt+1;i++){
            if(i%coins[0]==0){
                dp[0][i] = i/coins[0];
            }
        }
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<amt+1;j++){
                int take = 1e9;
                int not_take = dp[i-1][j];
                if(coins[i]<=j){
                    take = 1 + dp[i][j-coins[i]];
                }
                dp[i][j] = min(take,not_take);
            }
        }
    //return dp[1][0];
        return dp[n-1][amt]==1e9?-1:dp[n-1][amt];
    }
};