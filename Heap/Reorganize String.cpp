class Solution {
public:
 struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        }
    };
    string reorganizeString(string s) {
          int n = s.size();
          string res="";
          int seat=0;
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

        unordered_map<char,int> f;
        for (int i = 0; i < n; i++) {
            f[s[i]]++;
        }
        for (auto i : f) {
            char ele = i.first;
            int freq = i.second;
            pair<int, char> p = {freq, ele};
            pq.push(p);
        }

        while(!pq.empty()){
            pair<int, char> p1=pq.top() ;
            pq.pop();
            if(seat==0 || res[seat-1]!=p1.second){
                res.push_back(p1.second);
                seat++;
                p1.first--;
                if(p1.first>0){
                    pq.push(p1);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char>p2=pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);
                }
                pq.push(p1);
            }
        }
       
        return res;
    }
};
