class Solution {
public:
    long long func(const vector<int>& piles, int speed) {
        long long total = 0;
        for (int p : piles) {
            total += (p + speed - 1) / speed;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=0;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        int res=-1;
        while(low<=high){
            int guess=(low+high)/2;
            long long hour=func(piles,guess);
            if(hour>h){
                low=guess+1;
            }
            else{
                res=guess;
                high=guess-1;
            }
        }
        return res;
    }
};
