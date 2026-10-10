class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<list<pair<int,int>>> aj(n+1);
        for(auto &x : times){
            aj[x[0]].push_back({x[1],x[2]});
        }
        vector<int> dist(n+1,INT_MAX);
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k] = 0 ;
        pq.push({0,k});
        while(pq.size()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u])
                continue;
            for(auto [v, wt] : aj[u]) {
                if(d + wt < dist[v] ) {
                    int nd = d + wt;
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        int ans = INT_MIN ; 
        for(int i = 1 ; i <= n ; i++) {
            if(dist[i] == INT_MAX) return -1 ; 
            ans = max(ans,dist[i]);
        }
    return ans ; 
    }
};