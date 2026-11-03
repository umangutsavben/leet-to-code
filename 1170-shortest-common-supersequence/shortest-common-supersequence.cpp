class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(); // s1
        int m = s2.size(); // s2

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){ // s1
            for(int j=1;j<m+1;j++){ // s2
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int l = n; // s1
        int r = m; // s2
        string ans;
        while(l>0 && r>0){
            if(s1[l-1]==s2[r-1]){
                ans = ans + s1[l-1];
                l--;
                r--;
            }
            else if(dp[l-1][r]>dp[l][r-1]){
                ans = ans + s1[l-1];
                l--;
            }
            else{
                ans = ans + s2[r-1];
                r--;
            }
        }
        while(l>0){
            ans = ans + s1[l-1];
            l--;
        }
        while(r>0){
            ans = ans + s2[r-1];
            r--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};