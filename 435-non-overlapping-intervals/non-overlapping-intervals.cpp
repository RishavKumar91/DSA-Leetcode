class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a , vector<int> &b){
            // if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int ans = 0 ;
        int last = intervals[0][1];
        for(int i = 1 ; i < n ; i++){
            if(last > intervals[i][0]){
                ans++;
                last = min(last,intervals[i][1]);
            }
            else{
                last = intervals[i][1];
            }
        }
    return ans;
    }
};