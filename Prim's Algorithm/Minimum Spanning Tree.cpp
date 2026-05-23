class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        int sum=0;
        vector<vector<pair<int,int>>>a(V);
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            int wt=edges[i][2];
            a[s].push_back({d,wt});
            a[d].push_back({s,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            pq.pop();
            int w=p.first;
            int node=p.second;
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum=sum+w;
            for(int j=0;j<a[node].size();j++){
                int neigh=a[node][j].first;
                int w=a[node][j].second;
                if(vis[neigh]==0){
                    pq.push({w,neigh});
                }
                
            }
        }
        return sum;
    }
};
