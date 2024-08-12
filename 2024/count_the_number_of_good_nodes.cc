class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ans = 0;

        function<int(int, int)> dfs = [&](int cur, int parent) -> int {
            vector<int> cnt;
            for (auto child : g[cur]) {
                if (child != parent) {
                    cnt.push_back(dfs(child, cur));
                }
            }
            
            bool allSame = true;
            int ret = 1 + (cnt.size() > 0 ? cnt[0] : 0);
            for (int i = 1; i < cnt.size(); ++i) {
                if (cnt[i] != cnt[i - 1]) {
                    allSame = false;
                }

                ret += cnt[i];
            }

            if (allSame) {
                ++ans;
            }

            return ret;
        };

        dfs(0, -1);

        return ans;
    }
};
// 1517 ms
// 453.22 MB