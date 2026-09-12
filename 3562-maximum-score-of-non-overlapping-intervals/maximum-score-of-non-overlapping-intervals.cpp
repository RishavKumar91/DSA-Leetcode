class Solution {
public:
struct N{
        long long score ;
        vector<int> ixs;
        N(){score = -1 ; }
    };
    vector<vector<N >> dp ;
    int n;
    vector<int> nxtix;
    N hlpr(vector<vector<int>>& intervals,int ix,int k){
        if(ix == n || k == 0) return N();
        if(dp[ix][k].score != -1) return dp[ix][k];
        N skip = hlpr(intervals,ix+1,k);
        N tmp = hlpr(intervals,nxtix[ix],k-1);
        tmp.score += intervals[ix][2];
        tmp.ixs.push_back(intervals[ix][3]);
        sort( tmp.ixs.begin() , tmp.ixs.end() );
        if(skip.score > tmp.score) return dp[ix][k] = skip;
        else if(skip.score < tmp.score) return dp[ix][k] = tmp;
        else{
            return dp[ix][k] =  skip.ixs < tmp.ixs ? skip : tmp; 
        }
    }
    int findnxt(vector<vector<int>> &intrvals , int x){
        int low = 0 ;
        int high = n-1;
        int ans = n ;
        while(low <= high){
            int mi = low + (high-low)/2;
            if(intrvals[mi][0] > x ){
                ans = mi;
                high = mi - 1;
            }
            else{
                low = mi + 1;
            }
        }
    return ans ; 
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();
        dp.resize(n+1 , vector<N> (5,N()));
        nxtix.assign(n,-1);
        for(int i = 0 ; i < n ; i++){
            intervals[i].push_back(i);
        }
        sort( intervals.begin() , intervals.end() );
        for(int i = 0 ; i < n ; i++){
            int end = intervals[i][1];

            nxtix[i] = findnxt(intervals,end);
        }
        return hlpr(intervals,0,4).ixs ; 
    }
};