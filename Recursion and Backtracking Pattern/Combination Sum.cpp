class Solution {
public:
    void fun(vector<int>&candidates,int n,int idx,vector<int>&dairy,int sum,vector<vector<int>>&res,int target){
        if(idx==n){
            if(sum==target){
                res.push_back(dairy);
            }
            return;
        }
        // Skip current element
         fun(candidates,n,idx+1,dairy,sum,res,target);
         // Take current element
        if(candidates[idx]+sum<=target){
            dairy.push_back(candidates[idx]);
            sum+=candidates[idx];
            fun(candidates,n,idx,dairy,sum,res,target);
             dairy.pop_back();
            sum-=candidates[idx];
        }
        return;
        
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        int idx=0;
        vector<int>dairy;
        vector<vector<int>>res;
        int sum =0;
        fun(candidates,n,idx,dairy,sum,res,target);
        return res;
    }
};
