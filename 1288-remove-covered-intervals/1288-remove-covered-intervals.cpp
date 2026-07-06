class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[&](vector<int>&x, vector<int>&y){
            if(x[0]==y[0]){
                return x[1]>y[1];
            }
            return x[0]<y[0];
        });
        int cnt=n;
        int mx=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][1]>mx){
                mx=intervals[i][1];
            }
            else{
                cnt--;
            }
        }
        return cnt;
    }
};