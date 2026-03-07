// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        int res=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(arr[guess]<x){
                low=guess+1;
            }
            else{
                high=guess-1;
                res=guess;
            }
        }
        return res;
        
    }
};
