class Solution {
public:
   
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
        [] (auto &a,auto &b){return a[1]< b[1];}
        );
        priority_queue<int> pq;
        int totaltime = 0;
        for (auto& c : courses) {
            int duration = c[0];
            int lastday = c[1];

            totaltime += duration;
            pq.push(duration);
            if (totaltime > lastday) {
                totaltime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
