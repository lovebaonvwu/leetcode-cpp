class Solution {
    long long dfs(int i, int j, vector<int>& robot, vector<int>& factories, vector<vector<long long>>& cached) {
            if (i == robot.size()) {
                return 0;
            }

            if (j == factories.size()) {
                return 1e12;
            }

            if (cached[i][j] != -1) {
                return cached[i][j];
            }

            long long ret = abs(factories[j] - robot[i]) + dfs(i + 1, j + 1, robot, factories, cached);
            ret = min(ret, dfs(i, j + 1, robot, factories, cached));

            return cached[i][j] = ret;
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        vector<int> factories;
        for (auto f : factory) {
            for (int i = 0; i < f[1]; ++i) {
                factories.push_back(f[0]);
            }
        }

        int m = robot.size();
        int n = factories.size();
        vector<vector<long long>> cached(m, vector<long long>(n, -1));

        return dfs(0, 0, robot, factories, cached);
    }
};
// 146 ms
// 68 MB