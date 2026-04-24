class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mh;
        vector<list<pair<int,int>>> aj(n+1);
        for(int i = 0 ;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            aj[u].push_back({v,w});
        }
        vector<int> ans(n+1,INT_MAX);
        ans[k] = 0;
        mh.push({0,k});
        while(!mh.empty()){
            int wgt = mh.top().first;
            int nownode = mh.top().second;
            
            mh.pop();
            if (wgt > ans[nownode]) continue;
            for(auto &ngbr: aj[nownode]){
                if(ngbr.second + wgt < ans[ngbr.first]){
                    ans[ngbr.first] = ngbr.second + wgt ;
                    mh.push({ngbr.second + wgt,ngbr.first});
                }
            }
        }
        int maxx = INT_MIN;
        for(int i = 1;i<n+1;i++) {
            if(ans[i]==INT_MAX) return -1;
            maxx = max(maxx,ans[i]);
            }
    return maxx;
    }
};