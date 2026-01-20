/*
LeetCode 977: Squares of a Sorted Array

Approach:
- Split numbers into negative and positive arrays
- Square both arrays
- Reverse negative array
- Merge two sorted arrays

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<size;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++)
                pos[i]=pos[i]*pos[i];
          
            return pos;
        }
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
            }
             reverse(neg.begin(),neg.end());
            return neg;
        }
       
        int n=neg.size();
        int m=pos.size();
        vector<int>res(n+m);
        for(int i=0;i<n;i++){
            neg[i]=neg[i]*neg[i];
        }
         reverse(neg.begin(),neg.end());
        for(int j=0;j<m;j++){
            pos[j]=pos[j]*pos[j];
        }
         int i = 0, j = 0, id = 0;
        while(i<n && j<m){
            if(neg[i]<=pos[j]){
                res[id]=neg[i];
                id++;
                i++;
            }
            else{
                res[id]=pos[j];
                id++;
                j++;
            }
        }
         while(j<m){
            res[id]=pos[j];
            id++;
            j++;
        }
        while(i<n){
            res[id]=neg[i];
            id++;
            i++;
        }
    return res;
       
        
    }
};
