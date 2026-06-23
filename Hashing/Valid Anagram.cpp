class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1=s.size();
        int s2=t.size();
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>map;
        for(int i=0;i<s2;i++){
            map[t[i]]++;
        }
        for(int j=0;j<s1;j++){
            if(map.find(s[j])==map.end()){
                return false;
            }
            map[s[j]]--;
        }
         for (auto &p : map) {
            if (p.second != 0)
                return false;
        }

        return true;
    }
};
