class Solution {
public:
    bool f(vector<int>&have,vector<int>&need){
        for(int i=0;i<256;i++){
            if(have[i]<need[i]){
                return false;
            }
            
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low=0;
        int n=s.size();
        int res=INT_MAX;
        int start=0;
        vector<int>have(256,0);
        vector<int>need(256,0);
         for(char c : t) {
            need[c]++;
        }

        for(int high=0;high<n;high++){
            have[s[high]]++;
            while(f(have,need)){
                int len=high-low+1;
                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }
       if(res == INT_MAX) return "";
        return s.substr(start,res);
    }
};
