class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);
        vector<int> total(n, 0);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
            total[e[0]]--;
            total[e[1]]++;
        }

        vector<char> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;

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

        int sum = 0;
        vector<int> rem;
        rem.reserve(n);

        for (int i = 0; i < n; i++) {
            if (vis[i])
                sum += total[i];
            else
                rem.push_back(i);
        }

        if (sum == 0)
            return rem;

        rem.assign(n,0);
        iota(rem.begin(), rem.end(), 0);
        return rem;
    }
};