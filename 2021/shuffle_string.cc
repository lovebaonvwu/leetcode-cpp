class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    string ans = s;

    for (int i = 0; i < s.size(); ++i) {
      ans[indices[i]] = s[i];
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 12.76%
// Memory Usage: 15.2 MB, less than 84.12%

class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    for (int i = 0; i < s.size(); ++i) {
      while (indices[i] != i) {
        swap(s[i], s[indices[i]]);
        swap(indices[i], indices[indices[i]]);
      }
    }

    return s;
  }
};
// Runtime: 36 ms, faster than 12.76%
// Memory Usage: 15.2 MB, less than 78.94%