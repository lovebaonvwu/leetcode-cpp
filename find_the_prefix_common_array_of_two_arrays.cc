class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    unordered_set<int> C;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      C.insert(A[i]);
      int cnt = 0;

      for (int j = 0; j <= i; ++j) {
        if (C.find(B[j]) != C.end()) {
          ++cnt;
        }
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// Runtime 78 ms
// Memory 83.8 MB

class Solution {
 public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int cnt[51] = {0};
    vector<int> ans;

    for (int i = 0, c = 0; i < A.size(); ++i) {
      if (++cnt[A[i]] == 2) {
        ++c;
      }

      if (++cnt[B[i]] == 2) {
        ++c;
      }

      ans.push_back(c);
    }

    return ans;
  }
};
// Runtime 47 ms
// Memory 81.3 MB