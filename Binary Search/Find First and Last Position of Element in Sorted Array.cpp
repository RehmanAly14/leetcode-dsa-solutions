class Solution {
public:
   int firstPos(vector<int>& nums, int target){
      int n=nums.size();
        int res=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                high=guess-1;
                res=guess;
            }
        }
        return res;
        
   }
   int secondPos(vector<int>& nums, int target){
      int n=nums.size();
        int res=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(nums[guess]<target){
                low=guess+1;
            }
            else if(nums[guess]>target){
                high=guess-1;
            }
            else{
                low=guess+1;
                res=guess;
            }
        }
        return res;
        
   }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first =firstPos( nums, target);
        int second=secondPos(nums, target);
        return {first,second};

    }
};
