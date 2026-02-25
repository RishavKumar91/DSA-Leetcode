class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int ans = 0;
        vector<bool> visit(n,0);
        int a =0;
        while(a<n){
            auto [wt,no] = pq.top();
            pq.pop();
            if(visit[no]) continue;
            visit[no] = 1;
            ans+=wt;
            a++;
            for(int i =0;i<n;i++){
                if(!visit[i]){
                int wgttt = abs(points[i][1] - points[no][1] ) + abs(points[i][0] - points[no][0]);
                pq.push({wgttt,i});
                }
            }
        }
    return ans;
    }
};