class Solution {
public:

int ret;
    int solve(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==n-1 || j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int d = solve(i+1,j,n,m,dp);
        int r = solve(i,j+1,n,m,dp);
        return dp[i][j] = d+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        ret = solve(0,0,n,m,dp);
        return ret;
    }
};