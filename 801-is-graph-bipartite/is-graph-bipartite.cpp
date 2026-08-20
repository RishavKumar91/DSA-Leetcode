class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n+1,-1);
        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                queue<int> q;
                color[i] = 0 ;
                q.push(i);
                while(!q.empty()){
                    int now = q.front();
                    q.pop();
                    for(int ngbr : graph[now]){
                        if(color[ngbr] == -1){
                            color[ngbr] = !color[now];
                            q.push(ngbr);
                        }
                        else if(color[ngbr] == color[now]) return 0;
                    }
                }
            }
        }
    return 1;
    }
};