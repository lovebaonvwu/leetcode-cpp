class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<vector<vector<int>>> cached(n, vector<vector<int>>(op1 + 1, vector<int>(op2 + 1, -1)));

        function<int(int, int, int)> dfs = [&](int i, int op1, int op2) -> int {
            if (i == n) {
                return 0;
            }

            if (cached[i][op1][op2] != -1) {
                return cached[i][op1][op2];
            }

            int ret = INT_MAX;
            ret = min(ret, nums[i] + dfs(i + 1, op1, op2));

            if (op1 > 0) {
                ret = min(ret, (nums[i] + 1) / 2 + dfs(i + 1, op1 - 1, op2));
                if (op2 > 0 && (nums[i] + 1) / 2 >= k) {
                    ret = min(ret, (nums[i] + 1) / 2 - k + dfs(i + 1, op1 - 1, op2 - 1));
                }
            }

            if (op2 > 0 && nums[i] >= k) {
                ret = min(ret, nums[i] - k + dfs(i + 1, op1, op2 - 1));
                if (op1 > 0) {
                    ret = min(ret, (nums[i] - k + 1) / 2 + dfs(i + 1, op1 - 1, op2 - 1));
                }
            }

            return cached[i][op1][op2] = ret;
        };

        return dfs(0, op1, op2);
    }
};
// 284 ms
// 86.21 MB

