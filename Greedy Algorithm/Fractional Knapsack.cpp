class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();

        vector<pair<double, int>> items;
        for(int i = 0; i < n; i++) {
            double ratio = (double)val[i] / wt[i];
            items.push_back({ratio, i});
        }
        sort(items.rbegin(), items.rend());

        double ans = 0;

        for(auto item : items) {

            int i = item.second;

            if(wt[i] <= capacity) {
                // Take complete item
                ans += val[i];
                capacity -= wt[i];
            }
            else {
                // Take fraction
                ans += item.first * capacity;
                break;
            }
        }

        return ans;
    }
};
