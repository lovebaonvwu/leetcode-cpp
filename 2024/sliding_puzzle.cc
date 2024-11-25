class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = 2;
        int n = 3;
        string start;
        string goal;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                start += (board[i][j] + '0');
                goal += ((i * n + j + 1) % (m * n) + '0');
            }
        }

        if (start == goal) {
            return 0;
        }

        queue<string> q;
        q.push(start);

        set<string> visited;
        visited.insert(start);

        int ans = 0;
        int dirs[] = {-1, 0, 1, 0, -1};

        while (!q.empty()) {

            int cnt = q.size();

            while (cnt-- > 0) {
                auto current = q.front();
                q.pop();

                if (current == goal) {
                    return ans;
                }

                int p = current.find('0');
                int y = p / n;
                int x = p % n;

                for (int k = 0; k < 4; ++k) {
                    int dy = y + dirs[k];
                    int dx = x + dirs[k + 1];

                    if (dy < 0 || dy == m || dx < 0 || dx == n) {
                        continue;
                    }

                    int pp = dy * n + dx;
                    string tmp(current);
                    swap(tmp[p], tmp[pp]);

                    if (visited.count(tmp)) {
                        continue;
                    }

                    visited.insert(tmp);

                    q.push(tmp);
                }
            }

            ++ans;
        }

        return -1;
    }
};
// 4 ms
// 10.80 MB