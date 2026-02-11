class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
         if (totalSum - nums[0] == 0) {
            return 0;
        }
        for(int i=1;i<nums.size();i++){
            left+=nums[i-1];
            int right=totalSum-nums[i]-left;
            if(left==right){
                return i;
            }
        }
        return -1;
        
    }
};
