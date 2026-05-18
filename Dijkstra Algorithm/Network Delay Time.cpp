class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> a(n);
        for (int i = 0; i < times.size(); i++) {
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s - 1].push_back({d - 1, w});
        }
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);
        k--;
        dist[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
            if (d > dist[node]) { // old value
                continue;
            }
            for (int j = 0; j < a[node].size(); j++) {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if (d + wt < dist[neigh]) {
                    dist[neigh] = d + wt;
                    pq.push({d + wt, neigh});
                }
            }
        }
        if (*max_element(dist.begin(), dist.end()) == INT_MAX) {
            return -1;
        } else {
            return *max_element(dist.begin(), dist.end());
        }
    }
};
