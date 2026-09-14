class Solution {
public:
    int check(vector<pair<int,int>>&x){
        int n =x.size();
        vector<pair<int,int>>merged;
        int prevS = x[0].first;
        int prevE = x[0].second;
        int ct = 0;
        for(int i=0;i<n;i++){
            int s = x[i].first;
            int e = x[i].second;
            if(prevE>s){
                prevE = max(e,prevE); 
            }
            else{
                prevS = s;
                prevE = max(e,prevE);
                ct++;
            }
        }
        return ct;
    }
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        vector<pair<int,int>>x;
        vector<pair<int,int>>y;
        for(int i=0;i<r.size();i++){
            int sx = r[i][0];
            int ex = r[i][2];
            int sy = r[i][1];
            int ey = r[i][3];
            x.push_back({sx,ex});
            y.push_back({sy,ey});
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        
        int t = check(x);
        int p = check(y);
        if(t>=2 || p>=2) return true;
        else return false;
    }
};