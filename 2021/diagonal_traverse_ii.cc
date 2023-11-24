class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> ans;

    size_t m = nums.size();
    size_t n = nums[0].size();
    size_t max_col = 0;

    for (int i = 0; i < m; ++i) {
      max_col = max(max_col, nums[i].size());
      for (int j = 0; j <= i; ++j) {
        if (j < nums[i - j].size()) {
          ans.push_back(nums[i - j][j]);
        }
      }
    }

    for (int j = 1; j < max_col; ++j) {
      for (int i = m - 1, k = 0; i >= 0; --i, ++k) {
        if (j + k < nums[i].size()) {
          ans.push_back(nums[i][j + k]);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<vector<int>> diagonals;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums[i].size(); ++j) {
        if (i + j == diagonals.size()) {
          diagonals.push_back({});
        }

        diagonals[i + j].emplace_back(nums[i][j]);
      }
    }

    vector<int> ans;
    for (auto& d : diagonals) {
      ans.insert(ans.end(), d.rbegin(), d.rend());
    }

    return ans;
  }
};
// Runtime: 528 ms, faster than 83.54%
// Memory Usage: 89.5 MB, less than 100.00%