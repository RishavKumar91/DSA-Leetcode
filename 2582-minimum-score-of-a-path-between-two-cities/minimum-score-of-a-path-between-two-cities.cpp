class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<list<pair<int,int>>> aj(n+1);
        for(int i = 0 ; i < roads.size() ; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            aj[u].push_back({v,w});
            aj[v].push_back({u,w});
        }
        vector<bool> visit(n+1,0);
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;
        visit[1] = 1;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            
            for(auto &ngbr : aj[now]){
                ans = min(ans, ngbr.second);
                if(!visit[ngbr.first]){
                    ans = min(ans,ngbr.second);
                    visit[ngbr.first] = 1;
                    q.push(ngbr.first);
                }
            }
        }
    return ans;
    }
};