/*
GFG: Count Triplets with Sum Smaller than X
Pattern: Sorting + Two Pointers

Problem:
Given an array arr[] of size n and a number sum,
count the triplets (i, j, k) such that:
arr[i] + arr[j] + arr[k] < sum

Approach:
1. Sort the array
2. Fix one element arr[i]
3. Use two pointers:
   left = i+1, right = n-1
4. If current sum < target:
   then all pairs from left to right are valid
   so add (right - left) to answer

Time Complexity: O(n^2)
Space Complexity: O(1)
*/
class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
        long long ans =0;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                long long s = arr[i]+arr[left]+arr[right];
            if (s<sum){
                ans = ans +(right - left);
                left++;
            }
            else {
                right--;
            }
            }
        }
        return ans;
    }
};
