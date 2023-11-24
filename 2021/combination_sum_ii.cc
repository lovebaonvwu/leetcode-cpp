class Solution {
  set<vector<int>> st;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return vector<vector<int>>(st.begin(), st.end());
  }

  void dfs(vector<int>& c, vector<int> p, int start, int target) {
    if (target == 0) {
      st.insert(p);
      return;
    }

    for (int i = start; i < c.size(); ++i) {
      p.push_back(c[i]);

      dfs(c, p, i + 1, target - c[i]);

      p.pop_back();
    }
  }
};
// Time Limit Exceeded

class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return ans;
  }

  void dfs(vector<int>& c, vector<int> p, int start, int target) {
    if (target == 0) {
      ans.push_back(p);
      return;
    }

    for (int i = start; i < c.size();) {
      p.push_back(c[i]);

      dfs(c, p, i + 1, target - c[i]);

      p.pop_back();

      ++i;
      while (i > 0 && i < c.size() && c[i] == c[i - 1]) {
        ++i;
      }
    }
  }
};
// Time Limit Exceeded

class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return ans;
  }

  void dfs(vector<int>& c, vector<int> p, int start, int target) {
    if (target < 0) {
      return;
    }

    if (target == 0) {
      ans.push_back(p);
      return;
    }

    for (int i = start; i < c.size();) {
      p.push_back(c[i]);

      dfs(c, p, i + 1, target - c[i]);

      p.pop_back();

      ++i;
      while (i > 0 && i < c.size() && c[i] == c[i - 1]) {
        ++i;
      }
    }
  }
};
// Runtime: 52 ms, faster than 25.65%
// Memory Usage: 16.3 MB, less than 21.47%

class Solution {
  set<vector<int>> st;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    dfs(candidates, {}, 0, target);

    return vector<vector<int>>(st.begin(), st.end());
  }

  void dfs(vector<int>& c, vector<int> p, int start, int target) {
    if (target < 0) {
      return;
    }

    if (target == 0) {
      st.insert(p);
      return;
    }

    for (int i = start; i < c.size(); ++i) {
      p.push_back(c[i]);

      dfs(c, p, i + 1, target - c[i]);

      p.pop_back();
    }
  }
};
// Runtime: 556 ms, faster than 5.58%
// Memory Usage: 80.1 MB, less than 6.54%