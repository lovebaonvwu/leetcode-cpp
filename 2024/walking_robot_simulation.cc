class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        for (auto& obstacle : obstacles) {
            rows[obstacle[1]].push_back(obstacle[0]);
            cols[obstacle[0]].push_back(obstacle[1]);
        }

        for (auto& [_, v] : rows) {
            sort(begin(v), end(v));
        }

        for (auto& [_, v] : cols) {
            sort(begin(v), end(v));
        }

        int ans = 0;
        int y = 0;
        int x = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        int k = 0;
        for (auto& c : commands) {
            if (c == -1) {
                k += 1;
                k %= 4;
            } else if (c == -2) {
                k += 3;
                k %= 4;
            } else {
                if (k == 0) {
                    int dy = y + c;

                    if (cols.find(x) == cols.end()) {
                        y = dy;
                    } else {
                        auto it = upper_bound(begin(cols[x]), end(cols[x]), y);
                        if (it == cols[x].end()) {
                            y = dy;
                        } else {
                            y = min(dy, *it - 1);
                        }
                    }
                } else if (k == 1) {
                    int dx = x + c;

                    if (rows.find(y) == rows.end()) {
                        x = dx;
                    } else {
                        auto it = upper_bound(begin(rows[y]), end(rows[y]), x);
                        if (it == rows[y].end()) {
                            x = dx;
                        } else {
                            x = min(dx, *it - 1);
                        }
                    }
                } else if (k == 2) {
                    int dy = y - c;

                    if (cols.find(x) == cols.end()) {
                        y = dy;
                    } else {
                        auto it = lower_bound(begin(cols[x]), end(cols[x]), y);
                        if (it == cols[x].end()) {
                            y = max(dy, *prev(it) + 1);
                        } else if (it == cols[x].begin()) {
                            y = dy;
                        } else {
                            y = max(dy, *prev(it) + 1);
                        }
                    }
                } else if (k == 3) {
                    int dx = x - c;

                    if (rows.find(y) == rows.end()) {
                        x = dx;
                    } else {
                        auto it = lower_bound(begin(rows[y]), end(rows[y]), x);
                        if (it == rows[y].end()) {
                            x = max(dx, *prev(it) + 1);
                        } else if (it == rows[y].begin()) {
                            x = dx;
                        } else {
                            x = max(dx, *prev(it) + 1);
                        }
                    }
                }
            }

            ans = max(ans, y * y + x * x);
        }

        return ans;
    }
};
// 92 ms
// 47.71 MB

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        for (auto& obstacle : obstacles) {
            rows[obstacle[1]].push_back(obstacle[0]);
            cols[obstacle[0]].push_back(obstacle[1]);
        }

        for (auto& [_, v] : rows) {
            sort(begin(v), end(v));
        }

        for (auto& [_, v] : cols) {
            sort(begin(v), end(v));
        }

        int ans = 0;
        int y = 0;
        int x = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        int k = 0;
        for (auto& c : commands) {
            if (c == -1) {
                k += 1;
                k %= 4;
            } else if (c == -2) {
                k += 3;
                k %= 4;
            } else {
                if (k == 0) {
                    int dy = y + c;

                    if (cols.find(x) == cols.end()) {
                        y = dy;
                    } else {
                        auto it = upper_bound(begin(cols[x]), end(cols[x]), y);
                        if (it == cols[x].end()) {
                            y = dy;
                        } else {
                            y = min(dy, *it - 1);
                        }
                    }
                } else if (k == 1) {
                    int dx = x + c;

                    if (rows.find(y) == rows.end()) {
                        x = dx;
                    } else {
                        auto it = upper_bound(begin(rows[y]), end(rows[y]), x);
                        if (it == rows[y].end()) {
                            x = dx;
                        } else {
                            x = min(dx, *it - 1);
                        }
                    }
                } else if (k == 2) {
                    int dy = y - c;

                    if (cols.find(x) == cols.end()) {
                        y = dy;
                    } else {
                        auto it = lower_bound(begin(cols[x]), end(cols[x]), y);
                        if (it == cols[x].begin()) {
                            y = dy;
                        } else {
                            y = max(dy, *prev(it) + 1);
                        }
                    }
                } else if (k == 3) {
                    int dx = x - c;

                    if (rows.find(y) == rows.end()) {
                        x = dx;
                    } else {
                        auto it = lower_bound(begin(rows[y]), end(rows[y]), x);
                        if (it == rows[y].begin()) {
                            x = dx;
                        } else {
                            x = max(dx, *prev(it) + 1);
                        }
                    }
                }
            }

            ans = max(ans, y * y + x * x);
        }

        return ans;
    }
};
// 92 ms
// 47.64 MB