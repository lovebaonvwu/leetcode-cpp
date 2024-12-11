class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        set<pair<int, int>> st;
        for (auto& p : points) {
            st.insert({p[0], p[1]});
        }

        sort(begin(points), end(points));

        function<bool(int, int, int, int)> valid = [&](int x0, int y0, int x1, int y1) -> bool {
            for (auto& p : points) {
                int x = p[0];
                int y = p[1];
                if ((x == x0 && y == y0) || (x == x1 && y == y1)) {
                    continue;
                }

                if ((x == x0 && y == y1) || (x == x1 && y == y0)) {
                    continue;
                }

                if (x >= x0 && x <= x1 && y >= y0 && y <= y1) {
                    return false;
                }
            }

            return true;
        };

        int ans = -1;
        int n = points.size();
        for (int i = 0; i < n; ++i) {
            int x0 = points[i][0];
            int y0 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[j][0];
                int y1 = points[j][1];

                if (x0 >= x1 || y0 >= y1) {
                    continue;
                }

                if (st.count({x0, y1}) && st.count({x1, y0}) && valid(x0, y0, x1, y1)) {
                    ans = max(ans, (abs(x1 - x0) * abs(y1 - y0)));
                }
            }
        }

        return ans;
    }
};
// 4 ms
// 32.76 MB