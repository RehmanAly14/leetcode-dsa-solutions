class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

       
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist=x*x + y*y;
           
            pair<int,int>curr={dist,i};
            if(pq.size()<k){
                pq.push(curr);
            }
            else{
            if(pq.top().first< curr.first){
                continue;
            }
            pq.pop();
            pq.push(curr);
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            res.push_back(points[idx]);
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
