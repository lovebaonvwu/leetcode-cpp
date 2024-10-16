class Solution {
    enum Creature {N, F, W, E};

public:
    int countWinningSequences(string s) {
        int mod = 1e9 + 7;
        int n = s.size();

        vector<vector<vector<vector<long long>>>> cached(n, vector<vector<vector<long long>>>(4, vector<vector<long long>>(1001, vector<long long>(1001, -1))));

        function<long long(const string&, int, Creature, int, int)> dfs = [&](const string& s, int i, Creature prev, int alice, int bob) -> long long {
            if (i == s.size()) {
                return bob > alice;
            }

            if (cached[i][prev][alice][bob] != -1) {
                return cached[i][prev][alice][bob];
            }

            long long ret = 0;
            if (s[i] == 'F') {
                if (prev == F) {
                    ret += dfs(s, i + 1, W, alice, bob + 1);
                    ret += dfs(s, i + 1, E, alice + 1, bob);
                } else if (prev == W) {
                    ret += dfs(s, i + 1, F, alice, bob);
                    ret += dfs(s, i + 1, E, alice + 1, bob);
                } else if (prev == E) {
                    ret += dfs(s, i + 1, F, alice, bob);
                    ret += dfs(s, i + 1, W, alice, bob + 1);
                } else {
                    ret += dfs(s, i + 1, F, alice, bob);
                    ret += dfs(s, i + 1, W, alice, bob + 1);
                    ret += dfs(s, i + 1, E, alice + 1, bob);
                }
            } else if (s[i] == 'W') {
                if (prev == F) {
                    ret += dfs(s, i + 1, W, alice, bob);
                    ret += dfs(s, i + 1, E, alice, bob + 1);
                } else if (prev == W) {
                    ret += dfs(s, i + 1, F, alice + 1, bob);
                    ret += dfs(s, i + 1, E, alice, bob + 1);
                } else if (prev == E) {
                    ret += dfs(s, i + 1, F, alice + 1, bob);
                    ret += dfs(s, i + 1, W, alice, bob);
                } else {
                    ret += dfs(s, i + 1, F, alice + 1, bob);
                    ret += dfs(s, i + 1, W, alice, bob);
                    ret += dfs(s, i + 1, E, alice, bob + 1);
                }
            } else if (s[i] == 'E') {
                if (prev == F) {
                    ret += dfs(s, i + 1, W, alice + 1, bob);
                    ret += dfs(s, i + 1, E, alice, bob);
                } else if (prev == W) {
                    ret += dfs(s, i + 1, F, alice, bob + 1);
                    ret += dfs(s, i + 1, E, alice, bob);
                } else if (prev == E) {
                    ret += dfs(s, i + 1, F, alice, bob + 1);
                    ret += dfs(s, i + 1, W, alice + 1, bob);
                } else {
                    ret += dfs(s, i + 1, F, alice, bob + 1);
                    ret += dfs(s, i + 1, W, alice + 1, bob);
                    ret += dfs(s, i + 1, E, alice, bob);
                }
            }

            return cached[i][prev][alice][bob] = ret;
        };

        long long ans = dfs(s, 0, N, 0, 0);

        return ans % mod;
    }
};
// Time Limit Exceeded

class Solution {
    enum Creature {N, F, W, E};
    long long dp[1001][2001][4];
    const int mod = 1e9 + 7;

    long long dfs(const string& s, int i, Creature prev, int bob) {
        if (i == s.size()) {
                return bob > 0;
            }

            if (dp[i][bob + 1000][prev] != -1) {
                return dp[i][bob + 1000][prev];
            }

            long long ret = 0;
            if (s[i] == 'F') {
                if (prev == F) {
                    ret = (ret + dfs(s, i + 1, W, bob + 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob - 1)) % mod;
                } else if (prev == W) {
                    ret = (ret + dfs(s, i + 1, F, bob)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob - 1)) % mod;
                } else if (prev == E) {
                    ret = (ret + dfs(s, i + 1, F, bob)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob + 1)) % mod;
                } else {
                    ret = (ret + dfs(s, i + 1, F, bob)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob + 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob - 1)) % mod;
                }
            } else if (s[i] == 'W') {
                if (prev == F) {
                    ret = (ret + dfs(s, i + 1, W, bob)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob + 1)) % mod;
                } else if (prev == W) {
                    ret = (ret + dfs(s, i + 1, F, bob - 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob + 1)) % mod;
                } else if (prev == E) {
                    ret = (ret + dfs(s, i + 1, F, bob - 1)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob)) % mod;
                } else {
                    ret = (ret + dfs(s, i + 1, F, bob - 1)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob + 1)) % mod;
                }
            } else if (s[i] == 'E') {
                if (prev == F) {
                    ret = (ret + dfs(s, i + 1, W, bob - 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob)) % mod;
                } else if (prev == W) {
                    ret = (ret + dfs(s, i + 1, F, bob + 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob)) % mod;
                } else if (prev == E) {
                    ret = (ret + dfs(s, i + 1, F, bob + 1)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob - 1)) % mod;
                } else {
                    ret = (ret + dfs(s, i + 1, F, bob + 1)) % mod;
                    ret = (ret + dfs(s, i + 1, W, bob - 1)) % mod;
                    ret = (ret + dfs(s, i + 1, E, bob)) % mod;
                }
            }

            return dp[i][bob + 1000][prev] = ret;
    }

public:
    int countWinningSequences(string s) {
        int mod = 1e9 + 7;

        memset(dp, -1, sizeof(dp));

        long long ans = dfs(s, 0, N, 0);

        return ans % mod;
    }
};
// 2397 ms
// 78.91 MB