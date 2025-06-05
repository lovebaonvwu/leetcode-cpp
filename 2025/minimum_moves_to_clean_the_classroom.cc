class Solution
{
    int cached[21][21][1 << 10];

public:
    int minMoves(vector<string> &classroom, int energy)
    {
        int m = classroom.size();
        int n = classroom[0].size();

        int L = 0;
        pair<int, int> S;
        int label = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (classroom[i][j] == 'L')
                {
                    ++L;
                    classroom[i][j] = label + '0';
                    ++label;
                }
                else if (classroom[i][j] == 'S')
                {
                    S.first = i;
                    S.second = j;
                }
            }
        }

        int mask = (1 << L) - 1;

        queue<array<int, 5>> q;
        q.push({S.first, S.second, energy, 0, 0});

        memset(cached, -1, sizeof(cached));

        int dirs[] = {-1, 0, 1, 0, -1};

        while (!q.empty())
        {
            auto [y, x, e, curr_m, step] = q.front();
            q.pop();

            if (e < 0)
            {
                continue;
            }

            if (e <= cached[y][x][curr_m])
            {
                continue;
            }

            if (curr_m == mask)
            {
                return step;
            }

            cached[y][x][curr_m] = e;

            for (int k = 0; k < 4; ++k)
            {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];
                int next_e = e - 1;
                int next_m = curr_m;

                if (dy < 0 || dy == m || dx < 0 || dx == n || classroom[dy][dx] == 'X' || e == 0)
                {
                    continue;
                }

                if (classroom[dy][dx] >= '0' && classroom[dy][dx] <= '9')
                {
                    next_m |= (1 << (classroom[dy][dx] - '0'));
                }
                else if (classroom[dy][dx] == 'R')
                {
                    next_e = energy;
                }

                q.push({dy, dx, next_e, next_m, step + 1});
            }
        }

        return -1;
    }
};
// Time: O(m * n * 2^L)
// Space: O(m * n * 2^L) for the cached array