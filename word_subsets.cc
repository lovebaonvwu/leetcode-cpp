class Solution {
 public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> ans;

    for (auto& a : A) {
      vector<int> alpha(26);
      for (int i = 0; i < a.size(); ++i) {
        ++alpha[a[i] - 'a'];
      }

      int cnt = 0;
      for (auto& b : B) {
        vector<int> tmp(alpha);

        bool isSubset = true;
        for (int i = 0; i < b.size(); ++i) {
          --tmp[b[i] - 'a'];
          if (tmp[b[i] - 'a'] < 0) {
            isSubset = false;
            break;
          }
        }

        if (!isSubset) {
          break;
        }

        ++cnt;
      }

      if (cnt == B.size()) {
        ans.push_back(a);
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<int> alpha(26);

    for (auto& w : B) {
      vector<int> tmp(26);

      for (auto c : w) {
        ++tmp[c - 'a'];
      }

      for (int i = 0; i < 26; ++i) {
        alpha[i] = max(alpha[i], tmp[i]);
      }
    }

    vector<string> ans;

    for (auto& w : A) {
      vector<int> tmp(26);

      for (auto c : w) {
        ++tmp[c - 'a'];
      }

      int i = 0;
      for (; i < 26; ++i) {
        if (tmp[i] < alpha[i]) {
          break;
        }
      }

      if (i == 26) {
        ans.push_back(w);
      }
    }

    return ans;
  }
};
// Runtime: 172 ms, faster than 70.74%
// Memory Usage: 102.3 MB, less than 47.27%