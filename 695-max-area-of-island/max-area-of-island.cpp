class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        int ans=1;
        int row[] = {0,0,1,-1};
        int col[] = {1,-1,0,0};
        for(int i=0;i<4;i++){
            int nrow = row[i] + r;
            int ncol = col[i] + c;
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]!=1){
                ans = ans + dfs(nrow,ncol,vis,grid);
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    maxi = max(dfs(i,j,vis,grid),maxi);
                }
            }
        }
        return maxi;
    }
};