class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> f;

        for (auto& w : words) {
            f[w]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto& i : f) {
            pq.push({i.second, i.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
