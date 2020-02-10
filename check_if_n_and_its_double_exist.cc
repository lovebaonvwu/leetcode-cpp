class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> st;

    for (const auto& n : arr) {
      if (!(n & 1)) {
        if (st.count(n >> 1)) {
          return true;
        }
      }

      if (st.count(n * 2)) {
        return true;
      }

      st.insert(n);
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 9.2 MB, less than 100.00%

class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (const auto& n : arr) {
      ++mp[n];
    }

    for (const auto& n : arr) {
      if (!n) {
        if (mp[n] > 1) {
          return true;
        }
      } else if (n && mp.count(n * 2)) {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 12 ms, faster than 83.33%
// Memory Usage: 10.2 MB, less than 100.00%