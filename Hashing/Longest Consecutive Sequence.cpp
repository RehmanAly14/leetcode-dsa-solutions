class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>a;
        for(int i=0;i<n;i++){
            a.insert(nums[i]);
        }
        int longSub;
        for(int num : a){
            if(a.find(num - 1) != a.end()){
                continue;
            }
            else{
                int currNum=num;
                int currSub=1;
                while(a.find(currNum + 1) != a.end()){
                    currNum++;
                    currSub++;
                }
                longSub = max(longSub,currSub);
            }
        }
        return longSub;
    }
};
