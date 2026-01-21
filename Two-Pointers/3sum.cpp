/*
LeetCode 15: 3Sum
Pattern: Sorting + Two Pointers

Problem:
Given an integer array nums, return all the unique triplets
[nums[i], nums[j], nums[k]] such that:
- i != j, i != k, j != k
- nums[i] + nums[j] + nums[k] == 0

Approach:
1. Sort the array
2. Fix one element nums[i]
3. Use two pointers (left, right) to find remaining two numbers
4. Skip duplicates to avoid repeated triplets

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int sum = -1*nums[i];
            while(left<right){
                int s = nums[left]+nums[right];
                if(s==sum){
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left>n && nums[left]==nums[left-1]){
                        left++;
                    }
                    while(right>=0 && nums[right]==nums[right+1]){
                        right--;
                    }
                }
                else if(s<sum){
                    left++;
                }
                else{
                    right--;
                }

            }
        }
        return res;
        
    }
};
