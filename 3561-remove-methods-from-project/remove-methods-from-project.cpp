class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<list<int>> aj(n+1);
        for(auto &invocation : invocations){
            aj[invocation[0]].push_back(invocation[1]);
        }
        vector<int>  anss ;
        vector<bool> visit(n+1,0);
        queue<int> q;
        visit[k] = 1; q.push(k);
        while(!q.empty()){
            int now = q.front(); q.pop();
            // ans[now] = 0;
            for(int & ngbr :  aj[now]){
                if(visit[ngbr] == 0){
                    q.push(ngbr);
                    visit[ngbr] = 1;
                }
            }
        }
        for(auto &invocation : invocations){
            if(visit[invocation[0]] == 0 && visit[invocation[1]] ==1 ){
                visit.assign(n+1,0);
                break;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(visit[i] == 0 ) anss.push_back(i);
        }
        return anss;
    }
};