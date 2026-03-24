class Solution {
public:
void bfs(vector<int> &visited, vector<vector<int>>& isConnected, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[node][j] == 1 && visited[j] == 0) {
                    visited[j] = 1;
                    q.push(j);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int> visited(n,0);
        for(int i =0;i<n;i++){
            if(visited[i]==1) continue;
            bfs(visited,isConnected,i);
            ans++;
        }
    return ans;
    }
};