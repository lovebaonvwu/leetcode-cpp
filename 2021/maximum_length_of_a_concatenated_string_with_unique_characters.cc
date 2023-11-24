class Solution {
  int ans = 0;

 public:
  int maxLength(vector<string>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
      dfs(arr, i, {});
    }

    return ans;
  }

  void dfs(vector<string>& arr, int idx, unordered_set<char> seen) {
    for (auto c : arr[idx]) {
      if (seen.count(c)) {
        return;
      } else {
        seen.insert(c);
      }
    }

    ans = max(ans, (int)seen.size());

    for (int i = idx + 1; i < arr.size(); ++i) {
      dfs(arr, i, seen);
    }
  }
};
// Runtime: 276 ms, faster than 35.40%
// Memory Usage: 56.7 MB, less than 5.06%

class Solution {
  int ans = 0;

 public:
  int maxLength(vector<string>& arr) {
    dfs(arr, 0, "");

    return ans;
  }

  void dfs(vector<string>& arr, int idx, string s) {
    unordered_set<char> st(s.begin(), s.end());

    if (st.size() != s.size()) {
      return;
    }

    ans = max(ans, (int)s.size());

    for (int i = idx; i < arr.size(); ++i) {
      dfs(arr, i, s + arr[i]);
    }
  }
};
// Runtime: 676 ms, faster than 12.18%
// Memory Usage: 91.1 MB, less than 5.06%