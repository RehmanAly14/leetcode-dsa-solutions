/*
LeetCode 88: Merge Sorted Array
Approach 2: In-Place Optimal
Pattern: Two Pointers (from back)

Explanation:
- Merge from the end to avoid overwriting elements
- Start pointers at the last valid elements of nums1 and nums2
- Compare and put the larger element at the back of nums1
- If nums2 still has elements, copy them
Time Complexity: O(m + n)
Space Complexity: O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1,j=n-1,k=m+n-1;
       while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }
        else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
       }
       while(j>=0){
        nums1[k]=nums2[j];
        j--;
        k--;
       }
    }  
};
