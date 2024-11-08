class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> cnt(n);
            for (int k = i; k < m; ++k) {
                int rollingSum = 0;
                for (int j = 0; j < n; ++j) {
                    if (mat[k][j] == 1) {
                        ++cnt[j];
                    } else {
                        cnt[j] = 0;
                    }

                    if (cnt[j] == k - i + 1) {
                        ++rollingSum;
                    } else {
                        rollingSum = 0;
                    }

                    ans += rollingSum;
                }
            }
        }

        return ans;
    }
};
// 39 ms
// 18.11 MB

