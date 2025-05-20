class Solution
{
    using TP3 = tuple<int, int, int>;

public:
    int minMoves(vector<string> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<char, vector<pair<int, int>>> port;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '.' || matrix[i][j] == '#')
                {
                    continue;
                }

                port[matrix[i][j]].push_back({i, j});
            }
        }

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int dirs[] = {-1, 0, 1, 0, -1};

        priority_queue<TP3, vector<TP3>, greater<TP3>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        unordered_set<char> used;

        while (!pq.empty())
        {
            auto [cur, y, x] = pq.top();
            pq.pop();

            if (y == m - 1 && x == n - 1)
            {
                return cur;
            }

            if (isupper(matrix[y][x]) && used.find(matrix[y][x]) == used.end())
            {
                used.insert(matrix[y][x]);

                for (auto &[yy, xx] : port[matrix[y][x]])
                {
                    if (cur < dist[yy][xx])
                    {
                        dist[yy][xx] = cur;
                        pq.push({cur, yy, xx});
                    }
                }
            }

            for (int k = 0; k < 4; ++k)
            {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == m || dx < 0 || dx == n || matrix[dy][dx] == '#')
                {
                    continue;
                }

                if (cur + 1 < dist[dy][dx])
                {
                    dist[dy][dx] = cur + 1;
                    pq.push({cur + 1, dy, dx});
                }
            }
        }

        return -1;
    }
};
// Time: O(MNlog(MN))
// Space: O(MN)
