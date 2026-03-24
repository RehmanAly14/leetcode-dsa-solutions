class Solution {
  public:
   bool fun(string& s,int low,int high){
        int len=high-low+1;
        if(len==0 || len==1) return true;
        if(s[low]!=s[high]) return false;
        return fun(s,low+1,high-1);
   }
    bool isPalindrome(string& s) {
        // code here
        int low=0;
        int high=s.size()-1;
        return fun(s,low,high);
       
        
    }
};
