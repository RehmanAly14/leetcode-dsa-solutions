class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        int seat = 1;
        priority_queue<pair<int, char>> pq;

        unordered_map<char, int> f;
        unordered_map<char, int> free;
        for (int i = 0; i < m; i++) {
            f[tasks[i]]++;
            free[tasks[i]] = 1;
        }
        for (auto i : f) {
            char ele = i.first;
            int freq = i.second;
            pair<int, char> p = {freq, ele};
            pq.push(p);
        }
        while (!pq.empty()) {
            vector<pair<int, char>> pull;
            while (!pq.empty()) {
                pair<int, char> p1 = pq.top();
                int fr = p1.first;
                int child = p1.second;
                pq.pop();
                if (free[child] <= seat) {
                    if (fr > 1) {
                        pq.push({fr-1, child});
                        free[child] = seat + n + 1;
                    }
                    break;
                } else {
                    pull.push_back(p1);
                }
            }
            for (int i = 0; i < pull.size(); i++) {
                pq.push(pull[i]);
               
            }
             seat++;
        }

        return seat -1;
    }
};
