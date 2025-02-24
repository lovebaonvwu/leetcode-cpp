class Solution {
    unordered_map<int, int> bobPath;
    int ans = INT_MIN;

    bool findBobPath(const vector<vector<int>>& g, vector<bool>& visited, int node, int time) {
        bobPath[node] = time;
        visited[node] = true;

        if (node == 0) {
            return true;
        }

        for (auto& neighbor : g[node]) {
            if (!visited[neighbor]) {
                if (findBobPath(g, visited, neighbor, time + 1)) {
                    return true;
                }
            }
        }

        bobPath.erase(node);
        return false;
    }

    void findAlicePath(const vector<vector<int>>& g, const vector<int>& amount, vector<bool>& visited, int node, int time, int val) {
        visited[node] = true;

        if (bobPath.find(node) == bobPath.end() || time < bobPath[node]) {
            val += amount[node];
        } else if (bobPath[node] == time) {
            val += amount[node] / 2;
        }

        if (g[node].size() == 1 && node != 0) {
            ans = max(ans, val);
        }

        for(auto& neighbor : g[node]) {
            if (!visited[neighbor]) {
                findAlicePath(g, amount, visited, neighbor, time + 1, val);
            }
        }
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n);
        findBobPath(g, visited, bob, 0);

        visited.assign(n, false);
        findAlicePath(g, amount, visited, 0, 0, 0);

        return ans;
    }
};
// 115 ms
// 152.53 MB