class Solution {
public:
vector<vector<int>> dp;
int count(vector<int> &walls,int start,int last){
    int L = lower_bound(begin(walls),end(walls),start) - begin(walls);
    int R = upper_bound(begin(walls),end(walls),last) - begin(walls);
    return R - L;
}
int solv(vector<pair<int,int>> &p, vector<int> &walls,int prxn,vector<pair<int,int>> &limits,int ix){
    if(ix==p.size()) return 0;
    if(dp[ix][prxn] != -1) return dp[ix][prxn];
    int lftstart = limits[ix].first;
    if(prxn==1 ){
    lftstart = max(lftstart,limits[ix-1].second+1);
    }
    int L = count(walls , lftstart,p[ix].first) + solv(p,walls,0,limits,ix+1);
    int R = count(walls,p[ix].first,limits[ix].second) + solv(p,walls,1,limits,ix+1);
    return dp[ix][prxn] = max(L,R);
}
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int,int>> p(n);
        for(int i = 0;i<n;i++){
            p[i] = {robots[i],distance[i]};
        }
        sort(p.begin(),p.end());
        sort(walls.begin(),walls.end());
        vector<pair<int,int>> limits(n);
        for(int i = 0;i<n;i++){
            int lftlimit = (i==0) ? 1 :  p[i-1].first + 1 ;
            int rghtlimit = (i== n-1) ? 1e9   : p[i+1].first - 1 ;
            int L  = max(lftlimit,p[i].first - p[i].second);
            int R  = min(rghtlimit,p[i].first + p[i].second);
            limits[i] = {L,R};
        }
        dp.assign(n+1,vector<int>(2,-1));
        return  solv(p,walls,0,limits,0);
    }
};