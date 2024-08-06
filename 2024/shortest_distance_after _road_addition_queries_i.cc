class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> g(n);
        for (int i = 0; i < n - 1; ++i) {
            g[i].push_back(i + 1);
        }
        vector<int> ans;

        for (auto& query : queries) {
            g[query[0]].push_back(query[1]);

            vector<int> visited(n);
            queue<int> q;
            q.push(0);
            visited[0] = true;

            int step = 0;
            bool find = false;
            while (!q.empty()) {
                int cnt = q.size();

                while (cnt-- > 0) {
                    auto cur = q.front();
                    q.pop();

                    if (cur == n - 1) {
                        ans.push_back(step);
                        find = true;
                        break;
                    }

                    for (auto& next : g[cur]) {
                        if (!visited[next]) {
                            q.push(next);
                            visited[next] = true;
                        }
                    }
                }

                if (find) {
                    break;
                }

                ++step;
            }
        }

        return ans;
    }
};
// 187 ms
// 139.52 MB

