class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        typedef pair<int,pair<int,int>> pipi;
        priority_queue<pipi,vector<pipi>,greater<pipi>>q;
        q.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        int row[] = {0,0,1,-1};
        int col[] = {1,-1,0,0};
        if(n==1 && m==1) return 0;
        dist[0][0] = heights[0][0];
        while(!q.empty()){
            auto tmp = q.top();
            q.pop();
            int wt = tmp.first;
            int r = tmp.second.first;
            int c = tmp.second.second;
            for(int i=0;i<4;i++){
                int nrow = row[i] + r;
                int ncol = col[i] + c;
                if(nrow<n && ncol<m && nrow>-1 && ncol>-1){
                    int maxi = max(abs(heights[nrow][ncol]-heights[r][c]),wt);
                    if(dist[nrow][ncol]>maxi){
                        dist[nrow][ncol] = maxi;
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};