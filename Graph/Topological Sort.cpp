class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>a(V);
        vector<int>indeg(V,0);
        for(int i=0; i<edges.size();i++){
            int src = edges[i][0];
            int dest= edges[i][1];
            a[src].push_back(dest);
            indeg[dest]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            res.push_back(node);
            
            for(int j=0;j<a[node].size();j++){
                int neigh = a[node][j];
                indeg[neigh]--;
                if(indeg[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return res;
        
    }
};
