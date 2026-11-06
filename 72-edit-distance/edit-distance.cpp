class Solution {
public:
    int f(string w1,string w2,int i,int j){
        if(i==w1.size() || j == w2.size()){
            if(i == w1.size()) return w2.size() - j;
            if(j == w2.size()) return w1.size() - i;
        }
        if(w1[i]==w2[j]){
            return f(w1,w2,i+1,j+1);
        }
        else{
            int a = 1+f(w1,w2,i,j+1);//insert
            int b = 1+f(w1,w2,i+1,j);//delete
            int c = 1+f(w1,w2,i+1,j+1);//insert
            return min(a,min(b,c));
        }
    }
    int minDistance(string w1, string w2) {
        int n = w1.size();
        int m = w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n+1;i++) 
            dp[i][0] = i;
        for(int j=0;j<m+1;j++) 
            dp[0][j] = j;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};