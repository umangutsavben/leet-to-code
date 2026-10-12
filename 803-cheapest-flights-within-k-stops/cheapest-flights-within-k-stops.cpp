class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        typedef pair<int,pair<int,int>> pi; 
        priority_queue<pi,vector<pi>,greater<pi>>q; // steps,node,paisa
        q.push({0,{src,0}});
        vector<pair<int,int>>adj[n]; // node,paisa
        for(int i=0;i<f.size();i++){
            int u = f[i][0];
            int v = f[i][1];
            int paisa = f[i][2];
            adj[u].push_back({v,paisa});
        }
        k++;
        vector<int>dist(n,1e9);
        dist[src] = 0;
        while(!q.empty()){
            auto tmp = q.top();
            q.pop();
            int node = tmp.second.first;
            int cost = tmp.second.second;
            int steps = tmp.first;
            if(steps == k)continue;
            for(auto it:adj[node]){
                int nxt = it.first;
                int paisa = it.second;
                if(dist[nxt]>cost+paisa){
                    dist[nxt] = cost+paisa;
                    q.push({steps+1,{nxt,cost+paisa}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};