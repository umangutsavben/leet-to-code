class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string &s){
        if(i==j){
            return 1;
        }
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j] = 2+f(i+1,j-1,s);
        else{
            return dp[i][j] = max(f(i+1,j,s),f(i,j-1,s));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return f(0,n-1,s);
    }
};