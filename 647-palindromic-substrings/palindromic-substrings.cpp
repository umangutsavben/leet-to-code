class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ct = 01;
        int ans=0;
        for(int l=1;l<n+1;l++){
            for(int i=0;l+i-1<n;i++){
                int j = i+l-1;
                if(i==j) dp[i][j] = 1;
                else if (i+1==j) {
                    dp[i][j] = (s[i]==s[j]);
                    if(s[i]==s[j]){
                        ct = max(j-i+1,ct);
                    }
                }
                else {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]==1);
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        ct = max(ct,j-i+1);
                    }
                }
                if(dp[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};