/*
LeetCode 88: Merge Sorted Array
Approach 1: Extra Space (Simple)
Pattern: Two Pointers

Explanation:
- Create a new vector `res` to store merged result
- Use two pointers to compare nums1 and nums2
- Append smaller element to res
- Copy back res to nums1
Time Complexity: O(m + n)
Space Complexity: O(m + n)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>res;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(j<n){
             res.push_back(nums2[j]);
            j++;
        }
        while(i<m){
            res.push_back(nums1[i]);
            i++;
        }

        for (int k = 0; k < m + n; k++) {
            nums1[k] = res[k];
        }
    }
};
