class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int srow=0;
        int scol=0;
        int erow=m-1;
        int ecol=n-1;
        vector<int> ans;
        while(srow<=erow && scol <=ecol){
        //top
        for(int j=scol;j<=ecol;j++){
            ans.push_back(mat[srow][j]);
        }

        //right
         for(int j=srow+1;j<=erow;j++){
            ans.push_back(mat[j][ecol]);
        }
        //bottom
         for(int j=ecol-1;j>=scol;j--){
            if(srow==erow){
                break;
            }
            ans.push_back(mat[erow][j]);
        }
        //left
         for(int j=erow-1;j>=srow+1;j--){
            if(scol==ecol){
                break;
            }
            ans.push_back(mat[j][scol]);
        }  
        srow++; scol++; erow--; ecol--; 
        }
         return ans; 
    }
   
};
