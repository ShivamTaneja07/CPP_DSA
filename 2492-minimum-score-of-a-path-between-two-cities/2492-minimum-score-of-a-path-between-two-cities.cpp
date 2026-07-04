class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.push(1);
        vis[1] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &[next, dist] : adj[node]) {
                ans = min(ans, dist);

                if (!vis[next]) {
                    vis[next] = true;
                    q.push(next);
                }
            }
        }

        return ans;
    }
};