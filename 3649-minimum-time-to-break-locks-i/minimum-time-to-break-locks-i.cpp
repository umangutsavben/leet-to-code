class Solution {
public:
    int f(vector<int>& s,int k,vector<int>&vis,int e,int x){
        //if(i==s.size()) return 0;
        int mini = 1e9;
        int n = s.size();
        int all = 0;
        for(int i=0;i<n;i++){
            if(vis[i]==0) all = 1;
        }
        if(all==0) return 0 ;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                float t=s[i]; 
                int tmp = ceil(t/e);
                tmp = tmp + f(s,k,vis,x+k,x+k);
                mini = min(tmp,mini);
                vis[i]=0;
            }
        }
        return mini;
    }
    int findMinimumTime(vector<int>& s, int k) {
        int n = s.size();
        vector<int>vis(n,0);
        int ans = f(s,k,vis,1,1);
        return ans;
    }
};