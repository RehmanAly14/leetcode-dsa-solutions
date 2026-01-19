/*
LeetCode 26: Remove Duplicates from Sorted Array

Approach: Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)

Explanation:
- One pointer keeps track of unique elements
- Second pointer scans the array
- Duplicate elements are skipped
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int officer = 0;
        int res = 1;
        int cm = 1;
        int n = nums.size();
        while(cm< n){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;
            }
            nums[officer+1]=nums[cm];
            res++;
            officer++;
            cm++;

        }
        return res;
        
    }
};
