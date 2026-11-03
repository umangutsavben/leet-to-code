class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ct = 0;
        int ans=0;
        int left,r;
        for(int l=1;l<n+1;l++){
            for(int i=0;l+i-1<n;i++){
                int j = i+l-1;
                if(i==j){
                    dp[i][j] = 1;
                    if(j-i+1>ct){
                        ct = 1;
                        left = i;
                        r = j;
                    }
                }
                else if (i+1==j) {
                    dp[i][j] = (s[i]==s[j]);
                    if(s[i]==s[j]&& j-i+1 > ct){
                        ct = max(j-i+1,ct);
                        left = i;
                        r = j;
                    }
                }
                else {
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]==1); 
                    if(s[i]==s[j] && dp[i+1][j-1]==1 && j-i+1 > ct){
                        ct = max(ct,j-i+1);
                        left = i;
                        r = j;
                    }
                }
                if(dp[i][j]){
                    ans++;
                }
            }
        }
        string a;
        for(int i=left;i<r+1;i++){
            a = a + s[i];
        }
        return a;
    }
};


