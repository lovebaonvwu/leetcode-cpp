class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return ans;
  }

  void dfs(vector<int>& c, vector<int> comb, int start, int target) {
    if (c[start] > target) {
      return;
    }

    for (int i = start; i < c.size(); ++i) {
      comb.push_back(c[i]);

      if (target - c[i] == 0) {
        ans.push_back(comb);
        break;
      }

      dfs(c, comb, i, target - c[i]);

      comb.pop_back();
    }
  }
};
// Runtime: 16 ms, faster than 54.58%
// Memory Usage: 12.8 MB, less than 44.62%

class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return ans;
  }

  void dfs(vector<int>& c, vector<int> comb, int start, int target) {
    if (target == 0) {
      ans.push_back(comb);
      return;
    }

    for (int i = start; i < c.size() && c[i] <= target; ++i) {
      comb.push_back(c[i]);

      dfs(c, comb, i, target - c[i]);

      comb.pop_back();
    }
  }
};
// Runtime: 20 ms, faster than 47.56%
// Memory Usage: 12.7 MB, less than 45.00%