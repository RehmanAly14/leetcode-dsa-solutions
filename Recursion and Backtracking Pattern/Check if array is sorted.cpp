class Solution {
  public:
  int fun(vector<int>&arr,int i){
      if(i==arr.size()-1) return true;
      if(arr[i]>arr[i+1]) return false;
      
      return fun(arr,i+1);
      
  }
    bool isSorted(vector<int>& arr) {
        // code here
        int i=0;
        fun(arr,i);
    }
};
