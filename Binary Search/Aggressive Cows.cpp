class Solution {
  public:
    bool func(vector<int>& stalls,int n,int k,int guess){
        int cow=1;
        int pos=stalls[0];
        for(int i=0;i<n;i++){
            int dis=stalls[i]-pos;
            if(dis<guess){
                continue;
            }
            cow++;
            pos=stalls[i];
        }
        if(cow>=k) return true;
        else{
            return false;
        }
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(func(stalls,n,k,guess)){
                res=guess;
                low=guess+1;
            }
            else{
                high=guess-1;
            }
        }
        return res;
        
    }
};
