class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;
    unordered_set<int> st;

    for (const auto& n : arr) {
      mp[n]++;
    }

    for (const auto& p : mp) {
      st.insert(p.second);
    }

    return mp.size() == st.size();
  }
};
// Runtime: 4 ms, faster than 74.60%
// Memory Usage: 9 MB, less than 100.00%

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    int n[2001];
    int cnt[1001];

    memset(n, -1, sizeof(n));
    memset(cnt, 0, sizeof(cnt));

    for (const auto& a : arr) {
      n[a + 1000]++;
    }

    for (const auto& v : n) {
      if (v > -1 && cnt[v]) {
        return false;
      } else if (v > -1) {
        cnt[v]++;
      }
    }

    return true;
  }
};
// Runtime: 4 ms, faster than 74.60%
// Memory Usage: 8.4 MB, less than 100.00%