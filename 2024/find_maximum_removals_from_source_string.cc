class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        unordered_set<int> st(begin(targetIndices), end(targetIndices));

        int m = source.size();
        int n = pattern.size();
        
        vector<vector<int>> cached(m, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int s, int p) -> int {
            if (s == m) {
                return p < n ? INT_MIN : 0;
            }

            if (p == n) {
                int ret = 0;
                for (; s < m; ++s) {
                    if (st.count(s)) {
                        ++ret;
                    }
                }

                return ret;
            }

            if (cached[s][p] != -1) {
                return cached[s][p];
            }

            int ret = INT_MIN;
            ret = max(ret, dfs(s + 1, p));

            if (source[s] == pattern[p]) {
                ret = max(ret, dfs(s + 1, p + 1));
            }

            if (st.count(s)) {
                ret = max(ret, dfs(s + 1, p) + 1);
            }

            return cached[s][p] = ret;
        };

        return dfs(0, 0);
    }
};
// 525 ms
// 95.08 MB

