class Solution 
{
    int ans = INT_MAX;
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        vector<int> used(bikes.size());
        dfs(workers, bikes, used, 0, 0);

        return ans; 
    }

    void dfs(
        vector<vector<int>>& workers, 
        vector<vector<int>>& bikes, 
        vector<int> used,
        int cur,
        int sum)
    {
        if (cur == workers.size())
        {
            ans = min(ans, sum);
            return;
        }

        for (int i = 0; i < bikes.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = 1;
                auto& worker = workers[cur];
                auto& bike = bikes[i];
                sum += abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
                dfs(workers, bikes, used, cur + 1, sum);
                used[i] = 0;
            }
        }
    }
};
// Time Limit Exceeded

class Solution 
{
    int ans = INT_MAX;
    int used[10];
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        dfs(workers, bikes, 0, 0);

        return ans; 
    }

    void dfs(
        vector<vector<int>>& workers, 
        vector<vector<int>>& bikes, 
        int cur,
        int sum)
    {
        if (cur >= workers.size())
        {
            ans = min(ans, sum);
            return;
        }

        if (sum >= ans)
        {
            return;
        }

        for (int i = 0; i < bikes.size(); ++i)
        {
            if (!used[i])
            {
                used[i] = 1;
                auto& worker = workers[cur];
                auto& bike = bikes[i];
                dfs(workers, bikes, cur + 1, sum + abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]));
                used[i] = 0;
            }
        }
    }
};
// Runtime 1572 ms
// Memory 8.2 MB
// 2022.12.18 at 奥盛大厦

class Solution 
{
    int memo[1024];
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
        memset(memo, -1, sizeof(memo));
        return dfs(workers, bikes, 0, 0);
    }

    int dfs(
        vector<vector<int>>& workers, 
        vector<vector<int>>& bikes, 
        int cur,
        int mask)
    {
        if (cur >= workers.size())
        {
            return 0;
        }

        if (memo[mask] != -1)
        {
            return memo[mask];
        }

        int res = INT_MAX;
        for (int i = 0; i < bikes.size(); ++i)
        {
            if (!(mask & (1 << i)))
            {
                auto& worker = workers[cur];
                auto& bike = bikes[i];

                int dist = abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
                res = min(res, dist + dfs(workers, bikes, cur + 1, mask | (1 << i)));
            }
        }

        return memo[mask] = res;
    }
};
// Runtime 4 ms
// Memory 8.2 MB
// 2022.12.18 at 奥盛大厦