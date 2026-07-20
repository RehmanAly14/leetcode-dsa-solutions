class Solution {
public:
bool matches(vector<int>&m1,vector<int>&m2){
    for(int i=0;i<26;i++){
        if(m1[i] != m2[i]){
            return false;
        }
    }
     return true;
}
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int>m1(26,0);
        vector<int>m2(26,0);
        for(int i=0;i<s1.size();i++){
            m1[s1[i] - 'a']++;
            m2[s2[i] - 'a']++;
        }

        for(int i=0;i<s2.size()-s1.size();i++){
            if(matches(m1,m2)){
                return true;
            }
            m2[s2[i + s1.size()] - 'a']++;
            m2[s2[i] - 'a']--;
        }
        return matches(m1,m2);
    }
};
