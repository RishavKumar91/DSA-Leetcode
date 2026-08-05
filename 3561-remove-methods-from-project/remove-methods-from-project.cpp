class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> aj(n+1);
        vector<int> total(n+1,0);
        for(auto &invocation : invocations) {
            int u = invocation[0] ,  v = invocation[1];
            total[u]--; total[v]++; aj[u].push_back(v);
        }
        vector<bool> visit(n+1,0);
        queue<int> q; q.push(k); visit[k] = 1;
        while(!q.empty()){
            int now = q.front() ; q.pop(); 
            for(int &ngbr : aj[now]){
                if(!visit[ngbr]) {
                    visit[ngbr] = 1;
                    q.push(ngbr);
                }
            }
        }
        vector<int> ans,anss;
        int totalsum = 0;
        for(int i = 0 ; i < n ; i++){
            cout<<total[i] <<" ,";
            if(visit[i]) totalsum += total[i];
            ans.push_back(i);
            if(visit[i] == 0) anss.push_back(i);
        }
        
        if(totalsum == 0) return anss;
        return ans;
    }
};