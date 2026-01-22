// Sort the array
// Fix one element and use two pointers (left, right) for the remaining part
// Track the minimum difference between current sum and target
// Update the closest sum whenever a smaller difference is found

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int minDiff = INT_MAX;
        int closestSum = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int sum =nums[i]+ nums[left]+nums[right];
                 int diff = abs(sum-target);
                    if(minDiff>diff){
                        minDiff=diff;
                        closestSum=sum;
                    }
                if(sum==target){
                    return sum;
                   
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
        return closestSum;
        
    }
        
};
