/*
Problem: Maximum Sum Subarray of Size K
Approach: Sliding Window
Time: O(n)
Space: O(1)
*/
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low=0;
        int high=k-1;
        int sum=0;
        int n=arr.size();
        for(int i=low;i<=high;i++){
            sum +=arr[i];
        }
            int res=sum;
            while(high<n){
                res=max(res,sum);
                low++;
                high++;
                if(high==n){
                    break;
                }
                sum -=arr[low-1];
                sum +=arr[high];
            }
        
        return res;
    }
};
