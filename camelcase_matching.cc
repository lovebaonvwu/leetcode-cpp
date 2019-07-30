class Solution {
 public:
  vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> ans(queries.size());

    for (int i = 0; i < queries.size(); ++i) {
      int p1, p2;
      for (p1 = 0, p2 = 0; p1 < queries[i].size(); ++p1) {
        if (queries[i][p1] == pattern[p2]) {
          ++p2;
        } else if (isupper(queries[i][p1])) {
          p2 = -1;
          break;
        }
      }

      ans[i] = p2 == pattern.size() ? true : false;
    }

    return ans;
  }
};  // 4ms