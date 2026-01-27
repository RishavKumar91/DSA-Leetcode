class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long       ,    int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [currDist, u] = pq.top();
            pq.pop();
            if(currDist > dist[u]) continue;
            for(auto &edge : adj[u]){
                int v = edge.first;
                long long cost = edge.second;
                if(dist[u] + cost < dist[v]){
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n-1] == LLONG_MAX ? -1 : dist[n-1];
    }
};
