class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>>a(V);
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            a[s].push_back(d);
            a[d].push_back(s);
        }
        vector<int> res(V, -1);
        vector<int>vis(V,0);
        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src]=1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int node=p.first;
            int dis=p.second;
            res[node]=dis;
            for(int j=0;j<a[node].size();j++){
                int neigh=a[node][j];
                if(vis[neigh]==0){
                    q.push({neigh,dis+1});
                    vis[neigh]=1;
                }
            }
        }
        return res;
        
    }
};
