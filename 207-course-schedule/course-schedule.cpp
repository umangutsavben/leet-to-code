class Solution {
public:
    // bool bfs(int i,vector<int>&adj[]){
    //     queue<pair<int,int>>q;
    //     q.push({i,-1});
    //     while(!q.empty()){
    //         int n = q.size();
    //         int node = q.front();
    //         q.pop();
    //         for(auto it:adj[node]){

    //         }
    //     }
    // }
    bool dfs(int node,vector<int> adj[],vector<int>&vis,vector<int>&path){
        vis[node] = 1;
        path[node] = 1;
        for(auto it:adj[node]){
            if(path[it]==1){
                return true;
            }
            else if (vis[it]!=1){
                if(dfs(it,adj,vis,path))return true;
            }
        }


        path[node]=-1;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        if(num == 1) return true;
        int n = pre.size();
        //int m = pre[0].size();
        if(num == 1) return true;
        vector<int>adj[num];
        vector<int>path(num,-1);
        vector<int>vis(num,-1);
        for(int i=0;i<n;i++){
            int u = pre[i][0];
            int v = pre[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<num;i++){
            if(vis[i]==-1){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};