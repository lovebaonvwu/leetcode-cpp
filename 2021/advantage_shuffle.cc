class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());

    int n = A.size();

    vector<int> ans(n, -1);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (A[j] > B[i]) {
          ans[i] = A[j];

          A[j] = -1;
          break;
        }
      }
    }

    vector<int> left;
    for (int i = 0; i < n; ++i) {
      if (A[i] > -1) {
        left.push_back(A[i]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (ans[i] < 0) {
        ans[i] = left.back();
        left.pop_back();
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> advantageCount(vector<int>& A, vector<int>& B) {
    vector<int> ans(A.size());

    multiset<int> s(A.begin(), A.end());

    for (int i = 0; i < B.size(); ++i) {
      auto it = *s.rbegin() > B[i] ? s.upper_bound(B[i]) : s.begin();
      ans[i] = *it;

      s.erase(it);
    }

    return ans;
  }
};
// Runtime: 96 ms, faster than 76.58%
// Memory Usage: 41 MB, less than 43.24%