class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n+1,0);
        vector<list<int>> aj(n+1);
        for(auto & e : prerequisites ){
            int u = e[0];
            int v = e[1];
            aj[v].push_back(u);
            in[u]++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++) if(in[i] == 0) q.push(i);
        vector<int> ans;
        while(!q.empty()){
            int now = q.front();
            q.pop();
            ans.push_back(now);
            for(int &ngbr : aj[now]){
                in[ngbr]--;
                if(in[ngbr] == 0) q.push(ngbr);
            }
        }
    return ans.size() == n ? ans : vector<int>{};
    }
};