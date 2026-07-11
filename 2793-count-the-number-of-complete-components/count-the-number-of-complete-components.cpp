class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<list<int>> aj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int u  = edges[i][0];
            int v  = edges[i][1];
            aj[u].push_back(v);
            aj[v].push_back(u);
        }
        int ans = 0;
        vector<int> visit(n,0);
        for(int i = 0 ; i < n ; i++){
            if(visit[i] == 1) continue;
            visit[i]  = 1;
            bool flag = 1;
            int sz = aj[i].size();
            queue<int> q;
            q.push(i);
            unordered_set<int> s;
            s.insert(i);
            while(!q.empty()){
                int top = q.front();
                q.pop();
                if(sz != aj[top].size()){flag = 0 ; }
                for(auto &ngbr : aj[top]){
                    if(visit[ngbr]==1) continue;
                    s.insert(ngbr);
                    visit[ngbr] = 1;
                    q.push(ngbr);
                }
            }
        if(sz != s.size()-1) flag = 0;
        if(flag) ans++;
        }
    return ans;
    }
};