/*
LeetCode 75: Sort Colors
Approach: Dutch National Flag Algorithm (3 pointers)

Time: O(n)
Space: O(1)

Idea:
low  -> boundary for 0s
mid  -> current element
high -> boundary for 2s

Rules:
- if nums[mid] == 0 -> swap with low, low++, mid++
- if nums[mid] == 1 -> mid++
- if nums[mid] == 2 -> swap with high, high--
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int low =0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            
                if(nums[mid]==2){
                    swap(nums[mid],nums[high]);
                    high--;
                }
                else if(nums[mid]==1){
                    mid++;
                }
                else if(nums[mid]==0){
                    swap(nums[mid],nums[low]);
                    low++;
                    mid++;

                }
            
        }
        
    }
};
