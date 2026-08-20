class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n  = graph.size();
        vector<int> in(n,0);
        vector<list<int>> aj(n);
        for(int i = 0 ; i < n ; i++){
            for(int &x : graph[i]){
                aj[x].push_back(i);
                in[i]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) if(in[i] == 0) q.push(i);
        while(!q.empty()){
            int now = q.front();
            ans.push_back(now);
            q.pop();
            for(int &ngbr : aj[now]){
                in[ngbr]--;
                if(in[ngbr] == 0) q.push(ngbr);
            }
        }
    sort(ans.begin(),ans.end()) ;
    return ans;
    }
};