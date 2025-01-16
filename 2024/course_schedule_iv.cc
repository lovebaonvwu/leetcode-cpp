class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mp;
        for (auto& p : prerequisites) {
            mp[p[0]].push_back(p[1]);
        }

        vector<vector<int>> g(numCourses, vector<int>(numCourses));

        for (int i = 0; i < numCourses; ++i) {
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                g[i][cur] = true;

                for (auto& neighbor : mp[cur]) {
                    if (!g[i][neighbor]) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(g[q[0]][q[1]]);
        }

        return ans;
    }
};
// 119 ms
// 77.13 MB
