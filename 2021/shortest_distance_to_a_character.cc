class Solution {
 public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> ans(S.size(), S.size());

    int prev = -1;
    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == C) {
        prev = i;
      }

      if (prev != -1) {
        ans[i] = i - prev;
      }
    }

    prev = -1;
    for (int i = S.size() - 1; i >= 0; --i) {
      if (S[i] == C) {
        prev = i;
      }

      if (prev != -1) {
        ans[i] = min(ans[i], prev - i);
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 56.47%
// Memory Usage: 8.9 MB, less than 100.00%

class Solution {
 public:
  vector<int> shortestToChar(string S, char C) {
    vector<int> vec;

    for (int i = 0; i < S.size(); ++i) {
      if (S[i] == C) {
        vec.push_back(i);
      }
    }

    vector<int> ans;

    for (int i = 0; i < S.size(); ++i) {
      int sht = INT_MAX;

      for (int j = 0; j < vec.size(); ++j) {
        if (abs(i - vec[j]) < sht) {
          sht = abs(i - vec[j]);
        }
      }

      ans.push_back(sht);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 97.21%
// Memory Usage: 8.7 MB, less than 100.00%