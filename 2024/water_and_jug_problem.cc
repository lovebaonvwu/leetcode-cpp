class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<int> q;
        q.push(0);

        int z = x + y;
        vector<bool> visited(z + 1);
        visited[0] = true;

        int ops[] = {x,-x,-y,y};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            if (cur == target) {
                return true;
            }

            for (auto op : ops) {
                int next = cur + op;
                
                if (next >= 0 && next <= z && !visited[next]) {
                    q.push(next);
                    visited[next] = true;;
                }
            }
        }

        return false;
    }
};
// 0 ms
// 8.15 MB
