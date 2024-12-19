class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> cached(201, vector<vector<int>>(202, vector<int>(202, -1)));

        function<int(int, int, int)> dfs = [&](int i, int left, int right) {
            if (i == n) {
                if (left >= 0 && left == right) {
                    return 1;
                }

                return 0;
            }

            if (cached[i][left + 1][right + 1] != -1) {
                return cached[i][left + 1][right + 1];
            }

            int ret = dfs(i + 1, left, right);
            if (left == -1) {
                ret = (ret + dfs(i + 1, nums[i], right)) % mod;
            } else {
                ret = (ret + dfs(i + 1, gcd(left, nums[i]), right)) % mod;
            }
            if (right == -1) {
                ret = (ret + dfs(i + 1, left, nums[i])) % mod;
            } else {
                ret = (ret + dfs(i + 1, left, gcd(right, nums[i]))) % mod;
            }

            return cached[i][left + 1][right + 1] = ret;
        };

        return dfs(0, -1, -1);
    }
};
// Time Limit Exceeded

class Solution {
    const int mod = 1e9 + 7;
    int cached[200][201][201];
    int dfs(const vector<int>& nums, int i, int left, int right) {
            if (i == nums.size()) {
                if (left && right && left == right) {
                    return 1;
                }

                return 0;
            }

            if (cached[i][left][right] != -1) {
                return cached[i][left][right];
            }

            int ret = dfs(nums, i + 1, left, right);
            ret = (ret + dfs(nums, i + 1, gcd(left, nums[i]), right)) % mod;
            ret = (ret + dfs(nums, i + 1, left, gcd(right, nums[i]))) % mod;

            return cached[i][left][right] = ret;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(cached, -1, sizeof(cached));

        return dfs(nums, 0, 0, 0);
    }
};
// 1178 ms
// 58.04 MB
