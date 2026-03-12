class Solution {
  public:
   bool func(vector<int>& arr,int n,int k,int guess){
        int s=1;
        int page=0;
        for(int i=0;i<n;i++){
            if(page+arr[i]<=guess){
                page=page+arr[i];
            }
            else{
            s++;
            page=arr[i];
            if(s>k) return false;
            }
        }
        
       return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int low=0;
        int high=0;
        for(int i=0;i<n;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            if(func(arr,n,k,guess)){
                res=guess;
                high=guess-1;
            }
            else{
                low=guess+1;
            }
        }
        return res;
        
    }
};
