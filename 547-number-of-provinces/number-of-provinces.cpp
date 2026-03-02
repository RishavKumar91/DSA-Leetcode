class Solution {
public:
    void dfs(vector<int> &visit ,vector<vector<int>>& isConnected,int start){
        queue<int> q;
        int n = isConnected.size() ;
        q.push(start);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            visit[now]  = 1;
            for(int i =0;i<n;i++){
                if(i!=now && isConnected[now][i] ==  1 && visit[i] == 0) q.push(i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        vector<int> visit(n,0);
        int ans = 0;
        for(int i =0;i<n;i++){
            if (visit[i] == 0){ 
                dfs(visit,isConnected,i);
                ans++;
            }
        }
    return ans;
    }
};