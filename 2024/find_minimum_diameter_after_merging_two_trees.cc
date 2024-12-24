class Solution {
    int topologicalSort(const vector<vector<int>>& g, vector<int> deg) {
        int ret = 0;
        queue<int> q;
        for (int i = 0; i < deg.size(); ++i) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }

        int left = 0;
        while (!q.empty()) {
            int cnt = q.size();
            left = cnt;

            while (cnt-- > 0) {
                int node = q.front();
                q.pop();
                --deg[node];

                for (auto neighbor : g[node]) {
                    --deg[neighbor];
                    if (deg[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }

            ++ret;
        }

        if (left == 2) {
            return 2 * (ret - 1) + 1;
        }

        return (ret - 1) * 2;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<int> deg1(n);
        vector<vector<int>> g1(n);
        for (auto& e : edges1) {
            ++deg1[e[0]];
            ++deg1[e[1]];
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }

        vector<int> deg2(m);
        vector<vector<int>> g2(m);
        for (auto& e : edges2) {
            ++deg2[e[0]];
            ++deg2[e[1]];
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }

        int d1 = topologicalSort(g1, deg1);
        int d2 = topologicalSort(g2, deg2);

        return max({d1, d2, ((d1 + 1) / 2 + (d2 + 1) / 2 + 1) });
    }
};
// 270 ms
// 299.48 MB