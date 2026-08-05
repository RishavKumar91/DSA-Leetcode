class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj, vector<char>& vis) {
        queue<int> q;
        q.push(src);
        vis[src] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto &e : invocations)
            adj[e[0]].push_back(e[1]);

        vector<char> vis(n, 0);
        bfs(k, adj, vis);

        bool removable = true;

        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {
                removable = false;
                break;
            }
        }

        vector<int> ans;

        if (!removable) {
            for (int i = 0; i < n; i++)
                ans.push_back(i);
        } else {
            for (int i = 0; i < n; i++)
                if (!vis[i])
                    ans.push_back(i);
        }

        return ans;
    }
};