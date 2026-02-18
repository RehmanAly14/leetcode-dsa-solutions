class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int n=start.size();
        int m=end.size();
        int res=0;
        int room=0;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(start[i]<end[j]){
                room++;
                res=max(res,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return res;
    }
};
