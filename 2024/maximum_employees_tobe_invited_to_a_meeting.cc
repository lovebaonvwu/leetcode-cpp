class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();

        vector<int> ind(n);
        for (int i = 0; i < n; ++i) {
            ++ind[favorite[i]];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }

        vector<int> depth(n, 1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            int next = favorite[cur];
            depth[next] = max(depth[next], depth[cur] + 1);
            --ind[next];

            if (ind[next] == 0) {
                q.push(next);
            }
        }

        int longestCycle = 0;
        int twoNodesWithlink = 0;

        for (int i = 0; i < n; ++i) {
            if (ind[i] == 0) {
                continue;
            }

            int count = 0;
            int cur = i;
            while (ind[cur] != 0) {
                ind[cur] = 0;
                ++count;
                cur = favorite[cur];
            }

            if (count == 2) {
                twoNodesWithlink += depth[i] + depth[favorite[i]];
            } else {
                longestCycle = max(longestCycle, count);
            }
        }

        return max(longestCycle, twoNodesWithlink);
    }
};
// 10 ms
// 93.15 MB
