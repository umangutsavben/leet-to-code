class Solution {
public:
int ret = 1e9;
    void solve(int i,vector<pair<int,int>>&z,vector<pair<int,pair<int,int>>>&c,int &steps){
        if(i==z.size()){
            ret = min(ret,steps);
            return;
        }
        int crrx = z[i].first;
        int crry = z[i].second;
        for(int j = 0;j<c.size();j++){
            int curx = c[j].second.first;
            int cury = c[j].second.second;
            int coin = c[j].first;
            if(coin == 1) continue;
            int tmp = steps;
            c[j].first--;
            steps = steps + abs(curx-crrx) + abs(cury-crry);
            solve(i+1,z,c,steps);
            steps = tmp;
            c[j].first++;
        }
    }
    int minimumMoves(vector<vector<int>>& grid) {
        // one of the best question i have scene ...
        
        vector<pair<int,int>>z;
        vector<pair<int,pair<int,int>>>c;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0){
                    z.push_back({i,j});
                }
                if(grid[i][j]>1){
                    c.push_back({grid[i][j],{i,j}});
                }
            }
        }

        if(z.size() == 0) return 0;
        int steps =0;
        solve(0,z,c,steps);
        return ret;
    }
};
