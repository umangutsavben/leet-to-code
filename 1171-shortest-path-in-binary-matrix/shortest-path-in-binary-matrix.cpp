class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return -1;
        int ct = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0, {0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int r = t.second.first;
            int c = t.second.second;
            int wt = t.first;
            
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    int nrow = r + i;
                    int ncol = c + j;
                    if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==0){
                        if(dist[nrow][ncol]>wt+1){
                            dist[nrow][ncol] = wt+1;
                            q.push({wt+1,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return (dist[n-1][m-1]==1e9?-1:dist[n-1][m-1]+1);
    }
};