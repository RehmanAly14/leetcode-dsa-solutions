class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>a(V);
        for(int i=0;i<edges.size();i++){
            int s=edges[i][0];
            int d=edges[i][1];
            int w=edges[i][2];
            a[s].push_back({d,w});
            a[d].push_back({s,w});
        }
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            int d=p.first;
            int node=p.second;
            if(d>dist[node]){ //old value
                continue;
            }
            for( int j=0;j<a[node].size();j++){
                int neigh=a[node][j].first;
                int wt=a[node][j].second;
                if(d+wt < dist[neigh]){
                    dist[neigh]=d+wt;
                    pq.push({d+wt,neigh});
                }
            }
        }
        return dist;
    }
};
