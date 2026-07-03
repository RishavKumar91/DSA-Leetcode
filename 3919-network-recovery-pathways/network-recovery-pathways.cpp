class Solution {
public:
typedef long long ll;
int n ;
bool ok(int mid  , vector<list<pair<int,int>>> &aj,long long k){
    priority_queue< pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    vector<ll> dist(n+1,LLONG_MAX) ; pq.push({0,0}); dist[0] = 0 ;
    while(!pq.empty()){
        auto [ x , node] = pq.top();
        pq.pop();
        if(x > k || x > dist[node] ) continue;
        if(node == n-1) return 1;
        for(auto &ngbr : aj[node]){
            if(ngbr.second < mid) continue;
            ll nw = 1LL * ngbr.second + x;
            int nn = ngbr.first;
            if(nw < dist[nn] && nw <=k ) {
                dist[nn] = nw;
                pq.push({nw,nn});
            }
        }
    }
return 0;
}
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        vector<list<pair<int,int>>> aj(n);
        int start = INT_MAX , last = INT_MIN;
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0] ; 
            int v = edges[i][1] ; 
            int w = edges[i][2] ; 
            start = min(start , w) , last = max(last,w);
            if(online[u] == 0 || online[v]==0) continue;
            aj[u].push_back({v,w}); 
        }
        int ans = -1;
        while(start <= last){
            int mid = start + (last-start) / 2 ;
            if(ok(mid,aj,k)){
                ans = mid;
                start = mid+1;
            }
            else{
                last = mid-1;
            }
        }
    return ans;
    }
};