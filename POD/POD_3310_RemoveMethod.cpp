#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& suspicious) {
        suspicious[node] = 1;

        for (int nei : adj[node]) {
            if (!suspicious[nei]) {
                dfs(nei, adj, suspicious);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        // Build graph
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Find all suspicious methods
        vector<int> suspicious(n, 0);
        dfs(k, adj, suspicious);

        // Check if any outside method invokes a suspicious method
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Remove suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};



//######### Optimized Code #########//

class Solution {
    static constexpr int MAXN = 100000;
    static constexpr int MAXM = 200000;

    struct Edge {
        int to;
        int next;
    };

    static Edge edges[MAXM];
    static int head[MAXN];
    static uint8_t vis[MAXN];
    static int edgeCount;

    // Add a directed edge u -> v
    static inline void addEdge(int u, int v) {
        edges[edgeCount] = {v, head[u]};
        head[u] = edgeCount++;
    }

    // DFS to mark all suspicious methods
    static void dfs(int u) {
        vis[u] = 1;

        for (int idx = head[u]; idx != -1; idx = edges[idx].next) {
            int v = edges[idx].to;
            if (!vis[v]) {
                dfs(v);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        edgeCount = 0;

        // Initialize only required portion
        memset(head, -1, n * sizeof(int));
        memset(vis, 0, n);

        // Build graph
        for (auto &e : invocations) {
            addEdge(e[0], e[1]);
        }

        // Find all suspicious methods
        dfs(k);

        // Check if any non-suspicious method calls a suspicious one
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

