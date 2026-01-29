class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         unordered_map<int, int> f;
        int low=0;
        int high=0;
        int n = fruits.size();
        int res=INT_MIN;
        int k=2;
        for(high=0;high<n;high++){
            f[fruits[high]]++;
            while(f.size()>k){
                f[fruits[low]]--;
                if(f[fruits[low]]==0){
                    f.erase(fruits[low]);
                }
                low++;
            }
          
                int len = high - low +1;
                res=max(len,res);
        }
        return (res == INT_MIN)? -1 : res;
    }
};
