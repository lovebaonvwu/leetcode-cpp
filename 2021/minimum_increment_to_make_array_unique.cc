class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());

    int ans = 0;
    int mx = -1;
    for (auto a : A) {
      if (a <= mx) {
        ans += mx + 1 - a;
        a = mx + 1;
      }

      mx = a;
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 62.47%
// Memory Usage: 12 MB, less than 100.00%

class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());
    unordered_set<int> st;

    int ans = 0;
    int mx = 0;
    for (auto a : A) {
      if (st.count(a)) {
        ans += mx + 1 - a;
        a = mx + 1;
      }

      mx = a;
      st.insert(a);
    }

    return ans;
  }
};
// Runtime: 148 ms, faster than 21.40%
// Memory Usage: 26 MB, less than 16.67%

class Solution {
 public:
  int minIncrementForUnique(vector<int>& A) {
    sort(A.begin(), A.end());
    unordered_set<int> st;

    int ans = 0;
    for (auto a : A) {
      while (st.count(a)) {
        ++ans;
        ++a;
      }

      st.insert(a);
    }

    return ans;
  }
};
// Time Limit Exceeded